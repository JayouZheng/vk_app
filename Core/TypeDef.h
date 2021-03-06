﻿/*********************************************************************
 *  TypeDef.h
 *  Copyright (C) 2020 Jayou. All Rights Reserved.
 * 
 *  A set of custom define macros and types.
 *********************************************************************/

#pragma once

#include <cassert>
#include <cstring>
#include <cstdio>
#include <cstdlib>

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <unordered_map>
#include <memory>
#include <algorithm>

#define _assert(x) assert(x)

// Size of a static C-style array. Don't use on pointers!
#define _array_size(x) ((int)(sizeof(x) / sizeof(*x)))

#define _is_cstr_equal(str1, str2) !std::strcmp(str1, str2)

#define _is_cstrlen_equal(str1, str2) std::strlen(str1) == std::strlen(str2)

#define _lambda_is_cstr_equal [&](const char* a, const char* b) { return _is_cstr_equal(a, b); }

#define _lambda_is_equal(type) [&](const type& a, const type& b) { return a == b; }


#define _cmd_print_line(str) std::cout << str << std::endl
#define _cmd_print_line_ws(str) std::wcout << str << std::endl


#define _reinterpret_data(dst, source) { auto data = source; std::memcpy(&dst, &data, sizeof dst); }

// None Zero new.
#define _safe_new(type, num) num != 0u ? new type[num] : nullptr;

// Safe delete.
#define _safe_delete(ptr) if (ptr != nullptr) { delete ptr; ptr = nullptr; }
#define _safe_delete_array(ptr) if (ptr != nullptr) { delete[] ptr; ptr = nullptr; }


#define _w_text(x)    L#x
#define _u8_text(x)   u8#x
#define _u16_text(x)  u#x
#define _u32_text(x)  U#x


#define _name_of(x)   #x
#define _wname_of(x)  _w_text(x)

#define _str_name_of(x) string(_name_of(x))

#define _nullptr (void*)0


#define _index_0           0
#define _count_0           0
#define _count_1           1
#define _offset_0          0
#define _offset_start      0
#define _flag_none         0
#define _max_path          260

#define _uuid_size         16

#define _false             0
#define _true              1

#define _str_null          "NULL"
#define _wstr_null         _w_text("NULL")

#define _str_unknown       "Unknown"

#define _numeric_max(type) std::numeric_limits<type>::max()

#define _zero_memory_struct(obj) std::memset(&obj, 0, sizeof(obj))
#define _zero_memory(ptr, size) std::memset(ptr, 0, size)

#define _is_valid(ptr) (ptr != nullptr)


#include "Core/Base/BaseType.h"

// Function Ptr Table.
typedef void(__cdecl *PFVOID)    (void);
typedef void(__cdecl *PFVOIDVOID)(void);
typedef int (__cdecl *PFINTVOID) (void);


enum EInitFlag
{
	IF_Init,
	IF_Zero
};