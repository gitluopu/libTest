
/*!
 *	\file	OS_Ext.h
 *
 *	\brief	屏蔽平台差异代码头文件
 *
 *	对于ACE没有封装的底层API在此文件中进行封装，同时包括一些屏蔽平台差异的代码
 */
#ifndef _LIBTEST_OSEXT_H__
#define _LIBTEST_OSEXT_H__

#include <string>

 //! 只定义了WIN32而没有定义_WINDOWS
#ifdef WIN32
#ifndef _WINDOWS
#define _WINDOWS
#endif
#endif

////////////////////////////////////////////////////////////////////
//! WINDOWS专用
#ifdef _WINDOWS

//! 支持_T字符操作宏
#include <tchar.h>

#define LIBTEST_DLL_EXPORT __declspec(dllexport)
#define LIBTEST_DLL_IMPORT __declspec(dllimport)

//! hash_map等标准模板库为扩展内容，在不同平台下实现在不同命名空间内
#define STL_EXT	stdext
#include <unordered_map>

//! 获取缺省ini文件存放目录，Windows下缺省ini文件存放在Windows目录下
#ifndef GetDefaultIniDirectory
#define GetDefaultIniDirectory GetWindowsDirectory
#endif

#define _MODULE_PREFIX ""
#define _MODULE_POSTFIX ".dll"
#define _EXE_POSTFIX ".exe"

//! longlong类型调用sprintf输出的格式定义
#define PRINT_FORMAT_LONGLONG "I64d"	//! %d == %i
#define PRINT_FORMAT_ULONGLONG "I64u"

#endif

////////////////////////////////////////////////////////////////////
//! UNIX系列专用
#ifndef _WINDOWS

#define LIBTEST_DLL_EXPORT
#define LIBTEST_DLL_IMPORT

//! hash_map等标准模板库为扩展内容，在不同平台下实现在不同命名空间内
#define STL_EXT	__gnu_cxx
#include <ext/hash_map>

#define _MAX_PATH 260
#define _MAX_DRIVE 3
#define _MAX_DIR 256
#define _MAX_EXT 256
#define _MAX_FNAME 255
#define MAX_PATH 260
#define _tcsncpy strncpy
#define _tcslen strlen
#define stricmp strcasecmp
#define _TSCHAR char
#define __int64 long long
#define TCHAR char
#define _tcschr strchr
#define _stprintf sprintf
#define _ttol atol
#define _ttoi64 atoll
#define _tcstod strtod
#define _ttoi atoi
#define _sntprintf snprintf
#define _tcstol strtol
#define _tcscmp strcmp
#define _tcscat strcat
#define _atoi64 atoll

#define __time64_t time_t
#define _time64 time
#define _localtime64 localtime

#define _I64_MIN    LONG_LONG_MIN
#define _I64_MAX    LONG_LONG_MAX
#define _UI32_MAX ULONG_MAX
#define _I32_MIN LONG_MIN

/* Minimum and maximum macros */
#define __max(a,b)  (((a) > (b)) ? (a) : (b))
#define __min(a,b)  (((a) < (b)) ? (a) : (b))

#ifndef _T
#define _T(x) x
#endif

#define _MODULE_PREFIX "lib"
#define _MODULE_POSTFIX ".so"
#define _EXE_POSTFIX ""

//! longlong类型调用sprintf输出的格式定义
#define PRINT_FORMAT_LONGLONG "lld" 
#define PRINT_FORMAT_ULONGLONG "llu"


#endif

////////////////////////////////////////////////////////////////////
#ifdef LIBTEST_COMMON_EXPORTS
#define LIBTEST_COMMON_DLL LIBTEST_DLL_EXPORT
#else
#define LIBTEST_COMMON_DLL LIBTEST_DLL_IMPORT
#endif


#endif
