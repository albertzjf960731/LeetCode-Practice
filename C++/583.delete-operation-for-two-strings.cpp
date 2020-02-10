/*
 * @lc app=leetcode id=583 lang=cpp
 *
 * [583] Delete Operation for Two Strings
 *
 * https://leetcode.com/problems/delete-operation-for-two-strings/description/
 *
 * algorithms
 * Medium (46.59%)
 * Likes:    861
 * Dislikes: 23
 * Total Accepted:    40.7K
 * Total Submissions: 87.4K
 * Testcase Example:  '"sea"\n"eat"'
 *
 * 
 * Given two words word1 and word2, find the minimum number of steps required
 * to make word1 and word2 the same, where in each step you can delete one
 * character in either string.
 * 
 * 
 * Example 1:
 * 
 * Input: "sea", "eat"
 * Output: 2
 * Explanation: You need one step to make "sea" to "ea" and another step to
 * make "eat" to "ea".
 * 
 * 
 * 
 * Note:
 * 
 * The length of given words won't exceed 500.
 * Characters in given words can only be lower-case letters.
 * 
 * 
 */
#include<vector>
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int size1=word1.size(), size2=word2.size();
        
        vector<vector<int>> dp(size1+1, vector<int>(size2+1, 0));
        for (int i=1; i<=size1; i++) dp[i][0] = i;
        for (int j=1; j<=size2; j++) dp[0][j] = j;

        for (int i=1; i<size1+1; ++i) {
            for (int j=1; j<size2+1; ++j) {
                if (word1[i-1]==word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else 
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1])+1;
            }
        }
        return dp[size1][size2];

        return word1.size()+word2.size()-longestCommonSubsequence(word1, word2)*2;
    }

    int longestCommonSubsequence(string text1, string text2) {
        int size1=text1.size(), size2=text2.size();

        vector<vector<int>> dp(size1+1, vector<int>(size2+1, 0));

        for (int i=1; i<size1+1; ++i) {
            for (int j=1; j<size2+1; ++j) {
                if (text1[i-1]==text2[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[size1][size2];
    }
};
// @lc code=end

