/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (23.30%)
 * Likes:    1937
 * Dislikes: 2177
 * Total Accepted:    324.4K
 * Total Submissions: 1.4M
 * Testcase Example:  '"12"'
 *
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 * 
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * Given a non-empty string containing only digits, determine the total number
 * of ways to decode it.
 * 
 * Example 1:
 * 
 * 
 * Input: "12"
 * Output: 2
 * Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "226"
 * Output: 3
 * Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
 * 6).
 * 
 */
#include<string>
#include<vector>
using namespace std; 

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() && s[0]=='0') 
            return 0;
        
        int s_size = s.size();
        vector<int> dp(s_size+1, 0);
        dp[0] = 1;
        dp[1] = s[0]!='0' ? 1: 0;

        for (int i=2; i<s_size+1; i++) {
            int first = stoi(s.substr(i-1, 1));
            int second = stoi(s.substr(i-2, 2));
            if (1<=first && first<=9) 
                dp[i] += dp[i-1];
            if (10<=second && second<=26) 
                dp[i] += dp[i-2];
        }
        return dp[s_size];
    }
};
// @lc code=end

