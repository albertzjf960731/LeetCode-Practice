/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (28.86%)
 * Likes:    1066
 * Dislikes: 2514
 * Total Accepted:    385.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '2.00000\n10'
 *
 * Implement pow(x, n), which calculates x raised to the power n (x^n).
 * 
 * Example 1:
 * 
 * 
 * Input: 2.00000, 10
 * Output: 1024.00000
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 2.10000, 3
 * Output: 9.26100
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 2.00000, -2
 * Output: 0.25000
 * Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
 * 
 * 
 * Note:
 * 
 * 
 * -100.0 < x < 100.0
 * n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) 
            return 1;
        else if(n<0)
            return 1/x * myPow(1/x, -(n+1));
        else if(n%2==1)
            return x * myPow(x, n-1);
        else 
            return myPow(x*x, n/2);


        double ans = 1;

        if (n==0) return 1;
        if (n<0) {
            x = 1/x;
            n = -(n+1);
            ans *= x;
        }
        while (n>0) {
            if (n&1) ans *= x;
            x *= x;
            n >>= 1;
        }
        return ans;
    }
};
// @lc code=end

