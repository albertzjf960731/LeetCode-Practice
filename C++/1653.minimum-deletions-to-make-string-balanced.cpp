/*
 * @lc app=leetcode id=1653 lang=cpp
 *
 * [1653] Minimum Deletions to Make String Balanced
 *
 * https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description/
 *
 * algorithms
 * Medium (59.16%)
 * Likes:    1089
 * Dislikes: 31
 * Total Accepted:    33.3K
 * Total Submissions: 56.3K
 * Testcase Example:  '"aababbab"'
 *
 * You are given a string s consisting only of characters 'a' and 'b'​​​​.
 * 
 * You can delete any number of characters in s to make s balanced. s is
 * balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b'
 * and s[j]= 'a'.
 * 
 * Return the minimum number of deletions needed to make s balanced.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "aababbab"
 * Output: 2
 * Explanation: You can either:
 * Delete the characters at 0-indexed positions 2 and 6 ("aababbab" ->
 * "aaabbb"), or
 * Delete the characters at 0-indexed positions 3 and 6 ("aababbab" ->
 * "aabbbb").
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "bbaaaaabb"
 * Output: 2
 * Explanation: The only solution is to delete the first two characters.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s[i] is 'a' or 'b'​​.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> pre(n, 0), suf(n, 0);
        
        for (int i=1; i<n; ++i) pre[i] = pre[i-1] + (s[i-1] == 'b');
        for (int i=n-2; i>=0; --i) suf[i] = suf[i+1] + (s[i+1] == 'a');

        int ans = n;
        for (int i=0; i<n; ++i) ans = min(ans, pre[i] + suf[i]);
        return ans;

    }
};
// @lc code=end

