/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        // if (dividend == INT_MIN && divisor == -1) {
        //     return INT_MAX;
        // }
        // if (dividend == INT_MIN && divisor == 1) {
        //     return INT_MIN;
        // }

        if (dividend == INT_MIN) {
            if (divisor == 1) return INT_MIN;
            else if (divisor == -1) return INT_MAX;
            else if (divisor & 1) return divide(dividend+1, divisor);
            else return divide(dividend >> 1, divisor >> 1);
        }
        if(divisor == INT_MIN) return 0;

        int sign = ((dividend<0) == (divisor<0)) ? 1 : -1;
        dividend = abs(dividend), divisor = abs(divisor);
        
        int ans = 0;
        while (dividend >= divisor) {
            int tmp_divisor = divisor;
            int tmp_quotient = 1;

            while (dividend >= (tmp_divisor << 1)) {
                tmp_divisor <<= 1;
                tmp_quotient <<= 1;
            }
            dividend -= tmp_divisor;
            ans += tmp_quotient;
        }
        
        return ans * sign;
    }
};
// @lc code=end

