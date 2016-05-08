#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void biggesNumber(vector<string> &words, vector<string>::size_type sz = 0, ostream &os = cout, char c = ' ')
{
	auto num = count_if(words.begin(), words.end(), 
		[sz, &os](const string& s) -> bool
			{
				if (s.size() > sz)
					return true;
				else
					return false;
			});
	os << num << c;
}

int main()
{
	ifstream fin("data1.dat");

	vector<string> words;
	string word;
	while (fin >> word)
		words.push_back(word);
	
	// 统计单词长度超过 6 的个数
	biggesNumber(words, 6);

	return 0;
}