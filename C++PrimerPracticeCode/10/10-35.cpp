#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {

	vector<int> v(10);
	iota(v.begin(), v.end(), 0);
	vector<int>::iterator it = v.end();
	while (it != v.cbegin())
		cout << *(--it) << " ";

	return 0;
}
