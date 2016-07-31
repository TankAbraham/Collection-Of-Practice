/*
 * 面试链家网时被考到的 DP 经典问题，最大连续子数组和问题。
 * 在《编程之法》有很好的解答
 */
#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(const vector<int> &v) {
	int curr = 0;
	int ret = v[0];

	for (auto e : v) {
		if (curr >= 0) {
			curr += e;
		}
		else {
			curr = e;
		}

		ret = curr > ret ? curr : ret;
	}

	return ret;
}

int main() {
	cout << maxSubArray({1, -2, 3, 10, -4, 7, 2, -5}) << endl;
	return 0;
}