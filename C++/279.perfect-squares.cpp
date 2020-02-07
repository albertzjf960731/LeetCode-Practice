/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 *
 * https://leetcode.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (43.92%)
 * Likes:    2054
 * Dislikes: 161
 * Total Accepted:    237.4K
 * Total Submissions: 537.4K
 * Testcase Example:  '12'
 *
 * Given a positive integer n, find the least number of perfect square numbers
 * (for example, 1, 4, 9, 16, ...) which sum to n.
 * 
 * Example 1:
 * 
 * 
 * Input: n = 12
 * Output: 3 
 * Explanation: 12 = 4 + 4 + 4.
 * 
 * Example 2:
 * 
 * 
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1);
        for (int i=1; i<=n; i++) {
            dp[i] = i;
            for (int j=1; j*j<=i; j++)
                dp[i] = min(dp[i], dp[i-j*j]+1);
        }
        return dp[n];
    }
};
// @lc code=end

