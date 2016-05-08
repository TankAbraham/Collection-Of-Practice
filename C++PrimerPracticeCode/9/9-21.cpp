#include <list>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	ifstream fin("data1.dat");

	list<string> l;
	string s;
	auto iter = l.begin();
	while (fin >> s)
		l.insert(iter, s);

	list<string>::const_iterator it1 = l.cbegin();
	list<string>::const_iterator it2 = l.cend();

	while (it1 != it2)
		cout << *it1++ << " ";

	fin.close();
	cout << endl;
	/********************************************/
	ifstream fin2("data1.dat");

	vector<string> v;
	auto iter2 = v.begin();
	while ( fin2 >> s)
		iter2 = v.insert(iter2, s);
	for (auto &e : v)
		cout << e << " ";
	return 0;
}