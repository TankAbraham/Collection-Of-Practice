#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <fstream>

using namespace std;

int main()
{
	/*����resserve()�����ı�������Ԫ������������Ӧ����һ��ʼ�ͷ��� 
	vector<int> v;*/
	vector<int> v(10);
	//v.reserve(10);
	fill_n(v.begin(), 10, 0);
	for_each(v.begin(), v.end(), [](const int a) {cout << a << " "; });
	return 0;
}