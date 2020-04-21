#ifndef LIBTEST_RPJSON_READER_H
#define LIBTEST_RPJSON_READER_H
#include<iostream>
#include<string>
#include "Common/OsExt.h"
#include "Common/DebugMsg.h"
#ifdef LIBTEST_RPJSON_EXPORTS
#define LIBTEST_RPJSON_DLL LIBTEST_DLL_EXPORT
#else
#define LIBTEST_RPJSON_DLL LIBTEST_DLL_IMPORT
#endif

class LIBTEST_RPJSON_DLL Rpjson {
public:
	int ParseFile(const std::string &path);
	int ParseStr(const std::string &str);
};
#endif