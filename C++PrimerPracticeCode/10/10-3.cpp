#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main()
{
	vector<int> v = { 1, 2, 3, 4 };
	cout << accumulate(v.begin(), v.end(), 0);
	return 0;
}