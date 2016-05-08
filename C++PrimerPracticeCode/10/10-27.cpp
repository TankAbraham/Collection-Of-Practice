#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
	ifstream fin("data3.dat");
	
	vector<int> v;
	list<int> l;

	int num;
	while ( fin >> num )
		v.push_back(num);

	for_each(v.cbegin(), v.cend(), [](const int n) {cout << n << " "; });
	cout << endl;

	unique_copy(v.cbegin(), v.cend(), back_inserter(l));
	
	for_each(l.cbegin(), l.cend(), [](const int n) {cout << n << " "; });

	return 0;
}
