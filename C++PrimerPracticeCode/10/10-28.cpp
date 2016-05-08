#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <forward_list>
#include <iterator>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {

	vector<int> v(10);
	list<int> l1{-1, -2};
	deque<int> d2;
	forward_list<int> fl3;

	iota(v.begin(), v.end(), 0);

	for_each(v.cbegin(), v.cend(), [](const int n) {cout << n << " "; });
	cout << endl;

	copy(v.cbegin(), v.cend(), inserter(l1, l1.begin()));
	copy(v.cbegin(), v.cend(), back_inserter(d2));
	copy(v.cbegin(), v.cend(), front_inserter(fl3));
	
	for_each(l1.cbegin(), l1.cend(), [](const int n) {cout << n << " "; });
	cout << endl;
	for_each(d2.cbegin(), d2.cend(), [](const int n) {cout << n << " "; });
	cout << endl;
	for_each(fl3.cbegin(), fl3.cend(), [](const int n) {cout << n << " "; });

	return 0;
}
