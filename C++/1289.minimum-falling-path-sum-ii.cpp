/*
 * @lc app=leetcode id=1289 lang=cpp
 *
 * [1289] Minimum Falling Path Sum II
 *
 * https://leetcode.com/problems/minimum-falling-path-sum-ii/description/
 *
 * algorithms
 * Hard (61.01%)
 * Likes:    975
 * Dislikes: 72
 * Total Accepted:    31.6K
 * Total Submissions: 52.5K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given an n x n integer matrix grid, return the minimum sum of a falling path
 * with non-zero shifts.
 * 
 * A falling path with non-zero shifts is a choice of exactly one element from
 * each row of grid such that no two elements chosen in adjacent rows are in
 * the same column.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: 13
 * Explanation: 
 * The possible falling paths are:
 * [1,5,9], [1,5,7], [1,6,7], [1,6,8],
 * [2,4,8], [2,4,9], [2,6,7], [2,6,8],
 * [3,4,8], [3,4,9], [3,5,7], [3,5,9]
 * The falling path with the smallest sum is [1,5,7], so the answer is 13.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[7]]
 * Output: 7
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == grid.length == grid[i].length
 * 1 <= n <= 200
 * -99 <= grid[i][j] <= 99
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = nums.size();
        if (n == 1) return nums[0][0];
        
        int min1 = -1, min2 = -1;
        for (int i=0; i<n; ++i) {
            int last1 = min1, last2 = min2;
            min1 = -1, min2 = -1;
            
            for (int j=0; j<n; ++j) {
                if (i > 0) {
                    if (j != last1) nums[i][j] += nums[i-1][last1];
                    else nums[i][j] += nums[i-1][last2];
                }
                
                if (min1 < 0 || nums[i][j] < nums[i][min1]) {
                    min2 = min1;
                    min1 = j;
                }
                else if (min2 < 0 || nums[i][j] < nums[i][min2]) {
                    min2 = j;
                }
            }
        }
        return nums[n-1][min1];
    }
};
// @lc code=end

