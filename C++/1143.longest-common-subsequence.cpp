/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 *
 * https://leetcode.com/problems/longest-common-subsequence/description/
 *
 * algorithms
 * Medium (57.45%)
 * Likes:    528
 * Dislikes: 11
 * Total Accepted:    33.5K
 * Total Submissions: 58.4K
 * Testcase Example:  '"abcde"\n"ace"'
 *
 * Given two strings text1 and text2, return the length of their longest common
 * subsequence.
 * 
 * A subsequence of a string is a new string generated from the original string
 * with some characters(can be none) deleted without changing the relative
 * order of the remaining characters. (eg, "ace" is a subsequence of "abcde"
 * while "aec" is not). A common subsequence of two strings is a subsequence
 * that is common to both strings.
 * 
 * 
 * 
 * If there is no common subsequence, return 0.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: text1 = "abcde", text2 = "ace" 
 * Output: 3  
 * Explanation: The longest common subsequence is "ace" and its length is 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: text1 = "abc", text2 = "abc"
 * Output: 3
 * Explanation: The longest common subsequence is "abc" and its length is 3.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: text1 = "abc", text2 = "def"
 * Output: 0
 * Explanation: There is no such common subsequence, so the result is 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= text1.length <= 1000
 * 1 <= text2.length <= 1000
 * The input strings consist of lowercase English characters only.
 * 
 * 
 */

#include<string>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int size1=text1.size(), size2=text2.size();

        vector<vector<int>> dp(size1+1, vector<int>(size2+1, 0));

        for (int i=1; i<=size1; ++i) {
            for (int j=1; j<=size2; ++j) {
                if (text1[i-1]==text2[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[size1][size2];

        vector<vector<string>> dp(s1.size()+1, vector<string>(s2.size()+1, ""));
        for (int i=0; i<s1.size(); ++i) {
            for (int j=0; j<s2.size(); ++j) {
                if (s1[i] == s2[j]) 
                    dp[i+1][j+1] = dp[i][j] + s1[i];
                else   
                    dp[i+1][j+1] = dp[i+1][j].size() > dp[i][j+1].size() ?  dp[i+1][j] : dp[i][j+1];
            }
        }
        return dp[s1.size()][s2.size()];
    }

    // string getLCS(string text1, string text2, vector<vector<int>>& dp, 
    //                 int i, int j, string& path, vector<string>& res) {

    //     while(i>0 && j>0) {
    //         if(text1[i] == text2[j]) {
    //             path.push_back(text1[i]);
    //             i--;
    //             j--;
    //         }
    //         else {
    //             if(dp[i-1][j] > dp[i][j-1])
    //                 i--;
    //             else if (dp[i-1][j] < dp[i][j-1])
    //                 j--;
                // else {
                //     getLCS(text1, text2, dp, i-1, j, path);
                //     getLCS(text1, text2, dp, i, j-1, path);
                //     return;
                // }
    //         }
    //     }
    //     reverse(path.begin(), path.end());
    //     res.push_back(path);
    // }

};
// @lc code=end

