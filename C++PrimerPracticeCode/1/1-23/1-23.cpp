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
			 ��һ�ֱ�﷽������ȷ������ע�͵�
			*/
			 //m[item.isbn()] += 1; 

			/*
			 �ڶ��ֱ�﷽ʽ����ȷ��������C++11��׼����� <<c++ primer 5th>> p385
			*/
			ret.first->second += 1;
		}
	}	

	for_each(m.cbegin(), m.cend(), [](const pair<string, int>& book) {cout << book.first << " " << book.second << endl; });

	return 0;
}