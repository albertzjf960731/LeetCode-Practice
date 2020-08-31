/*
 * @lc app=leetcode id=921 lang=cpp
 *
 * [921] Minimum Add to Make Parentheses Valid
 */
#include<vector>
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    int minAddToMakeValid(string str) {
        vector<char> stack;
        for (char ch: str) {
            if (!stack.empty() && stack.back()=='(' && ch==')')
                stack.pop_back();
            else 
                stack.push_back(ch);
        }
        return stack.size();

        // 经典区间dp问题，dp[i][j]代表着从字符串i位置到j位置需要的最小括号匹配数，如果第i个位置和第j个位置的两个括号是匹配的，那么dp[i][j] = dp[i+1][j-1]，相当于两边分别往里缩了一个；当i<j时，dp[i][j] = dp[i][k]+dp[k+1][j] ;

        int n = str.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for(int i=0; i<n; ++i) dp[i][i]=1;

        for(int len=2; len<=n; len++){
            for(int i=0; i < n-len+1; i++){
                int j = i+len-1;

                dp[i][j]=n;
                if((str[i]=='[' && str[j]==']') || (str[i]=='(' && str[j]==')'))
                    dp[i][j] = min(dp[i][j], dp[i+1][j-1]);

                for(int k=i; k<j; k++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
            }
        }
        return dp[0][n-1];
    }
};
// @lc code=end

