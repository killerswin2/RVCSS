#include "GameDataCSharp.hpp"

static sqf_script_type game_data_c_sharp_type;
static std::vector<string_t> possiblePaths;
static std::vector<string_t> finalPaths;

const sqf_script_type& game_data_c_sharp::type() const
{
	return game_data_c_sharp_type;
}

serialization_return game_data_c_sharp::serialize(param_archive& ar)
{
	game_data::serialize(ar);
	return serialization_return::no_error;
}

game_data* create_game_data_c_sharp(param_archive* arch)
{
	auto data = new game_data_c_sharp;
	if (arch)
	{
		data->serialize(*arch);
	}
	return data;
}

game_value create_game_c_sharp_object(game_value_parameter className)
{
	char_t sourceMod[MAX_PATH] = { 0 };
	char_t assemblyName[MAX_PATH] = { 0 };
	char_t assemblyClassName[MAX_PATH] = { 0 };
	std::filesystem::path assemblyPath;


	// check if string
	game_data* GameDataPointer = className.data.get();
	if (className.type() == game_data_string::type_def)
	{

		intercept::sqf::config_entry config = intercept::sqf::config_file();

		std::string sourceModString = intercept::sqf::config_source_mod(config >> "rvcss" >> className);
		std::string assemblyString = intercept::sqf::get_text(config >> "rvcss" >> className >> "assemblyName");
		std::string assemblyClassString = intercept::sqf::get_text(config >> "rvcss" >> className >> "assemblyClassName");

		// error out if the strings are empty
		if (sourceModString == "" || assemblyString == "" || assemblyClassString == "")
		{
			intercept::sqf::diag_log("Bad ClassName in creation of game_c_sharp_object or empty class.");
			return {};
		}

		// convert char to char_t
#ifdef _WIN32
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, sourceModString.c_str(), -1, sourceMod, sourceModString.size());
		rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, assemblyString.c_str(), -1, assemblyName, assemblyString.size());
		rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, assemblyClassString.c_str(), -1, assemblyClassName, assemblyClassString.size());
#endif
		// find the real final path, use the first one as the right one.
		for (int i = 0; i < finalPaths.size(); i++)
		{
			if (finalPaths[i].find(sourceMod) != string_t::npos)
			{
				assemblyPath = std::filesystem::path{ finalPaths[i] };
				break;
			}
		}

		if (!std::filesystem::exists(assemblyPath))
		{
			return {};
		}

		return game_value(new game_data_c_sharp(string_t{ assemblyName }, string_t{ assemblyClassName }, assemblyPath));
		
	}
	else
	{
		return {};
	}
	
}

game_value call_cs_code(game_value_parameter csHost, game_value_parameter callingParams)
{
	if (callingParams.is_nil()|| csHost.is_nil())
	{
		return {};
	}

	if (callingParams.size() != 2)
	{
		intercept::sqf::diag_log("calling params for csCall are not the right size");
		return {};
	}

	if (callingParams[0].type() != game_data_string::type_def || callingParams[1].type() != game_data_string::type_def)
	{
		intercept::sqf::diag_log("method name or custom delegate name are not strings in csCall");
		return {};
	}

	//convert to wchar_t
	auto methodNameString = reinterpret_cast<game_data_string*>(callingParams[0].data.get());
	auto customDelegateNameString = reinterpret_cast<game_data_string*>(callingParams[1].data.get());

	

	char_t methodName[MAX_PATH] = { 0 };
	int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, methodNameString->raw_string.c_str(), -1, methodName, methodNameString->raw_string.size());

	char_t customDelegateName[MAX_PATH] = { 0 };
	rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, customDelegateNameString->raw_string.c_str(), -1, customDelegateName, customDelegateNameString->raw_string.size());

	// get the hosting object
	auto host = reinterpret_cast<game_data_c_sharp*>(csHost.data.get())->_host;

	auto function = host.get_function_pointer<void(CORECLR_DELEGATE_CALLTYPE*)(void)>(methodName, customDelegateName);
	function();
	return {};
}

void find_assembly_path(const std::filesystem::path& path, const std::vector<string_t>& nonOfficalModsDirs)
{
	for (auto const& dirEntry : std::filesystem::recursive_directory_iterator{ path })
	{
		string_t assembly{ STR("assembly") };
		if (dirEntry.is_directory())
		{
			string_t dirPath = dirEntry.path().native();
			auto pos = dirPath.find(assembly);
			if (pos == string_t::npos)
			{
				continue;
			}
			possiblePaths.push_back(dirEntry.path().native());
			//std::wcout << dirPath << STR("\n");
		}
	}
	
	for (size_t i = 0; i < nonOfficalModsDirs.size(); i++)
	{
		auto modDir = nonOfficalModsDirs[i];
		for (size_t j = 0; j < possiblePaths.size(); j++)
		{
			string_t dirPath = possiblePaths[j];
			auto pos = dirPath.find(modDir);
			if (pos == string_t::npos)
			{
				continue;
			}
			finalPaths.push_back(dirPath);
		}
	}

	// free this memory
	possiblePaths.clear();

	for (auto string : finalPaths)
	{
		std::wcout << string << STR("\n");
	}
}

void path_set_up()
{
	auto loadedMods = intercept::sqf::get_loaded_mods_info();
	std::vector<string_t> nonOfficalModsDirs;

	// filter out offical
	for (int i = 0; i < loadedMods.size(); i++)
	{
		if (!loadedMods[i].isOfficial)
		{
			char_t buffer[MAX_PATH] = { 0 };
			int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, loadedMods[i].modDir.c_str(), -1, buffer, loadedMods[i].modDir.size());
			nonOfficalModsDirs.push_back(buffer);
		}
	}


	// get the exec path on the system.
	char_t buffer[MAX_PATH] = { 0 };
	GetModuleFileNameW(NULL, buffer, MAX_PATH);
	string_t pathString = buffer;
	auto pos = pathString.find_last_of(DIR_SEPARATOR);
	if (pos == string_t::npos)
	{
		return;
	}
	pathString = pathString.substr(0, pos + 1);
	const std::filesystem::path path{pathString};
	find_assembly_path(path, nonOfficalModsDirs);
}

void rvcss::hosting::pre_start()
{
	path_set_up();
	auto codeType = intercept::client::host::register_sqf_type("CSHARP"sv, "CSharp"sv, "CSharp Hosting", "CSharp"sv, create_game_data_c_sharp);
	game_data_c_sharp_type = *codeType.second;

	Commands& commands = Commands::get();
	commands.addCommand("csLoad", "", userFunctionWrapper<create_game_c_sharp_object>, codeType.first, game_data_type::STRING);
	commands.addCommand("csCall", "", userFunctionWrapper<call_cs_code>, game_data_type::NOTHING, codeType.first, game_data_type::ARRAY);
}
