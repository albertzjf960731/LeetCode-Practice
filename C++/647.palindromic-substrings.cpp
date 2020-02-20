/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 *
 * https://leetcode.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (59.13%)
 * Likes:    1992
 * Dislikes: 97
 * Total Accepted:    148.8K
 * Total Submissions: 251.6K
 * Testcase Example:  '"abc"'
 *
 * Given a string, your task is to count how many palindromic substrings in
 * this string.
 * 
 * The substrings with different start indexes or end indexes are counted as
 * different substrings even they consist of same characters.
 * 
 * Example 1:
 * 
 * 
 * Input: "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The input string length won't exceed 1000.
 * 
 * 
 * 
 */
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0, n = s.size();
        for (int i=0; i<s.size(); i++) {
            // ans += expand(s, i, i);
            // ans += expand(s, i, i+1);
            for(int j=0; i-j>=0 && i+j<n && s[i-j]==s[i+j]; j++)
                ans++; 
            for(int j=0; i-1-j>=0 && i+j<n && s[i-1-j] == s[i+j]; j++)
                ans++; 
        }
        return ans;
    }
    int expand(string &s, int l, int r) {
        int ans = 0;
        while (l>=0 && r<s.size() && s[l--]==s[r++])
            ans ++;
        return ans;
    }
};
// @lc code=end

