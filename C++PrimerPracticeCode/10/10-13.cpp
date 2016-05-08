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

int main()
{
	ifstream fin("data1.dat");
	
	vector<string> words;
	string word;
	while (fin >> word)
		words.push_back(word);

	auto last = partition(words.begin(), words.end(), bind(longerThan, placeholders::_1, 5));

	for (auto &w : words)
		cout << w << " ";
	cout << endl;

	for_each(words.begin(), last, [](const string& s) {cout << s << " "; });

	return 0;
}