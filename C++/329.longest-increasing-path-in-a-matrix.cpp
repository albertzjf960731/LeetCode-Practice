/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 *
 * https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
 *
 * algorithms
 * Hard (43.53%)
 * Likes:    2176
 * Dislikes: 41
 * Total Accepted:    160.3K
 * Total Submissions: 367.3K
 * Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
 *
 * Given an integer matrix, find the length of the longest increasing path.
 * 
 * From each cell, you can either move to four directions: left, right, up or
 * down. You may NOT move diagonally or move outside of the boundary (i.e.
 * wrap-around is not allowed).
 * 
 * Example 1:
 * 
 * 
 * Input: nums = 
 * [
 * ⁠ [9,9,4],
 * ⁠ [6,6,8],
 * ⁠ [2,1,1]
 * ] 
 * Output: 4 
 * Explanation: The longest increasing path is [1, 2, 6, 9].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = 
 * [
 * ⁠ [3,4,5],
 * ⁠ [3,2,6],
 * ⁠ [2,2,1]
 * ] 
 * Output: 4 
 * Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally
 * is not allowed.
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int  m = matrix.size(), n = matrix[0].size();
        int ans = 1;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                ans = max(ans, DFS(matrix, dp, i, j));
            }
        }
        return ans;
    }
    int DFS(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j) {
        vector<vector<int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

        if (dp[i][j]) return dp[i][j];
        
        int m = matrix.size(), n = matrix[0].size();
        
        int ans = 1;
        for (auto d : dirs) {
            int x = i + d[0], y = j + d[1];
            if (x<0 || x>=m || y<0 || y>=n || matrix[x][y] <= matrix[i][j]) 
                continue;
            int len = 1 + DFS(matrix, dp, x, y);
            ans = max(ans, len);
        }
        dp[i][j] = ans;
        return ans;
    }
};
// @lc code=end

