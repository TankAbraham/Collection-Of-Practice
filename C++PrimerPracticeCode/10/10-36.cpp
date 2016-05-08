#include <iostream>
#include <list>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {

	list<int> l(10);
	iota(l.rbegin(), l.rend(), 0);
	for (auto e : l)
		cout << e << " ";
	cout << endl;

	list<int>::reverse_iterator position = find(l.rbegin(), l.rend(), 0);

	cout << *position;

	return 0;
}
