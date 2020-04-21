
/*!
 *	\file	OS_Ext.h
 *
 *	\brief	����ƽ̨�������ͷ�ļ�
 *
 *	����ACEû�з�װ�ĵײ�API�ڴ��ļ��н��з�װ��ͬʱ����һЩ����ƽ̨����Ĵ���
 */
#ifndef _LIBTEST_OSEXT_H__
#define _LIBTEST_OSEXT_H__

#include <string>

 //! ֻ������WIN32��û�ж���_WINDOWS
#ifdef WIN32
#ifndef _WINDOWS
#define _WINDOWS
#endif
#endif

////////////////////////////////////////////////////////////////////
//! WINDOWSר��
#ifdef _WINDOWS

//! ֧��_T�ַ�������
#include <tchar.h>

#define LIBTEST_DLL_EXPORT __declspec(dllexport)
#define LIBTEST_DLL_IMPORT __declspec(dllimport)

//! hash_map�ȱ�׼ģ���Ϊ��չ���ݣ��ڲ�ͬƽ̨��ʵ���ڲ�ͬ�����ռ���
#define STL_EXT	stdext
#include <unordered_map>

//! ��ȡȱʡini�ļ����Ŀ¼��Windows��ȱʡini�ļ������WindowsĿ¼��
#ifndef GetDefaultIniDirectory
#define GetDefaultIniDirectory GetWindowsDirectory
#endif

#define _MODULE_PREFIX ""
#define _MODULE_POSTFIX ".dll"
#define _EXE_POSTFIX ".exe"

//! longlong���͵���sprintf����ĸ�ʽ����
#define PRINT_FORMAT_LONGLONG "I64d"	//! %d == %i
#define PRINT_FORMAT_ULONGLONG "I64u"

#endif

////////////////////////////////////////////////////////////////////
//! UNIXϵ��ר��
#ifndef _WINDOWS

#define LIBTEST_DLL_EXPORT
#define LIBTEST_DLL_IMPORT

//! hash_map�ȱ�׼ģ���Ϊ��չ���ݣ��ڲ�ͬƽ̨��ʵ���ڲ�ͬ�����ռ���
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

//! longlong���͵���sprintf����ĸ�ʽ����
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
