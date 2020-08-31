/*
 * @lc app=leetcode id=664 lang=cpp
 *
 * [664] Strange Printer
 */
#include<string>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int strangePrinter(string s) {
        if (s.empty()) return 0;
        
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i=0; i<n; ++i) dp[i][i] = 1;

        for(int len=2; len<=n; len++){
            for(int i=0; i<n-len+1; i++){
                int j = i+len-1;
                
                dp[i][j] = (1+dp[i+1][j]);
                
                for (int k=i+1; k<=j; ++k) {
                    if (s[k] == s[i]) 
                        dp[i][j] = min(dp[i][j], dp[i+1][k-1] + dp[k][j]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
// @lc code=end

