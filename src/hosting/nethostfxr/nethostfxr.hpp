#ifndef _NETHOSTINGFXR_H
#define _NETHOSTINGFXR_H

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
    t1 get_function_pointer(const string_t& methodName, const string_t& customDelegate);
};

template<typename t1>
t1 Nethostfxr::get_function_pointer(const string_t& methodName, const string_t& customDelegate)
{
    return _binding.get_function_pointer_from_assembly<t1>(methodName, customDelegate);
}
#endif