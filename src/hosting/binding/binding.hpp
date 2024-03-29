#ifndef _BINDING_H
#define _BINDING_H

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
#include "../error_handling/errormessing.hpp"

using string_t = std::basic_string<char_t>;

class Bindings
{
private:
    string_t _assemblyName;

    // used for custom delegate types
    string_t _assemblyStaticClassName;

    std::filesystem::path _assemblyPath;
    std::function<int(
        const char_t* assembly_path,
        const char_t* type_name,
        const char_t* method_name,
        const char_t* delegate_type_name,
        void* reserved,
        void** delegate
        )> _load_assembly_and_get_function_pointer;

public:
    Bindings() {}
    Bindings(string_t& assemblyName, string_t assemblyStaticClassName, std::filesystem::path& assemblyPath, load_assembly_and_get_function_pointer_fn functionPointer);
    template<typename t1>
    t1 get_function_pointer_from_assembly(const string_t& methodName, const string_t& customDelegate, const string_t& assemblyClassName, const string_t& namespaceName);
};

//@TODO: make this cached.
template<typename t1>
t1 Bindings::get_function_pointer_from_assembly(const string_t& methodName, const string_t& customDelegate, const string_t& assemblyClassName, const string_t& namespaceName)
{
    string_t assemblyStaticClassName = assemblyClassName;
    if (assemblyStaticClassName == string_t())
    {
        assemblyStaticClassName = _assemblyStaticClassName;
    }
    const string_t dotnetType = namespaceName + STR(".") + assemblyStaticClassName + STR(", ") + _assemblyName;
    //std::wcout << dotnetType << STR("\n");
    const string_t delegateTypeName = namespaceName + STR(".") + assemblyStaticClassName + STR("+") + customDelegate + STR(", ") + _assemblyName;
    //std::wcout << delegateTypeName << STR("\n");

    t1 custom = nullptr;
    int rc = _load_assembly_and_get_function_pointer(
        _assemblyPath.c_str(),
        dotnetType.c_str(),
        methodName.c_str(), /*method_name*/
        delegateTypeName.c_str(),  /*delegate_type_name*/
        nullptr,
        (void**)&custom
    );

    if (rc != 0)
    {
        ErrorDescription(rc);
        std::cout << "Error code: " << rc << "\n";
    }
    assert(rc == 0 && custom != nullptr && "Failure: load_assembly_and_get_function_pointer()");
    return custom;
}

#endif