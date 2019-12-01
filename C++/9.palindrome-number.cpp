/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] Palindrome Number
 */
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x==0) return true;
        if (x<0) return false;

        return (reverse(x) == x) ? true: false;
    }

    int reverse(int x) {
        long ans=0;
        while (x!=0){
            ans = ans*10 + x%10;
            x = x/10;
        }

        return (ans>INT_MAX || ans<INT_MIN) ? 0 : ans;
    }
};
// @lc code=end

