#include <iostream>
#include "Sales_item.h"
#include <vector>
#include <algorithm>

using namespace std;

void print(Sales_item* item)
{
	cout << *item << endl; 
}


int main()
{
	vector<Sales_item*> arr;
	while(1)
	{
		Sales_item* item  = new Sales_item;
		while(cin >> *item)
		{
			arr.push_back(item);
		}
		for_each(arr.begin(), arr.end(), print);
	}
	return 0;
}