#include <list>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	ifstream fin("data1.dat");

	list<string> l;
	string s;
	while (fin >> s)
		l.push_back(s);

	list<string>::const_iterator it1 = l.cbegin();
	list<string>::const_iterator it2 = l.cend();

	while (it1 != it2)
		cout << *it1++ << " ";
	return 0;
}