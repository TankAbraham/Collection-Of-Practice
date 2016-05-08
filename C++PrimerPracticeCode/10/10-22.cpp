#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

bool bigger(const string& s, string::size_type sz)
{
	return s.size() > sz;
}

int main()
{
	ifstream fin("data1.dat");

	vector<string> words;
	string word;
	while (fin >> word)
		words.push_back(word);

	cout << count_if(words.begin(), words.end(), bind(bigger, placeholders::_1, 6));

	return 0;
}