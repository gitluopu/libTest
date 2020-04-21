#ifndef _LIBTEST_DEBUGMSG_H
#define _LIBTEST_DEBUGMSG_H
#include<stdio.h>
#define LOG_ERROR(...) printf(__VA_ARGS__);printf("\n");
#define LOG_DEBUG(...) printf(__VA_ARGS__);printf("\n");
#define LOG_INFO(...) printf(__VA_ARGS__);printf("\n");
#endif