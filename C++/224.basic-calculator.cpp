/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 *
 * https://leetcode.com/problems/basic-calculator/description/
 *
 * algorithms
 * Hard (36.94%)
 * Likes:    1598
 * Dislikes: 139
 * Total Accepted:    170K
 * Total Submissions: 458.6K
 * Testcase Example:  '"1 + 1"'
 *
 * Implement a basic calculator to evaluate a simple expression string.
 * 
 * The expression string may contain open ( and closing parentheses ), the plus
 * + or minus sign -, non-negative integers and empty spaces  .
 * 
 * Example 1:
 * 
 * 
 * Input: "1 + 1"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: " 2-1 + 2 "
 * Output: 3
 * 
 * Example 3:
 * 
 * 
 * Input: "(1+(4+5+2)-3)+(6+8)"
 * Output: 23
 * Note:
 * 
 * 
 * You may assume that the given expression is always valid.
 * Do not use the eval built-in library function.
 * 
 * 
 */
#include<vector>
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        // long ans = 0;
        // vector<long> stack;
        
        // long num = 0;
        // long sign = 1;
        // for (int i=0; i<s.size(); ++i) {
        //     char ch = s[i];
            
        //     if (isdigit(ch)) num = num * 10 + ch - '0';
        //     else if (ch == '+') {
        //         ans += sign * num;
        //         num = 0;
        //         sign = 1;
        //     }
        //     else if (ch == '-') {
        //         ans += sign * num;
        //         num = 0;
        //         sign = -1;
        //     }
        //     else if (ch == '(') {
        //         stack.push_back(ans);
        //         stack.push_back(sign);
        //         sign = 1;
        //         ans = 0;
        //     }
        //     else if (ch == ')') {
        //         ans += sign * num;
        //         num = 0;
        //         sign = stack.back(); stack.pop_back();
        //         ans = ans * sign + stack.back(); stack.pop_back();
        //         sign = 1;
        //     }
        //     else 
        //         continue;
        // }
        
        // if (num) 
        //     ans += sign * num;
        // return ans;

        int res = 0, num = 0, sign = 1, n = s.size();
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c >= '0' && c <= '9') {
                num = 10 * num + (c - '0');
            } else if (c == '(') {
                int j = i, cnt = 0;
                for (; i < n; ++i) {
                    if (s[i] == '(') ++cnt;
                    if (s[i] == ')') --cnt;
                    if (cnt == 0) break;
                }
                num = calculate(s.substr(j + 1, i - j - 1));
            }
            if (c == '+' || c == '-' || i == n - 1) {
                res += sign * num;
                num = 0;
                sign = (c == '+') ? 1 : -1;
             } 
        }
        return res;

    }
};
// @lc code=end

