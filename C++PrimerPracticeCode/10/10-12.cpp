#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include "Sales_data.h"

using namespace std;

bool compareIsbn(const Sales_data& lhs, const Sales_data& rhs)
{
	return lhs.isbn() < rhs.isbn();
}

int main()
{
	ifstream fin("data2.dat");

	vector<Sales_data> v;
	Sales_data book;
	while (fin >> book)
		v.push_back(book);
	
	for (auto &e : v)
		cout << e << endl;;
	
	sort(v.begin(), v.end(), compareIsbn);

	cout << "ÅÅÐòºó.................."<< endl;
	for (auto &e : v)
		cout << e << " " << endl;

	return 0;
}