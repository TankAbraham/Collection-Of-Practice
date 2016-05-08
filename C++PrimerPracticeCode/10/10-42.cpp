#include <iostream>
#include <fstream>
#include <list>
#include <string>

using namespace std;

int main() {
	ifstream fin("data1.dat");
	list<string> l;
	string s;

	while (fin >> s)
		l.push_back(s);

	for (auto &e : l)
		cout << e << " ";
	cout << endl;

	l.sort();
	l.unique();

	for (auto &e : l)
		cout << e << " ";
	cout << endl;

	return 0;
}
