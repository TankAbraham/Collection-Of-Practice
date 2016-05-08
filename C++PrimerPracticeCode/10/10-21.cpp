#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int i = 2;
	
	int arr[] = { 1, 2, 3, 4, 5 };
	for_each(arr, end(arr), 
		[i](const int a) mutable -> bool
		{
			if (i != 0)
			{
				i--;
				cout << a << endl;
				return true;
			}
			else
				return false;
		});
	
	return 0;
}