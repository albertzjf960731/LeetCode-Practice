/*
 * @lc app=leetcode id=712 lang=cpp
 *
 * [712] Minimum ASCII Delete Sum for Two Strings
 *
 * https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/
 *
 * algorithms
 * Medium (56.72%)
 * Likes:    709
 * Dislikes: 41
 * Total Accepted:    27.8K
 * Total Submissions: 49K
 * Testcase Example:  '"sea"\n"eat"'
 *
 * Given two strings s1, s2, find the lowest ASCII sum of deleted characters to
 * make two strings equal.
 * 
 * Example 1:
 * 
 * Input: s1 = "sea", s2 = "eat"
 * Output: 231
 * Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to
 * the sum.
 * Deleting "t" from "eat" adds 116 to the sum.
 * At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum
 * possible to achieve this.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: s1 = "delete", s2 = "leet"
 * Output: 403
 * Explanation: Deleting "dee" from "delete" to turn the string into "let",
 * adds 100[d]+101[e]+101[e] to the sum.  Deleting "e" from "leet" adds 101[e]
 * to the sum.
 * At the end, both strings are equal to "let", and the answer is
 * 100+101+101+101 = 403.
 * If instead we turned both strings into "lee" or "eet", we would get answers
 * of 433 or 417, which are higher.
 * 
 * 
 * 
 * Note:
 * 0 < s1.length, s2.length .
 * All elements of each string will have an ASCII value in [97, 122]. 
 * 
 */
#include<vector>
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    int minimumDeleteSum(string word1, string word2) {
        int size1=word1.size(), size2=word2.size();
        
        vector<vector<int>> dp(size1+1, vector<int>(size2+1, 0));
        for (int i=1; i<=size1; i++) dp[i][0] = dp[i-1][0] + word1[i-1];
        for (int j=1; j<=size2; j++) dp[0][j] = dp[0][j-1] + word2[j-1];

        for (int i=1; i<size1+1; ++i) {
            for (int j=1; j<size2+1; ++j) {
                if (word1[i-1]==word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else 
                    dp[i][j] = min(dp[i-1][j]+word1[i-1], dp[i][j-1]+word2[j-1]);
            }
        }
        return dp[size1][size2];
    }
};
// @lc code=end

