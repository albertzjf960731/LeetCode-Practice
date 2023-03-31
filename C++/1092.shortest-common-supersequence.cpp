/*
 * @lc app=leetcode id=1092 lang=cpp
 *
 * [1092] Shortest Common Supersequence 
 *
 * https://leetcode.com/problems/shortest-common-supersequence/description/
 *
 * algorithms
 * Hard (58.05%)
 * Likes:    3653
 * Dislikes: 56
 * Total Accepted:    72.5K
 * Total Submissions: 125.2K
 * Testcase Example:  '"abac"\n"cab"'
 *
 * Given two strings str1 and str2, return the shortest string that has both
 * str1 and str2 as subsequences. If there are multiple valid strings, return
 * any of them.
 * 
 * A string s is a subsequence of string t if deleting some number of
 * characters from t (possibly 0) results in the string s.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: str1 = "abac", str2 = "cab"
 * Output: "cabac"
 * Explanation: 
 * str1 = "abac" is a subsequence of "cabac" because we can delete the first
 * "c".
 * str2 = "cab" is a subsequence of "cabac" because we can delete the last
 * "ac".
 * The answer provided is the shortest such string that satisfies these
 * properties.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
 * Output: "aaaaaaaa"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= str1.length, str2.length <= 1000
 * str1 and str2 consist of lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        string lcs = helper(s1, s2);
        cout << lcs << endl;

        int i=0, j=0;
        string ans = "";
        for (char c: lcs) {
            while (c != s1[i]) ans += s1[i++];
            while (c != s2[j]) ans += s2[j++];
            ans += c, i += 1, j += 1;
        }
        return ans + s1.substr(i) + s2.substr(j);
    }

    string helper(string& s1, string& s2) {
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

};
// @lc code=end

