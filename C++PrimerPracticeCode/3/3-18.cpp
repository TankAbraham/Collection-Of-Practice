#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	vector<int> v;
	auto it = back_inserter(v);
	it = 42;
	it = 43;
	cout << v[0] << endl;
	cout << v[1] << endl;
	return 0;
}