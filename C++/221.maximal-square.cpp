/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 *
 * https://leetcode.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (34.74%)
 * Likes:    1880
 * Dislikes: 47
 * Total Accepted:    168.6K
 * Total Submissions: 485.1K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square
 * containing only 1's and return its area.
 * 
 * Example:
 * 
 * 
 * Input: 
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * Output: 4
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;

        if (matrix.empty())
            return ans;
        vector<vector<int>> dp(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));

        for (int i=0; i<matrix.size(); i++) {
            for (int j=0; j<matrix[0].size(); j++) {
                if (matrix[i][j]=='1') {
                    dp[i+1][j+1] = min(dp[i][j], min(dp[i+1][j], dp[i][j+1]))+1;
                    ans = max(ans, dp[i+1][j+1]);
                }
            }
        }
        return ans*ans;
    }
};
// @lc code=end

