/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */
#include<string>
#include<vector>
#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        vector<int> dp(s.size()+1, 0);

        for (int i=1; i<s.size(); i++) {
            if (s[i] == ')') {
                if (s[i-1] == '(')
                    dp[i+1] = dp[i-1]+2;
                else if (i-dp[i]>0 && s[i-dp[i]-1]=='(')
                    dp[i+1] = dp[i] + dp[i-dp[i]-1] +2;
            }
            ans = max(ans, dp[i+1]);
        }
        return ans;
    }
};
// @lc code=end

int main() {
    Solution sol;
    string s = "()(())";
    int ans = sol.longestValidParentheses(s);
    cout<<"ans="<<ans<<endl;
}
