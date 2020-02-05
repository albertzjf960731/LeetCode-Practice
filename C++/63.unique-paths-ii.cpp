/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 *
 * https://leetcode.com/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (33.79%)
 * Likes:    1157
 * Dislikes: 191
 * Total Accepted:    242.9K
 * Total Submissions: 718.7K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 * 
 * Now consider if some obstacles are added to the grids. How many unique paths
 * would there be?
 * 
 * 
 * 
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 * 
 * Note: m and n will be at most 100.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * [0,0,0],
 * [0,1,0],
 * [0,0,0]
 * ]
 * Output: 2
 * Explanation:
 * There is one obstacle in the middle of the 3x3 grid above.
 * There are two ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down -> Down
 * 2. Down -> Down -> Right -> Right
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> dp(rows+1, vector<int>(cols+1, 0));
        
        dp[0][1] = 1;
        for (int i=1; i<=rows; i++) {
            for (int j=1; j<=cols; j++) {
                if (!matrix[i-1][j-1])
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[rows][cols];
        
        // int rows = matrix.size(), cols = matrix[0].size();
        // for (int i=0; i<rows; i++) {
        //     for (int j=0; j<cols; j++) {
        //         if (1-matrix[i][j]==0) {
        //             matrix[i][j] = 0;
        //             continue;
        //         }

        //         if (i==0 && j==0)
        //             matrix[i][j] = 1;
        //         else {
        //             if (i==0)
        //                 matrix[i][j] = matrix[i][j-1];
        //             else if(j==0) 
        //                 matrix[i][j] = matrix[i-1][j];
        //             else 
        //                 matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];    
        //         }
        //     }
        // }
        // return matrix[rows-1][cols-1];
    }
};
// @lc code=end

