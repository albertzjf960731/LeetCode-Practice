/*
 * @lc app=leetcode id=664 lang=cpp
 *
 * [664] Strange Printer
 *
 * https://leetcode.com/problems/strange-printer/description/
 *
 * algorithms
 * Hard (40.32%)
 * Likes:    448
 * Dislikes: 51
 * Total Accepted:    15.1K
 * Total Submissions: 37.3K
 * Testcase Example:  '"aaabbb"'
 *
 * 
 * There is a strange printer with the following two special requirements:
 * 
 * 
 * The printer can only print a sequence of the same character each time.
 * At each turn, the printer can print new characters starting from and ending
 * at any places, and will cover the original existing characters.
 * 
 * 
 * 
 * 
 * 
 * Given a string consists of lower English letters only, your job is to count
 * the minimum number of turns the printer needed in order to print it.
 * 
 * 
 * Example 1:
 * 
 * Input: "aaabbb"
 * Output: 2
 * Explanation: Print "aaa" first and then print "bbb".
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "aba"
 * Output: 2
 * Explanation: Print "aaa" first and then print "b" from the second place of
 * the string, which will cover the existing character 'a'.
 * 
 * 
 * 
 * Hint: Length of the given string will not exceed 100.
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

