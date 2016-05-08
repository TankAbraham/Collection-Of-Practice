#include <map>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream fin("data9.dat");
	const string symbols = ".,\"";

	map<string, unsigned> m;

	string s;
	string::size_type pos;
	while (fin >> s){
		for (unsigned i = 0; i < symbols.length(); i++) {
			while ((pos = s.find(symbols[i])) != string::npos) {
				s.erase(pos, 1);
			}
		}

		for (unsigned i = 0; i < s.length(); i++) 
			s[i] = tolower(s[i]);

		++m[s];
	}

	for (auto &e : m)
		cout << e.first << " " << e.second << endl;

	return 0;
}
