#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include "Sales_data.h"

using namespace std;

int main()
{
	ifstream fin("data2.dat");

	vector<Sales_data> v;
	Sales_data book;
	while (fin >> book)
		v.push_back(book);

	for (auto &e : v)
		cout << e << endl;;

	sort(v.begin(), v.end(), 
		[](const Sales_data& lhs, const Sales_data& rhs) -> bool
		{
			return lhs.isbn() < rhs.isbn();
		});

	cout << "ÅÅÐòºó.................." << endl;
	for (auto &e : v)
		cout << e << " " << endl;

	return 0;
}