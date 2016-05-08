#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("data3.dat");

	vector<int> v;
	list<int> l;
	int i;
	while (fin >> i)
		l.push_back(i);

	/* ����Ӧ���ò��������
	copy(l.cbegin(), l.cend(), v.begin()); */
	copy(l.cbegin(), l.cend(), back_inserter(v));

	for_each(v.begin(), v.end(), [](const int a) {cout << a << " "; });
	return 0;
}