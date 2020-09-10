/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 *
 * https://leetcode.com/problems/basic-calculator-ii/description/
 *
 * algorithms
 * Medium (37.02%)
 * Likes:    1556
 * Dislikes: 274
 * Total Accepted:    197K
 * Total Submissions: 530.8K
 * Testcase Example:  '"3+2*2"'
 *
 * Implement a basic calculator to evaluate a simple expression string.
 * 
 * The expression string contains only non-negative integers, +, -, *, /
 * operators and empty spaces  . The integer division should truncate toward
 * zero.
 * 
 * Example 1:
 * 
 * 
 * Input: "3+2*2"
 * Output: 7
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: " 3/2 "
 * Output: 1
 * 
 * Example 3:
 * 
 * 
 * Input: " 3+5 / 2 "
 * Output: 5
 * 
 * 
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
        long num = 0, n = s.size();
        char op = '+';
        
        vector<int> stack;
        for (int i=0; i<n; ++i) {
            char ch = s[i];
            if (isdigit(ch)) {
                num = num * 10 + s[i] - '0';
            }
            
            if (ch=='+' || ch=='-' || ch=='*' || ch=='/' || i == n - 1) {
                if (op == '+') stack.push_back(num);
                if (op == '-') stack.push_back(-num);
                if (op == '*' || op == '/') {
                    int tmp = (op=='*') ? stack.back() * num : stack.back() / num;
                    stack.pop_back();
                    stack.push_back(tmp);
                }
                op = ch;
                num = 0;
            } 
        }
        int ans = 0;
        while (!stack.empty()) {
            ans += stack.back();
            stack.pop_back();
        }
        return ans;
    }
};
// @lc code=end

