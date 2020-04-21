#include <iostream>
#include "Rpjson/Rpjson.h"
#include "AceWrap/Time.h"
using namespace std;
#define  PATH "C:\\Users\\95163\\Desktop\\test.json"
int main(int argc, char *argv[])
{
	AceTime at;
	LOG_INFO("%s\n",at.TimeStampMs().c_str());
	system("pause");
	return 0;
}