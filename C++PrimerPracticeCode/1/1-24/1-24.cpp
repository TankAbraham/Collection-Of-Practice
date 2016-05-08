#include "Sales_item.h"
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	ifstream fin("data2.dat");
	map<string, int> m;
	Sales_item item;
	while (fin >> item)
	{
		auto ret = m.insert({ item.isbn(), 1});
		if (!ret.second)
		{
			/*
			 第一种表达方法，正确，但是注释掉
			*/
			 //m[item.isbn()] += 1; 

			/*
			 第二种表达方式，正确，更符合C++11标准。详见 <<c++ primer 5th>> p385
			*/
			ret.first->second += 1;
		}
	}	

	for_each(m.cbegin(), m.cend(), [](const pair<string, int>& book) {cout << book.first << " " << book.second << endl; });

	return 0;
}