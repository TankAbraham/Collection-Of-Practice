#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	/*
	 * ÖØÐ´ 1-9
	 */
	int sum = 0;
	for (int i = 50; i <= 100; i++)
		sum += i;
	cout << sum << endl;

	/*
	* ÖØÐ´ 1-10
	*/
	for (int i = 11; i != 0; )
		cout << --i << " ";
	cout << endl;

	/*
	* ÖØÐ´ 1-11
	*/
	for (int i, j; cin >> i >> j; )
	{
		int maximum = max(i, j);
		int minimum = min(i, j);
		for (; minimum != maximum; minimum++)
			cout << minimum << " ";
		cout << maximum << endl;
	}

	return 0;
}