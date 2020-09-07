/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (48.55%)
 * Likes:    2492
 * Dislikes: 1595
 * Total Accepted:    1M
 * Total Submissions: 2.1M
 * Testcase Example:  '121'
 *
 * Determine whether an integer is a palindrome. An integer is a palindrome
 * when it reads the same backward as forward.
 * 
 * Example 1:
 * 
 * 
 * Input: 121
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it
 * becomes 121-. Therefore it is not a palindrome.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a
 * palindrome.
 * 
 * 
 * Follow up:
 * 
 * Coud you solve it without converting the integer to a string?
 * 
 */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x==0) return true;
        if (x<0) return false;

        return (reverse(x) == x) ? true: false;

        if (x==0) return true;
        if (x<0) return false;
        
        vector<int> stack;
        queue<int> q;
        while (x != 0) {
            stack.push_back(x % 10);
            q.push(x % 10);
            x /= 10;
        }
        
        while (!stack.empty()) {
            if (stack.back() != q.front())
                return false;
            stack.pop_back();
            q.pop();
        }
        return true;
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

