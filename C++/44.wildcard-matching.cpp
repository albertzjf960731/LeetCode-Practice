/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */
#include<string>
#include<vector>
#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int s_size = s.size(), p_size = p.size();

        vector<vector<bool>> dp(s_size+1, vector<bool>(p_size+1, false));
        dp[0][0] = true;

        for (int j=1; j<=p_size; j++) {
            if (p[j-1] == '*')
                dp[0][j] = dp[0][j-1];
        }

        for (int i=1; i<=s_size; i++) {
            for (int j=1; j<=p_size; j++) {
                if (p[j-1] == '*')
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else if (p[j-1]==s[i-1] || p[j-1]=='?') 
                    dp[i][j] = dp[i-1][j-1];
            }
        }
        return dp[s_size][p_size];
    }
};
// @lc code=end

int main() {
    Solution sol;
    string s = "aa", p="*";
    bool ans = sol.isMatch(s, p);
    cout<<"ans="<<ans<<endl;
}