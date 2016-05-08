#include <iostream>
#include <list>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
	vector<int> v(10);
	iota(v.begin(), v.end(), 0);
	
	vector<int>::const_reverse_iterator it3 = find(v.crbegin(), v.crend(), 3);
	vector<int>::const_reverse_iterator it7 = find(v.crbegin(), v.crend(), 7);

	//方法一
	list<int> l(it7, ++it3);
	for (auto e : l)
		cout << e << " ";
	cout << endl;


	//方法二
	list<int> l2;
	copy(it7, it3, back_inserter(l2));
	for (auto e : l2)
		cout << e << " ";

	return 0;
}
