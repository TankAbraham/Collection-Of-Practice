#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <functional>

using namespace std;

template <typename T>
struct PendingEqueal{
	bool operator() (const T& lhs, const T& rhs) {
		if (lhs == rhs)
			return true;
		else
			return false;
	}
};

int main() {
	ifstream fin("data4.dat");
	vector<int> v;
	int num;

	while (fin >> num)
		v.push_back(num);

	// °Ñ 5 Ìæ»»³É 0
	replace_if(v.begin(), v.end(), bind(PendingEqueal<int>(), placeholders::_1, 5), 0);

	for (auto &e : v)
		cout << e << " ";

	return 0;
}
