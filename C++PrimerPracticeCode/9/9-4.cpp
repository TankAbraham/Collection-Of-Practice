#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

// ����P100 ���ֲ���
template <typename T, typename T2>
T binarySearch(const T &start, const T &end, const T2 &val) {
	T mid = start + (end - start) / 2;
	T beg = start;
	T last = end;
	
	if (val < *beg || val > *(--last))
		return end;

	while (mid != last  &&  *mid != val) {
		if (val < *mid)
			last = mid;
		else
			beg = mid + 1;
		mid = beg + (last - beg) / 2;
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

	auto it = binarySearch(v.begin(), v.end(), 40);

	if (it == v.end())
		cout << "����end() ˵��Ҫ�ҵ�Ԫ�ز��ڸ�����֮�� " << endl;
	else
		cout << *it;

	return 0;
}