#include <iostream>
#include <algorithm>
#include <list>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	fstream f("data.dat");
	string s;
	list<string> l;

	while (f >> s)
		l.push_back(s);

	cout << count(l.begin(), l.end(), "fox");
	return 0;
}