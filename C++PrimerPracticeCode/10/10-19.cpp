#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void bigges(vector<string> &words, vector<string>::size_type sz)
{
	auto last = stable_partition(words.begin(), words.end(), 
		[sz](const string& s) -> bool
			{
				return s.size() > sz;
			});
	for_each(words.begin(), last, [](const string& s) {cout << s << " "; });
}

int main()
{
	ifstream fin("data1.dat");

	vector<string> words;
	string word;
	while (fin >> word)
		words.push_back(word);
	
	bigges(words, 4);

	return 0;
}