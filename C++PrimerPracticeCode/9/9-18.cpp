#include <deque>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	ifstream fin("data1.dat");

	deque<string> d;
	string s;
	while (fin >> s)
		d.push_back(s);

	deque<string>::const_iterator it1 = d.cbegin();
	deque<string>::const_iterator it2 = d.cend();

	while (it1 != it2)
		cout << *it1++ << " ";
	return 0;
}