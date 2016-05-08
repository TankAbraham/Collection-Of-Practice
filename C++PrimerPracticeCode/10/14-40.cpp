#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

struct Bigger {
	bool operator() (const string& lhs, vector<string>::size_type rhs) {
		return lhs.size() > rhs;
	}
};

void biggies(vector<string>& words, const vector<string>::size_type sz)
{
	auto beg = words.begin();
	while (beg != words.end())
	{
		auto temp = 
			find_if(beg, words.end(), bind(Bigger(), placeholders::_1, sz));
		cout << *temp << " ";
		beg = ++temp;
	}
	cout << endl;
}

int main()
{
	fstream fin("data1.dat");
	if (!fin)
	{
		cerr << "data.dat 文件打开错误" << endl;
		return -1;
	}
	vector<string> v;
	string str;
	while (fin >> str)
		v.push_back(str);

	biggies(v, 5);

	for_each(v.begin(), v.end(),
		[](const auto it) {cout << it << " "; });

	return 0;
}