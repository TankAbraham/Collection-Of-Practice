#include "Sales_data.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>

using namespace std;

struct SalesItemAdd
{
	Sales_item& operator() (const Sales_item& lhs, const Sales_item& rhs)
	{
		return lhs + rhs;
	}
};

int main()
{
	ifstream fin("data2.dat");
	vector<Sales_item> v;
	Sales_item item;
	while (fin >> item)
		v.push_back(item);

	cout << accumulate(v.cbegin(), v.cend(), *v.begin(),
				[](const Sales_item& lhs, const Sales_item& rhs)
					{ return lhs + rhs;}) << endl;
	cout << accumulate(v.cbegin(), v.cend(), *v.begin(), SalesItemAdd()) << endl;
	cout << accumulate(v.begin(), v.end(), *v.begin()) << endl;

	return 0;
}

/*
�����ʽ��
	5 110 22

bug1:
	û��isbn��
ԭ��
	accumulate�ĵ��������������Ϊ�գ���������ֵ����Ϊ�Ӻŵ����غ�������bookNo���и�ֵ��
	���Ե��� item + ... �����bookNoΪ�ա�
���������
	��accumulate������������Ϊvector��begin()��������ӽ����ò��� *v.begin() ;

bug2:
	accumulate�ĵڶ������û�������ش���
*/