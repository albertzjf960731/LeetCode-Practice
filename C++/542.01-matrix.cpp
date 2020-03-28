/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 *
 * https://leetcode.com/problems/01-matrix/description/
 *
 * algorithms
 * Medium (38.36%)
 * Likes:    1066
 * Dislikes: 95
 * Total Accepted:    69.1K
 * Total Submissions: 180K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * Given a matrix consists of 0 and 1, find the distance of the nearest 0 for
 * each cell.
 * 
 * The distance between two adjacent cells is 1.
 * 
 * 
 * 
 * Example 1: 
 * 
 * 
 * Input:
 * [[0,0,0],
 * ⁠[0,1,0],
 * ⁠[0,0,0]]
 * 
 * Output:
 * [[0,0,0],
 * [0,1,0],
 * [0,0,0]]
 * 
 * 
 * Example 2: 
 * 
 * 
 * Input:
 * [[0,0,0],
 * ⁠[0,1,0],
 * ⁠[1,1,1]]
 * 
 * Output:
 * [[0,0,0],
 * ⁠[0,1,0],
 * ⁠[1,2,1]]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of elements of the given matrix will not exceed 10,000.
 * There are at least one 0 in the given matrix.
 * The cells are adjacent in only four directions: up, down, left and right.
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rows=matrix.size(), cols=matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, max(rows, cols)));
        
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                if (matrix[i][j]==0)
                    dp[i][j] = 0;
                else {
                    if (i>0 && j>0)
                        dp[i][j] = min(min(dp[i-1][j]+1, dp[i][j-1]+1), dp[i][j]);
                    else if(i>0 && j==0)
                        dp[i][j] = min(dp[i-1][j]+1, dp[i][j]);
                    else if(i==0 && j>0)
                        dp[i][j] = min(dp[i][j-1]+1, dp[i][j]);
                }
            }
        }
        for (int i=rows-1; i>=0; i--) {
            for (int j=cols-1; j>=0; j--) {
                if (matrix[i][j]==0)
                    dp[i][j] = 0;
                else {
                    if (i<rows-1 && j<cols-1)
                        dp[i][j] = min(min(dp[i+1][j]+1, dp[i][j+1]+1), dp[i][j]);
                    else if(i<rows-1 && j==cols-1)
                        dp[i][j] = min(dp[i+1][j]+1, dp[i][j]);
                    else if(i==rows-1 && j<cols-1)
                        dp[i][j] = min(dp[i][j+1]+1, dp[i][j]);
                }
            }
        }
        return dp;
    }
};
// @lc code=end

