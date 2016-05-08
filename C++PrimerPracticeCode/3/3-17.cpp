#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ifstream fin("data1.dat");
	vector<string> words;
	string word;

	while (fin >> word)
		words.push_back(word);

	for_each(words.begin(), words.end(),
		[](string &word)
		{
			for (char &c : word)
				c = toupper(c);
		});

	for (auto &w : words)
		cout << w << endl;

	return 0;
}