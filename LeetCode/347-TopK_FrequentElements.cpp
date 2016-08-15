/*
 * O（N + N * longN） 的解法
 */
#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

struct FrequencyCmp {
	bool operator() (const pair<int, unsigned int> &lhs, pair<int, unsigned int> &rhs) {
		return  lhs.second < rhs.second ? true : false;
	}
};

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, unsigned int> numberFrequency;

		for (auto e : nums) {
			numberFrequency[e]++;
		}

		priority_queue<pair<int, unsigned int>, vector<pair<int, unsigned int>>, FrequencyCmp> heap;

		for (auto e : numberFrequency) {
			heap.push(e);
		}

		vector<int> v;

		for (int i = 0; i < k; i++) {
			v.push_back(heap.top().first);
			heap.pop();
		}

		return v;
	}
};

int main() {
	Solution so;
	vector<int> v = { 1,1,1,2,2,3 };
	vector<int> ret = so.topKFrequent(v, 2);

	for (auto e : ret) {
		cout << e << endl;
	}
	return 0;
}