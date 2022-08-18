/*
 * @lc app=leetcode id=2328 lang=cpp
 *
 * [2328] Number of Increasing Paths in a Grid
 *
 * https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/description/
 *
 * algorithms
 * Hard (47.26%)
 * Likes:    420
 * Dislikes: 12
 * Total Accepted:    11.1K
 * Total Submissions: 23.6K
 * Testcase Example:  '[[1,1],[3,4]]'
 *
 * You are given an m x n integer matrix grid, where you can move from a cell
 * to any adjacent cell in all 4 directions.
 * 
 * Return the number of strictly increasing paths in the grid such that you can
 * start from any cell and end at any cell. Since the answer may be very large,
 * return it modulo 10^9 + 7.
 * 
 * Two paths are considered different if they do not have exactly the same
 * sequence of visited cells.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[1,1],[3,4]]
 * Output: 8
 * Explanation: The strictly increasing paths are:
 * - Paths with length 1: [1], [1], [3], [4].
 * - Paths with length 2: [1 -> 3], [1 -> 4], [3 -> 4].
 * - Paths with length 3: [1 -> 3 -> 4].
 * The total number of paths is 4 + 3 + 1 = 8.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[1],[2]]
 * Output: 3
 * Explanation: The strictly increasing paths are:
 * - Paths with length 1: [1], [2].
 * - Paths with length 2: [1 -> 2].
 * The total number of paths is 2 + 1 = 3.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 1000
 * 1 <= m * n <= 10^5
 * 1 <= grid[i][j] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<long>> dp;
    int mod = 1e9+7;
    vector<vector<int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    
    int countPaths(vector<vector<int>>& nums) {
        int n = nums.size(), m = nums[0].size();
        dp.resize(n, vector<long>(m, -1));
        
        long ans=0;
        for(int i=0; i<n; i++) 
            for(int j=0; j<m; j++)
                ans = (ans + DFS(nums,i,j)) % mod;
        return ans;
    }

    long DFS(vector<vector<int>>& nums,int i,int j) {
        if(dp[i][j]!=-1) return dp[i][j];
        
        int n = nums.size(), m = nums[0].size();
        int ans = 1;
        for(vector<int>& d : dirs) { 
            int x = i + d[0], y = j + d[1];
            if (x<0 || x>=n || y<0 || y>=m) continue;
            if(nums[x][y] <= nums[i][j]) continue;
            ans = (ans + DFS(nums, x, y)) % mod;
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
};
// @lc code=end

