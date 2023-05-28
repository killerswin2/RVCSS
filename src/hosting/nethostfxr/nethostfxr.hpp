#pragma once

#include <iostream>
#include <cstdlib>
#include <filesystem>
#include <cassert>

#include <nethost.h>
#include <coreclr_delegates.h>
#include <hostfxr.h>

#ifdef _WIN32
#include <windows.h>
#define STR(s) L ## s
#define CH(c) L ## c
#define DIR_SEPARATOR L'\\'

#else
#include <dlfcn.h>
#include <climits>
#define STR(s) s
#define CH(c) c
#define DIR_SEPARATOR '/'
#define MAX_PATH PATH_MAX

#endif

#include <string>
#include <filesystem>
#include <functional>
#include <type_traits>


#include "../binding/binding.hpp"
#include "../library/library.hpp"

class Nethostfxr
{
private:
    bool load_hostfxr();
    load_assembly_and_get_function_pointer_fn get_dotnet_load_assembly();

    hostfxr_initialize_for_runtime_config_fn _hostfxr_initialize_for_runtime_config;
    hostfxr_get_runtime_delegate_fn _hostfxr_get_runtime_delegate;
    hostfxr_close_fn _hostfxr_close;

    std::filesystem::path _configPath;
    string_t _assemblyName;

    Bindings _binding;


public:
    Nethostfxr() {};
    Nethostfxr(string_t& assemblyName, string_t& assemblyStaticClassName, std::filesystem::path& configPath);
    void Invoke();
    template<typename t1>
    t1 get_function_pointer(const string_t& methodName);
};

Nethostfxr::Nethostfxr(string_t& assemblyName, string_t& assemblyStaticClassName, std::filesystem::path& configPath) : _assemblyName{ assemblyName }
{
    std::filesystem::path temp = configPath;
    string_t configName = assemblyName + STR(".runtimeconfig.json");
    _configPath.clear();
    // check that the path exists
    temp.append(configName);
    if (std::filesystem::exists(temp))
    {
        _configPath = std::filesystem::canonical(temp);
        std::wcout << "Path: " << _configPath << "\n";
    }

    if (_configPath.empty())
    {
        std::cout << "Path is empty\n";
    }

    // load hostfxr and get exporting hosting funcs
    if (!load_hostfxr())
    {
        assert(false && "Failure: load_hostfxr()");
    }

    _binding = Bindings{ assemblyName, assemblyStaticClassName, configPath, get_dotnet_load_assembly() };

}

// Load and initialize .NET Core and get desired function pointer for scenario
load_assembly_and_get_function_pointer_fn Nethostfxr::get_dotnet_load_assembly()
{
    // load .Net Core
    void* load_assembly_and_get_function_pointer = nullptr;
    hostfxr_handle cxt = nullptr;
    int rc = _hostfxr_initialize_for_runtime_config(_configPath.c_str(), nullptr, &cxt);
    if (rc != 0 || cxt == nullptr)
    {
        std::cerr << "Init failed: " << std::hex << std::showbase << rc << std::endl;
        _hostfxr_close(cxt);
        return nullptr;
    }
    //get the load assembly function pointer
    rc = _hostfxr_get_runtime_delegate(
        cxt,
        hdt_load_assembly_and_get_function_pointer,
        &load_assembly_and_get_function_pointer
    );
    if (rc != 0 || load_assembly_and_get_function_pointer == nullptr)
    {
        std::cerr << "Get delegate failed: " << std::hex << std::showbase << rc << std::endl;
    }
    _hostfxr_close(cxt);

    assert(load_assembly_and_get_function_pointer != nullptr && "Failure: get_dotnet_load_assembly()");

    return reinterpret_cast<load_assembly_and_get_function_pointer_fn>(load_assembly_and_get_function_pointer);
}

// Using the nethost library, discover the location of hostfxr and get exports
bool Nethostfxr::load_hostfxr()
{
    // Pre-allocate a large buffer for the path to hostfxr
    char_t buffer[MAX_PATH];
    size_t bufferSize = sizeof(buffer) / sizeof(char_t);
    int rc = get_hostfxr_path(buffer, &bufferSize, nullptr);
    if (rc != 0)
    {
        return false;
    }
    // load hostfxr and get desired exports
    std::filesystem::path path = std::filesystem::path{ buffer };
    Library lib = Library{ path };
    lib.load_library();

    _hostfxr_initialize_for_runtime_config = lib.get_export<hostfxr_initialize_for_runtime_config_fn>("hostfxr_initialize_for_runtime_config");
    _hostfxr_get_runtime_delegate = lib.get_export<hostfxr_get_runtime_delegate_fn>("hostfxr_get_runtime_delegate");
    _hostfxr_close = lib.get_export<hostfxr_close_fn>("hostfxr_close");
    return (_hostfxr_initialize_for_runtime_config && _hostfxr_get_runtime_delegate && _hostfxr_close);
}

template<typename t1>
t1 Nethostfxr::get_function_pointer(const string_t& methodName)
{
    return _binding.get_function_pointer_from_assembly<t1>(methodName);
}