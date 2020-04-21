#ifndef LIBTEST_ACE_TIME_H
#define LIBTEST_ACE_TIME_H
#include<iostream>
#include<string>
#include "Common/OsExt.h"
#include "Common/DebugMsg.h"
#ifdef LIBTEST_ACE_EXPORTS
#define LIBTEST_ACE_DLL LIBTEST_DLL_EXPORT
#else
#define LIBTEST_ACE_DLL LIBTEST_DLL_IMPORT
#endif

class LIBTEST_ACE_DLL AceTime {
public:
	std::string TimeStampMs(); //返回以ms为单位的时间戳
};
#endif