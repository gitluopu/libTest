#include"Time.h"
#include <ace/OS_NS_unistd.h>
#include <ace/OS_NS_string.h>
#include <ace/OS_NS_time.h>
#include <ace/Date_Time.h>
#include <ace/Time_Value.h>
#include "ace/OS.h"
using namespace std;
string  AceTime::TimeStampMs()
{
	ACE_Time_Value tv = ACE_OS::gettimeofday();
	ACE_UINT64 usec;
	tv.to_usec(usec);
	//直接用long型得到的值不正确，string类型会得到正确的值
	return std::to_string(ACE_OS::gettimeofday().get_msec());
}