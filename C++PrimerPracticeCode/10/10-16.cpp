#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

void biggies(vector<string>& words, const vector<string>::size_type sz)
{
	auto beg = words.begin();
	while (beg != words.end())
	{
		auto temp = find_if(beg, words.end(), 
						[sz](const string& s)
							{ return s.size() > sz; });
		cout << *temp << " ";
		beg = ++temp;
	}
	cout << endl;
}

int main()
{
	fstream fin("data.dat");
	if (!fin)
	{
		cerr << "data.dat 文件打开错误" << endl;
		return -1;
	}
	vector<string> v;
	string str;
	while (fin >> str)
		v.push_back(str);

	biggies(v, 1);

	for_each(v.begin(), v.end(),
		[](const auto it) {cout << it << " "; });

	return 0;
}