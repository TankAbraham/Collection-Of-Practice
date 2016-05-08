#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

bool longerThan(const string& s, size_t sz)
{
	return s.size() > sz;
}

void bigges(vector<string> &words, vector<string>::size_type sz)
{
	auto last = partition(words.begin(), words.end(), bind(longerThan, placeholders::_1, sz));
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