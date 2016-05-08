#include "Sales_data.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>

using namespace std;

struct SalesItemAdd
{
	Sales_item operator() (const Sales_item& lhs, const Sales_item& rhs)
	{
		//Sales_item ret(lhs);
		//ret += rhs;
		//return ret;

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
输出形式：
	5 110 22

bug1:
	没有isbn号
原因：
	accumulate的第三个参数的输出为空，并且作左值。因为加号的重载函数不对bookNo进行赋值，
	所以导致 item + ... 结果的bookNo为空。
解决方法：
	将accumulate的三个参数置为vector的begin()，并且添加解引用操作 *v.begin() ;

bug2:
	accumulate的第二条调用会产生严重错误。
原因：
	warning C4172: 返回局部变量或临时变量的地址
解决方法：
	将BookItemAdd的()方法返回值改为return by value。
	Sale_item& => Sale_item

*/