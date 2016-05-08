#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main()
{
	vector<double> v = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	cout << accumulate(v.cbegin(), v.cend(), 0) << endl;
	cout << accumulate(v.cbegin(), v.cend(), 0.0) << endl;
	return 0;
}