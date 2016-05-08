#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());
	auto unique_end = unique(words.begin(), words.end());
	for(auto &e : words)
		cout << e << " ";
	cout << endl;
	words.erase(unique_end, words.end());
	for (auto &e : words)
		cout << e << " ";
	cout << endl;
}

int main()
{
	ifstream fin("data1.dat");

	vector<string> v;
	string word;
	while (fin >> word)
		v.push_back(word);
	
	for (auto &e : v)
		cout << e << " ";
	cout << endl;

	elimDups(v);

	for (auto &e : v)
		cout << e << " ";
	cout << endl;

	return 0;
}