/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] Reverse Integer
 */
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int reverse(int x) {
        // int sign=1;
        // if (x==0)
        //     return 0;
        // else if (x<0) {
        //     x = -x;
        //     sign = -1;
        // }

        long ans=0;
        while (x!=0){
            ans = ans*10 + x%10;
            x = x/10;
        }

        // ans = ans*sign;
        return (ans>INT_MAX || ans<INT_MIN) ? 0 : ans;
    }
};
// @lc code=end

