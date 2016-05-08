#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

// ����P100 ���ֲ���
template <typename T, typename T2>
T binarySearch(const T &start, const T &end, const T2& val) {
	T mid = start + (end - start) / 2;
	while (mid != end  &&  *mid != val) {
		if (val < *mid)
			//end = mid;	BUG:��const��Ա��ֵ������ʱ����
		else
			start = mid + 1;
		mid = start + (end - start) / 2;
	}
	return mid;
}

int main()
{
	ifstream fin("data3.dat");

	vector<int> v;
	int num;
	while (fin >> num)
		v.push_back(num);

	cout << *binarySearch(v.begin(), v.end(), 4);

	return 0;
}