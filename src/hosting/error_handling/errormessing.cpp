#include "errormessing.hpp"

#pragma push_macro("min")
#pragma push_macro("max")
#undef min
#undef max

#include <intercept.hpp>


namespace sqf = intercept::sqf;

void ErrorDescription(HRESULT hr)
{
	ErrorHosting(hr);
	HRESULT copyHr = hr;
	if (FACILITY_WINDOWS == HRESULT_FACILITY(hr))
	{
		copyHr = HRESULT_CODE(hr);
	}
	char_t* buffer;

	if (FormatMessageW( FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, copyHr, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), buffer, 0, NULL) != 0)
	{
		char bufferNonWide[1024] = { 0 };
		string_t message = string_t{ buffer };

		WideCharToMultiByte(CP_UTF8, WC_NO_BEST_FIT_CHARS, message.c_str(), -1, bufferNonWide, message.size(), NULL, NULL);

		sqf::diag_log(bufferNonWide);
		LocalFree(buffer);
	}
}


bool ErrorHosting (HRESULT hr)
{
	switch (hr)
	{

	case StatusCode::Success:
	{
		sqf::diag_log("Operation was successful.");
		break;
	}

	case StatusCode::Success_HostAlreadyInitialized:
	{
		sqf::diag_log("Initialization was successful, but another host context is already initialized, so the returned context is \"secondary\". The requested context was otherwise fully compatible with the already initialized context. This is returned by hostfxr_initialize_for_runtime_config if it's called when the host is already initialized in the process. Comes from corehost_initialize in hostpolicy.");
		break;
	}

	case StatusCode::Success_DifferentRuntimeProperties:
	{
		sqf::diag_log("Initialization was successful, but another host context is already initialized and the requested context specified some runtime properties which are not the same(either in value or in presence) to the already initialized context.This is returned by hostfxr_initialize_for_runtime_config if it's called when the host is already initialized in the process. Comes from corehost_initialize in hostpolicy.");
		break;
	}

	//failure codes
	case StatusCode::InvalidArgFailure:
	{
		sqf::diag_log("One of the specified arguments for the operation is invalid.");
		break;
	}

	case StatusCode::CoreHostLibLoadFailure:
	{
		sqf::diag_log("There was a failure loading a dependent library. If any of the hosting components calls LoadLibrary/dlopen on a dependent library and the call fails, this error code is returned. The most common case for this failure is if the dependent library is missing some of its dependencies (for example the necessary CRT is missing on the machine), likely corrupt or incomplete install. This error code is also returned from corehost_resolve_component_dependencies if it's called on a hostpolicy which has not been initialized via the hosting layer. This would typically happen if coreclr is loaded directly without the hosting layer and then AssemblyDependencyResolver is used (which is an unsupported scenario).");
		break;
	}

	case StatusCode::CoreHostLibMissingFailure:
	{
		sqf::diag_log("One of the dependent libraries is missing. Typically when the hostfxr, hostpolicy or coreclr dynamic libraries are not present in the expected locations. Probably means corrupted or incomplete installation.");
		break;
	}

	case StatusCode::CoreHostEntryPointFailure:
	{
		sqf::diag_log("One of the dependent libraries is missing a required entry point.");
		break;
	}

	case StatusCode::CoreHostCurHostFindFailure:
	{
		sqf::diag_log("If the hosting component is trying to use the path to the current module (the hosting component itself) and from it deduce the location of the installation. Either the location of the current module could not be determined (some weird OS call failure) or the location is not in the right place relative to other expected components. For example the hostfxr may look at its location and try to deduce the location of the shared folder with the framework from it. It assumes the typical install layout on disk. If this doesn't work, this error will be returned.");
		break;
	}

	case StatusCode::CoreClrResolveFailure:
	{
		sqf::diag_log("If the coreclr library could not be found. The hosting layer (hostpolicy) looks for coreclr library either next to the app itself (for self-contained) or in the root framework (for framework-dependent). This search can be done purely by looking at disk or more commonly by looking into the respective .deps.json. If the coreclr library is missing in .deps.json or it's there but doesn't exist on disk, this error is returned.");
		break;
	}

	case StatusCode::CoreClrBindFailure:
	{
		sqf::diag_log("The loaded coreclr library doesn't have one of the required entry points.");
		break;
	}

	case StatusCode::CoreClrInitFailure:
	{
		sqf::diag_log("The call to coreclr_initialize failed. The actual error returned by coreclr is reported in the error message.");
		break;
	}

	case StatusCode::CoreClrExeFailure:
	{
		sqf::diag_log("The call to coreclr_execute_assembly failed. Note that this does not mean anything about the app's exit code, this failure occurs if coreclr failed to run the app itself.");
		break;
	}

	case StatusCode::ResolverInitFailure:
	{
		sqf::diag_log("Initialization of the hostpolicy dependency resolver failed. This can be: 1) One of the frameworks or the app is missing a required.deps.json file. 2) One of the.deps.json files is invalid(invalid JSON, or missing required properties and so on).");
		break;
	}

	case StatusCode::ResolverResolveFailure:
	{
		sqf::diag_log("Resolution of dependencies in hostpolicy failed. This can mean many different things, but in general one of the processed .deps.json contains entry for a file which could not found, or its resolution failed for some other reason (conflict for example).");
		break;
	}

	case StatusCode::LibHostCurExeFindFailure:
	{
		sqf::diag_log("Failure to determine the location of the current executable. The hosting layer uses the current executable path to deduce the install location in some cases. If this path can't be obtained (OS call fails, or the returned path doesn't exist), this error is returned.");
		break;
	}

	case StatusCode::LibHostInitFailure:
	{
		sqf::diag_log("Initialization of the hostpolicy library failed. The corehost_load method takes a structure with lot of initialization parameters. If the version of this structure doesn't match the expected value, this error code is returned. This would in general mean incompatibility between the hostfxr and hostpolicy, which should really only happen if somehow a newer hostpolicy is used by older hostfxr. This typically means corrupted installation.");
		break;
	}

	case StatusCode::LibHostExecModeFailure:
	{
		sqf::diag_log("Not used.");
		break;
	}

	case StatusCode::LibHostSdkFindFailure:
	{
		sqf::diag_log("Failure to find the requested SDK. This happens in the hostfxr when an SDK (also called CLI) command is used with dotnet. In this case the hosting layer tries to find an installed .NET SDK to run the command on. The search is based on deduced install location and on the requested version from potential global.json file. If either no matching SDK version can be found, or that version exists, but it's missing the dotnet.dll file, this error code is returned.");
		break;
	}

	case StatusCode::LibHostInvalidArgs:
	{
		sqf::diag_log("Arguments to hostpolicy are invalid. This is used in three unrelated places in the hostpolicy, but in all cases it means the component calling hostpolicy did something wrong: 1) Command line arguments for the app - the failure would typically mean that wrong argument was passed or such.For example if the application main assembly is not specified on the command line.On its own this should not happen as hostfxr should have parsed and validated all command line arguments. 2) hostpolicy context's get_delegate - if the requested delegate enum value is not recognized. Again this would mean hostfxr passed the wrong value. 3) corehost_resolve_component_dependencies - if something went wrong initializing hostpolicy internal structures.Would happen for example when the component_main_assembly_path argument is wrong. ");
		break;
	}

	case StatusCode::InvalidConfigFile:
	{
		sqf::diag_log("The .runtimeconfig.json file is invalid. The reasons for this failure can be among these: 1) Failure to read from the file 2) Invalid JSON 3) Invalid value for a property(for example number for property which requires a string) 4) Missing required property ) Other inconsistencies(for example rollForward and applyPatches are not allowed to be specified in the same config file) 6) Any of the above failures reading the.runtimecofig.dev.json file 7) Self - contained.runtimeconfig.json used in hostfxr_initialize_for_runtime_config.Note that missing.runtimconfig.json is not an error(means self - contained app).This error code is also used when there is a problem reading the CLSID map file in comhost. ");
		break;
	}

	case StatusCode::AppArgNotRunnable:
	{
		sqf::diag_log("Used internally when the command line for dotnet.exe doesn't contain path to the application to run. In such case the command line is considered to be a CLI/SDK command. This error code should never be returned to external caller.");
		break;
	}

	case StatusCode::AppHostExeNotBoundFailure:
	{
		sqf::diag_log("apphost failed to determine which application to run. This can mean: 1) The apphost binary has not been imprinted with the path to the app to run(so freshly built apphost.exe from the branch will fail to run like this) 2) The apphost is a bundle(single - file exe) and it failed to extract correctly. ");
		break;
	}

	case StatusCode::FrameworkMissingFailure:
	{
		sqf::diag_log("It was not possible to find a compatible framework version. This originates in hostfxr (resolve_framework_reference) and means that the app specified a reference to a framework in its .runtimeconfig.json which could not be resolved. The failure to resolve can mean that no such framework is available on the disk, or that the available frameworks don't match the minimum version specified or that the roll forward options specified excluded all available frameworks. Typically this would be used if a 3.0 app is trying to run on a machine which has no 3.0 installed. It would also be used for example if a 32bit 3.0 app is running on a machine which has 3.0 installed but only for 64bit.");
		break;
	}

	case StatusCode::HostApiFailed:
	{
		sqf::diag_log("Returned by hostfxr_get_native_search_directories if the hostpolicy could not calculate the NATIVE_DLL_SEARCH_DIRECTORIES.");
		break;
	}

	case StatusCode::HostApiBufferTooSmall:
	{
		sqf::diag_log("Returned when the buffer specified to an API is not big enough to fit the requested value. Can be returned from: 1)hostfxr_get_runtime_properties 2)hostfxr_get_native_search_directories 3)get_hostfxr_path ");
		break;
	}

	case StatusCode::LibHostUnknownCommand:
	{
		sqf::diag_log("Returned by hostpolicy if the corehost_main_with_output_buffer is called with unsupported host command. This error code means there is incompatibility between the hostfxr and hostpolicy. In reality this should pretty much never happen.");
		break;
	}

	case StatusCode::LibHostAppRootFindFailure:
	{
		sqf::diag_log("Returned by apphost if the imprinted application path doesn't exist. This would happen if the app is built with an executable (the apphost) and the main app.dll is missing.");
		break;
	}

	case StatusCode::SdkResolverResolveFailure:
	{
		sqf::diag_log("Returned from hostfxr_resolve_sdk2 when it fails to find matching SDK. Similar to LibHostSdkFindFailure but only used in the hostfxr_resolve_sdk2.");
		break;
	}

	case StatusCode::FrameworkCompatFailure:
	{
		sqf::diag_log("During processing of .runtimeconfig.json there were two framework references to the same framework which were not compatible. This can happen if the app specified a framework reference to a lower-level framework which is also specified by a higher-level framework which is also used by the app. For example, this would happen if the app referenced Microsoft.AspNet.App version 2.0 and Microsoft.NETCore.App version 3.0. In such case the Microsoft.AspNet.App has .runtimeconfig.json which also references Microsoft.NETCore.App but it only allows versions 2.0 up to 2.9 (via roll forward options). So the version 3.0 requested by the app is incompatible.");
		break;
	}

	case StatusCode::FrameworkCompatRetry:
	{
		sqf::diag_log("Error used internally if the processing of framework references from .runtimeconfig.json reached a point where it needs to reprocess another already processed framework reference. If this error is returned to the external caller, it would mean there's a bug in the framework resolution algorithm.");
		break;
	}

	case StatusCode::BundleExtractionFailure:
	{
		sqf::diag_log("Error extracting single-file apphost bundle. This is used in case of any error related to the bundle itself. Typically would mean a corrupted bundle.");
		break;
	}

	case StatusCode::BundleExtractionIOError:
	{
		sqf::diag_log("Error reading or writing files during single-file apphost bundle extraction.");
		break;
	}

	case StatusCode::LibHostDuplicateProperty:
	{
		sqf::diag_log("The .runtimeconfig.json specified by the app contains a runtime property which is also produced by the hosting layer. For example if the .runtimeconfig.json would specify a property TRUSTED_PLATFORM_ROOTS, this error code would be returned. It is not allowed to specify properties which are otherwise populated by the hosting layer (hostpolicy) as there is not good way to resolve such conflicts.");
		break;
	}

	case StatusCode::HostApiUnsupportedVersion:
	{
		sqf::diag_log("Feature which requires certain version of the hosting layer binaries was used on a version which doesn't support it. For example if COM component specified to run on 2.0 Microsoft.NETCore.App - as that contains older version of hostpolicy which doesn't support the necessary features to provide COM services.");
		break;
	}

	case StatusCode::HostInvalidState:
	{
		sqf::diag_log("Error code returned by the hosting APIs in hostfxr if the current state is incompatible with the requested operation. There are many such cases, please refer to the documentation of the hosting APIs for details. For example if hostfxr_get_runtime_property_value is called with the host_context_handle nullptr (meaning get property from the active runtime) but there's no active runtime in the process.");
		break;
	}

	case StatusCode::HostPropertyNotFound:
	{
		sqf::diag_log("property requested by hostfxr_get_runtime_property_value doesn't exist.");
		break;
	}

	case StatusCode::CoreHostIncompatibleConfig:
	{
		sqf::diag_log("Error returned by hostfxr_initialize_for_runtime_config if the component being initialized requires framework which is not available or incompatible with the frameworks loaded by the runtime already in the process. For example trying to load a component which requires 3.0 into a process which is already running a 2.0 runtime.");
		break;
	}

	case StatusCode::HostApiUnsupportedScenario:
	{
		sqf::diag_log("Error returned by hostfxr_get_runtime_delegate when hostfxr doesn't currently support requesting the given delegate type using the given context.");
		break;
	}

	case StatusCode::HostFeatureDisabled:
	{
		sqf::diag_log("Error returned by hostfxr_get_runtime_delegate when managed feature support for native host is disabled.");
		break;
	}
	default:
	{
		sqf::diag_log("Default called in error messaging. Unknown Error.");
	}
	}
	return true;
}