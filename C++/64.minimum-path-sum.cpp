/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (49.73%)
 * Likes:    1833
 * Dislikes: 46
 * Total Accepted:    285.1K
 * Total Submissions: 572.5K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();

        for (int i=1; i<rows; i++)
            matrix[i][0] = matrix[i-1][0] + matrix[i][0];
        for (int j=1; j<cols; j++) 
            matrix[0][j] = matrix[0][j-1] + matrix[0][j];
        for (int i=1; i<rows; i++) {
            for (int j=1; j<cols; j++) 
                matrix[i][j] += min(matrix[i-1][j], matrix[i][j-1]);
        }
        return matrix[rows-1][cols-1];
    }
};
// @lc code=end

