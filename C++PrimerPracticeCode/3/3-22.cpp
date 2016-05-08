#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

struct StrUpper{
	void operator() (string &str) {
		for (char &c : str)
			c = toupper(c);
	}
};

int main()
{
	ifstream fin("data4.dat");
	vector<string> text;
	string line;
	while (getline(fin, line))
		text.push_back(line);

	vector<string>::iterator end;
	end = find_if(text.begin(), text.end(),
		[end](const string& s){
			if (s == "")
				return true;
	});

	for_each(text.begin(), end,
		[](string &s) {
			for (char &c : s)
				c = toupper(c);
			//StrUpper(s);		
	});

	for_each(text.cbegin(), text.cend(), [](const string &s) {cout << s << endl; });

	return 0;
}