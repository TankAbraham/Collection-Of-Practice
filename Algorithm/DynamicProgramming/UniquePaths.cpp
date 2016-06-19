/* 
	62. Unique Paths
	A robot is located at the top - left corner of a m x n grid(marked 'Start' in the diagram below).
	The robot can only move either down or right at any point in time.The robot is trying to reach the bottom - right corner of the grid.

	How many possible unique paths are there ?
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int uniquePaths(const int m, const int n) const {
		vector<vector<int>> vv(m, vector<int>(n, 1));	//DP table

		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				vv[i][j] = vv[i][j - 1] + vv[i - 1][j];
			}
		}

		return vv[m - 1][n - 1];
	}
};

//优化了 DP table 
class Solution2 {
public:
	int uniquePaths(const int m, const int n) const {
		if (m == 1 || n == 1)	return 1;

		int max = m > n ? m : n;
		int min = m > n ? n : m;

		vector<int> v(max);

		for (vector<int>::size_type i = 0; i < v.size(); i++)
			v[i] = i + 1;

		for (int j = 2; j < min; j++) {
			for (int i = 1; i < max && max > 2; i++)
				v[i] += v[i - 1];
		}

		return v[v.size() - 1];
	}
};

int main() {
	Solution so;

	cout << so.uniquePaths(1,2) << endl;

	return 0;
}