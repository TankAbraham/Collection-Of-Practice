#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	ifstream ifile("data9.dat");
	
	string s, word;
	vector<string> v;
	
	while (getline(ifile, s))
		v.push_back(s);

	for (auto &e : v)
	{
		istringstream line(e);

		while (line >> word)
			cout << word << endl;
	}

	return 0;
}