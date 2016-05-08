#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>


using namespace std;

int main() {
	ifstream fin("data11.dat");
	vector<pair<string, int>> v;

	string s;
	int i;

	while (fin >> s >> i)
		v.push_back(make_pair(s, i));

	for (auto &e : v)
		cout << e.first << " " << e.second << endl;

	return 0;
}