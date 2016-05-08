#include <set>
#include <vector>
#include <utility>
#include <iterator>
#include <string>
#include <iostream>
#include <algorithm>


using namespace std;

int main() {
	multiset<string> c = {"a", "b"};
	vector<string> v = {"A", "B"};

	//copy(v.begin(), v.end(), inserter(c, c.end()));  // ok
	//copy(v.begin(), v.end(), back_inserter(c));	// compiler error
	//copy(c.begin(), c.end(), inserter(v, v.end()));	// ok
	//copy(c.begin(), c.end(), back_inserter(v));	// ok

	return 0;
}