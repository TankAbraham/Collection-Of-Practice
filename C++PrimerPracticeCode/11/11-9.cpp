#include <iostream>
#include <fstream>
#include <list>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>


using namespace std;

bool operator== (
	const pair<string, list<unsigned>>& lhs,
	const string& rhs) 
{
	if (lhs.first == rhs)
		return true;
	else
		return false;
}

void lineToVector(vector<string>& v, const string& aLine) {
	v.clear();
	string s;
	
	for (unsigned i = 0; i < aLine.size(); i++) {
		if ((aLine[i] >= 'a'  &&  aLine[i] <= 'z')
			|| (aLine[i] >= 'A'  &&  aLine[i] <= 'Z'))
		{
			s += aLine[i];
		}
		else
		{
			if(s.length() > 1)
				v.push_back(s);
			s = "";
		}
	}
}

int main() {
	ifstream fin("data9.dat");
	map < string, list<unsigned> > words;
	vector<string> wordVector;
	string s;
	unsigned line = 1;

	while (getline(fin, s)){
		lineToVector(wordVector, s);
		for (auto &word : wordVector) {
			map < string, list<unsigned> >::const_iterator it 
				= find(words.cbegin(), words.cend(), 
					[word](const pair<string, list<unsigned>> lhs)
			{
				if (lhs.first == word)
					return true;
				else
					return false;
			});
			if( it == words.cend())
				words[word].push_back(line);
		}
		line++;
	}


	for (auto &e : words) {
		cout << e.first << endl;
		for (auto &l : e.second) {
			cout << l << " ";
		}
		cout << endl;
	}
	return 0;
}