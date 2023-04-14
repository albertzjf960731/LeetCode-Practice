/*
 * @lc app=leetcode id=2390 lang=cpp
 *
 * [2390] Removing Stars From a String
 *
 * https://leetcode.com/problems/removing-stars-from-a-string/description/
 *
 * algorithms
 * Medium (65.17%)
 * Likes:    1509
 * Dislikes: 107
 * Total Accepted:    86.6K
 * Total Submissions: 121.1K
 * Testcase Example:  '"leet**cod*e"'
 *
 * You are given a string s, which contains stars *.
 * 
 * In one operation, you can:
 * 
 * 
 * Choose a star in s.
 * Remove the closest non-star character to its left, as well as remove the
 * star itself.
 * 
 * 
 * Return the string after all stars have been removed.
 * 
 * Note:
 * 
 * 
 * The input will be generated such that the operation is always possible.
 * It can be shown that the resulting string will always be unique.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "leet**cod*e"
 * Output: "lecoe"
 * Explanation: Performing the removals from left to right:
 * - The closest character to the 1^st star is 't' in "leet**cod*e". s becomes
 * "lee*cod*e".
 * - The closest character to the 2^nd star is 'e' in "lee*cod*e". s becomes
 * "lecod*e".
 * - The closest character to the 3^rd star is 'd' in "lecod*e". s becomes
 * "lecoe".
 * There are no more stars, so we return "lecoe".
 * 
 * Example 2:
 * 
 * 
 * Input: s = "erase*****"
 * Output: ""
 * Explanation: The entire string is removed, so we return an empty string.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s consists of lowercase English letters and stars *.
 * The operation above can be performed on s.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string removeStars(string s) {
    
        string ans;
        for (char c: s)
            if (c == '*')
                ans.pop_back();
            else
                ans += c;
        return ans;

        int n = s.size();
        string ans = "";
        for (int i=n-1; i>=0; --i) {
            if (s[i] != '*') {
                ans.push_back(s[i]);
            }
            else {
                int cnt = 1;
                while (cnt) {
                    i -= 1;
                    if (s[i] == '*') cnt += 1;
                    else cnt -= 1;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

