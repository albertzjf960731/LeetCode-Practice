/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 *
 * https://leetcode.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (38.08%)
 * Likes:    1223
 * Dislikes: 77
 * Total Accepted:    123.1K
 * Total Submissions: 323.2K
 * Testcase Example:  '10'
 *
 * Write a program to find the n-th ugly number.
 * 
 * Ugly numbers are positive numbers whose prime factors only include 2, 3,
 * 5. 
 * 
 * Example:
 * 
 * 
 * Input: n = 10
 * Output: 12
 * Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10
 * ugly numbers.
 * 
 * Note:  
 * 
 * 
 * 1 is typically treated as an ugly number.
 * n does not exceed 1690.
 * 
 */

#include<vector>
using namespace std; 

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        int i2=0, i3=0, i5=0;
        vector<int> dp(n);
        dp[0] = 1;

        for (int i=1; i<n; i++) {
            dp[i] = min(dp[i2]*2, min(dp[i3]*3, dp[i5]*5));
            if (dp[i]==dp[i2]*2)
                i2++;
            if (dp[i]==dp[i3]*3)
                i3++;
            if (dp[i]==dp[i5]*5)
                i5++;
        }
        return dp[n-1];
    }
};
// @lc code=end

