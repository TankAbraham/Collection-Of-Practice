#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
	ifstream fin("data3.dat");
	vector<string> v;
	string s;
	int sum = 0;

	while (fin >> s)
		v.push_back(s);

	for_each(v.cbegin(), v.cend(),
		[&sum](const string &s) mutable { sum += stoi(s); });

	cout << sum;

	return 0;
}