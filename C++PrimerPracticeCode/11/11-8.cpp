#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>


using namespace std;

int main() {
	ifstream fin("data1.dat");
	vector<pair<string, unsigned> > words;
	string word;

	while (fin >> word){
		auto it = find_if(words.begin(), words.end(), [word](const pair<string, unsigned> wordPair){
			if (wordPair.first == word)
				return true;
			else
				return false;
		});

		if (it == words.end())
			words.push_back(make_pair(word, 1));
		else
			++(*it).second;
	}

	sort(words.begin(), words.end(), [](const pair<string, unsigned> lhs, const pair<string, unsigned> rhs) {
		if (lhs < rhs)
			return true;
		else
			return false;
	});

	for_each(words.cbegin(), words.cend(), [](const pair<string, unsigned> word) {
		cout << word.first << " " << word.second << endl;
	});

	return 0;
}