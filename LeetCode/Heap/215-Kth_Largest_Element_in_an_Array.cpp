/*
 * 只是用堆就搞定了，但显然存在更好的解决算法
 */
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int> heap;
		
		for (auto e : nums) {
			heap.push(e);
		}

		int temp;
		for (int i = 0; i < k; i++) {
			temp = heap.top();
			heap.pop();
		}

		return temp;
	}
};