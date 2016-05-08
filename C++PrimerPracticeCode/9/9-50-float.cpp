#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <random>

using namespace std;

int main() {
	ifstream fin("data6.dat");
	vector<string> v;
	string s;
	float sum = 0;

	while (fin >> s)
		v.push_back(s);

	for_each(v.cbegin(), v.cend(),
		[&sum](const string &s) mutable { sum += stof(s); });

	cout << sum;

	return 0;
}
