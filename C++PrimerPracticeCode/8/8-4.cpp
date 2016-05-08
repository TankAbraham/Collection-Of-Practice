#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() 
{
	ifstream ifile("data16.dat");
	vector<string> v;
	string s;

	while (getline(ifile, s))
		v.push_back(s);

	for (auto e : v)
		cout << e << endl;

	return 0;
}