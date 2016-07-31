/*
 * cost : 12ms
 */
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int curr = 0;
		int ret = nums[0];

		for (int i = 0; i < nums.size(); i++) {
			if (curr > 0) {
				curr += nums[i];
			}
			else {
				curr = nums[i];
			}

			ret = curr > ret ? curr : ret;
		}

		return ret;
	}
};


/*
 * cost : 8ms
 */
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int curr = 0;
		int ret = nums[0];

		for(auto e : nums) {
			if (curr > 0) {
				curr += e;
			}
			else {
				curr = e;
			}

			if(curr > ret) {
			    ret = curr;
			}
		}

		return ret;
	}
};



/*
 * cost : 22ms
 */
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int curr = 0;
		int ret = nums[0];

		for(auto e : nums) {
			if (curr > 0) {
				curr += e;
			}
			else {
				curr = e;
			}

			ret = curr > ret ? curr : ret;
		}

		return ret;
	}
};



/*
 * cost : 4ms
 */
int maxSubArray(int* nums, int numsSize) {
	int curr = 0;
	int ret = nums[0];

	for (int i = 0; i < numsSize; i++) {
		if (curr > 0) {
			curr += nums[i];
		} else {
			curr = nums[i];
		}

		if (curr > ret) {
			ret = curr;
		}
	}

	return ret;
}