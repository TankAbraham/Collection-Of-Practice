#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <utility>

using namespace std;

struct value {
	map<string, set<unsigned int>> words;
	map<unsigned int, string> lines;
};

struct value* parseInputFile(const string fileName) {
	ifstream ifile(fileName);
	string line;
	string word;
	unsigned int lineNum= 0;
	
	struct value *val = new value();

	while (getline(ifile,line)) {
		lineNum++;

		val->lines[lineNum] = line;

		istringstream iss(line);
		while (iss >> word) {
			val->words[word].insert(lineNum);
		}
	}

	return val;
}

bool findWordInLine(const struct value *val, const string word) {
	map<string, set<unsigned int>>::const_iterator it = val->words.find(word);
	
	if (it == val->words.cend()) {
		return false;
	}

	set<unsigned int> s = it->second;

	for (unsigned int e : s) {
		cout << val->lines.find(e)->second << endl;
	}

	return true;
}

int main() {
	struct value *val = parseInputFile("article.txt");

	string word;

	while (cin >> word){
		bool wasFound = findWordInLine(val, word);

		if (wasFound == false) {
			cout << "sorry to not found!" << endl;
		}
	}

	return 0;
}