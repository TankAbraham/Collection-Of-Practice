#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	vector<int> v1{1, 2, 3};
	vector<string> v2;

	count_if(v1.cbegin(), v1.cend(), bind(greater<int>(), placeholders::_1, 1024));
	find_if(v2.cbegin(), v2.cend(), bind(not_equal_to<string>(), placeholders::_1, "pooh"));

	// 将所有值乘以 2
	for_each(v1.begin(), v1.end(),[](int& n) {
		n *= 2;
	});
	// 验证上面的 lambda 表达式
	for (auto e : v1)
		cout << e << " ";

	return 0;
}

/* 习题 14.42 */