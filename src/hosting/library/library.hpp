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


class Library
{
private:
    std::filesystem::path _path;
#ifdef _WIN32
    HMODULE _library;
#else
    void* _library;
#endif
public:
    Library(std::filesystem::path& libraryPath) : _path{ std::move(libraryPath) } {}
    void load_library();

#ifdef _WIN32
    template<typename t1>
    t1 get_export(const char* name)
    {
        void* f = ::GetProcAddress(reinterpret_cast<HMODULE>(_library), name);
        assert(f != nullptr);
        return reinterpret_cast<t1>(f);
    }
#else
    template<typename t1>
    t1 get_export(const char* name)
    {
        void* f = dlsym(_library, name);
        assert(f != nullptr);
        return reinterpret_cast<t1>(f);
    }
#endif
};