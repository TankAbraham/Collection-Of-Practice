#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {

	vector<int> v(10);
	iota(v.begin(), v.end(), 0);
	vector<int>::reverse_iterator rit = v.rbegin();
	while (rit != v.rend())
		cout << *rit++ << " ";

	return 0;
}
