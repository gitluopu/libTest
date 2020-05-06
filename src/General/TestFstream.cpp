#include"TestFstream.h"
#include<algorithm>
using namespace std;

void TestFstream::StripDuplicatedLine(const string &path)
{
	fstream fs;
	fs.open(path);
	if (!fs)
	{
		LOG_ERROR("open %s error", path.c_str());
		return ;
	}
	vector<string> vs;
	string s;
	while (getline(fs, s))
		vs.push_back(s);
	for (auto &str : vs)
		cout << str << endl;
	sort(vs.begin(), vs.end());
	auto it = unique(vs.begin(), vs.end());
	int newSize = distance(vs.begin(), it);
	if (newSize == (vs.size() - 1))
		LOG_INFO("no duplicated line");
	vs.resize(newSize);
}