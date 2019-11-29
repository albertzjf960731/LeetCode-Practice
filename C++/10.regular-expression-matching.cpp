/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */


#include <string>
#include <vector>
#include <iostream>

using namespace std;
// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {

        const int s_size = s.size(), p_size = p.size();

        vector<vector<bool> > dp(s_size+1, vector<bool>(p_size+1, false));
        dp[0][0] = true;
        for (int j=1; j<p_size; j++) 
            dp[0][j+1] = (p[j]=='*' && dp[0][j-1]);
        
        for (int i=0; i<s_size; i++) {
            for (int j=0; j<p_size; j++) {
                if (p[j] == '*') {
                    dp[i+1][j+1] = dp[i+1][j-1];
                    if (p[j-1] == s[i] or p[j-1] == '.')
                        dp[i+1][j+1] = dp[i+1][j+1] || dp[i][j+1];
                }
                if (p[j] == s[i] or p[j] == '.')
                    dp[i+1][j+1] = dp[i][j];
            }
        }
        return dp[s_size][p_size];
    }
};
// @lc code=end

int main() {
    Solution sol;
    string s = "aa", p = "a*";

    cout << sol.isMatch(s, p) << endl;
    return 0;
}