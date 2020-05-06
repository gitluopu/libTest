#include <iostream>
#include "Rpjson/Rpjson.h"
#include "AceWrap/Time.h"
#include "General/TestFstream.h"
using namespace std;
#define  PATH "C:\\Users\\95163\\Desktop\\test.json"

int main(int argc, char *argv[])
{
	TestFstream tf;
	tf.StripDuplicatedLine(PATH);
#ifdef _WIN32
	system("pause");
#endif
	return 0;
}