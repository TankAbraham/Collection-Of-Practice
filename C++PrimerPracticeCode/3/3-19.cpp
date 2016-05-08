#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
	vector<vector<int>* > v;
	auto iv = back_inserter(v);

	// 方法一 back_inserter()
	iv = new vector<int>;
	back_insert_iterator<vector<int> > it = back_inserter(*v[0]);
	for (int i = 0; i < 10; i++)
		it = 42;

	// 方法二 构造函数
	iv = new vector<int>(10, 42);

	// 方法三 fill_n()
	iv = new vector<int>;
	fill_n(back_inserter(*v[2]), 10, 42);

	// 方法四 
	iv = new vector<int>(10);
	for_each(v[3]->begin(), v[3]->end(), 
		[](int &a) 
	{
		a = 42;
	});


	//打印结果
	int i = 0;
	for_each(v.cbegin(), v.cend(),
		[i](const vector<int>* v) mutable
	{
		cout << "方法" << ++i << " ";
		for_each(v->cbegin(), v->cend(), 
			[](const int a)
		{
			cout << a << " ";
		});
		cout << endl;
	});

	return 0;
}