#include"Rpjson.h"
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/writer.h"
#include<fstream>
#include<sstream>
using namespace std;
using namespace rapidjson;

int  Rpjson::ParseFile(const std::string & path)
{
	ifstream ifs;
	ifs.open(path);
	if (!ifs)
	{
		LOG_ERROR("open file %s error", path.c_str());
		return -1;
	}
	ostringstream oss;
	oss << ifs.rdbuf();
	string str = oss.str();
	
	return ParseStr(str);
}
int  Rpjson::ParseStr(const string &str)
{
	Document doc;
	doc.Parse(str.c_str());
	if (doc.HasParseError())
	{
		LOG_ERROR("json parse %s error", str.c_str());
		return -1;
	}
	return 0;
}