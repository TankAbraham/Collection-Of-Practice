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

	// ������ֵ���� 2
	for_each(v1.begin(), v1.end(),[](int& n) {
		n *= 2;
	});
	// ��֤����� lambda ���ʽ
	for (auto e : v1)
		cout << e << " ";

	return 0;
}

/* ϰ�� 14.42 */