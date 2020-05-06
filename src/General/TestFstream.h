#ifndef TestFstream_H
#define TestFstream_H
#include<iostream>
#include<string>
#include<fstream>
#include "Common/OsExt.h"
#include "Common/DebugMsg.h"
#ifdef LIBTEST_GENERAL_EXPORTS
#define LIBTEST_GENERAL_DLL LIBTEST_DLL_EXPORT
#else
#define LIBTEST_GENERAL_DLL LIBTEST_DLL_IMPORT
#endif

class LIBTEST_GENERAL_DLL TestFstream {
public:
	 void StripDuplicatedLine(const std::string &path);
};
#endif
