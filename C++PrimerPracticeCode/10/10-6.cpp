#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	vector<int> v;
	fill_n(back_inserter(v), 5, 0);
	for_each(v.begin(), v.end(), [](const int a) {cout << a << " "; });
	return 0;
}