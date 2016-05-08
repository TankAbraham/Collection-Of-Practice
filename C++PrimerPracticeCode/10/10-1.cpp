#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 6, 6, 6, 7, 8, 9, 10 };
	vector<int> v(begin(arr), end(arr));
	cout << count(v.begin(), v.end(), 6);
	return 0;
}