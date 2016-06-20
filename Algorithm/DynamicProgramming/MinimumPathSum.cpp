/*
leetcode 64. Minimum Path Sum

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minPathSum(const vector<vector<int>>& grid) {

		vector<vector<int>>::size_type m = grid.size();
		vector<int>::size_type n = grid[0].size();

		vector<vector<int>> table(m, vector<int>(n));

		table[0][0] = grid[0][0];

		for (vector<vector<int>>::size_type i = 1; i < m; i++)
			table[i][0] = grid[i][0] + table[i - 1][0];

		for (vector<int>::size_type i = 1; i < n; i++)
			table[0][i] = grid[0][i] + table[0][i - 1];

		for (vector<vector<int>>::size_type i = 1; i < m; i++) {
			for (vector<int>::size_type j = 1; j < n; j++) {
				table[i][j] = min(table[i][j - 1], table[i - 1][j]) + grid[i][j];
			}
		}

		return table[m - 1][n - 1];
	}

	//优化了 DP table 空间，在原有数组的基础上记忆性累加
	int minPathSum(vector<vector<int>>& grid) {
		for (unsigned int i = 1; i < grid.size(); i++)
			grid[i][0] += grid[i - 1][0];

		for (unsigned int i = 1; i < grid[0].size(); i++)
			grid[0][i] += grid[0][i - 1];

		for (unsigned int i = 1; i < grid.size(); i++) {
			for (unsigned int j = 1; j < grid[0].size(); j++) {
				grid[i][j] += min(grid[i][j - 1], grid[i - 1][j]);
			}
		}

		return grid[grid.size() - 1][grid[0].size() - 1];
	}
};


int main() {
	Solution so;
	vector<vector<int>> vv;
	
	vv = { {0} };
	cout << so.minPathSum(vv) << endl;

	vv = { {1,2},{1,1} };
	cout << so.minPathSum(vv) << endl;

	return 0;
}