#ifndef _ERRORMESSING_H
#define _ERRORMESSING_H


#include "error_codes.h"
#include <string>
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#include <Winerror.h>
#define STR(s) L ## s
#define CH(c) L ## c
#define DIR_SEPARATOR L'\\'
typedef wchar_t char_t;
using string_t = std::basic_string<char_t>;
#else
typedef long HRESULT
#define STR(s) s
#define CH(c) c
#define DIR_SEPARATOR '/'
#define MAX_PATH PATH_MAX
#endif

void ErrorDescription(HRESULT hr);
bool ErrorHosting(HRESULT hr);

#endif