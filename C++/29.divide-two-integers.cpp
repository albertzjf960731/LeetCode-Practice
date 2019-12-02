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
        int sign = ((dividend<0)==(divisor<0)) ? 1: -1;

        long long_dividend = labs(dividend), long_divisor= labs(divisor);  

        long ans=0, temp, i;
        while(long_dividend>=long_divisor) {
            temp=long_divisor, i=1;
            while (long_dividend>=temp) {
                long_dividend -= temp;
                ans += i;
                temp <<= 1;
                i <<= 1;

                if (ans*sign >=INT_MAX) return INT_MAX;
                if (ans*sign<=INT_MIN) return INT_MIN;
            }
        }  
        return ans*sign;
    }
};
// @lc code=end

