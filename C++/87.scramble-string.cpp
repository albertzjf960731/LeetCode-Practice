/*
 * @lc app=leetcode id=87 lang=cpp
 *
 * [87] Scramble String
 *
 * https://leetcode.com/problems/scramble-string/description/
 *
 * algorithms
 * Hard (32.55%)
 * Likes:    377
 * Dislikes: 600
 * Total Accepted:    99.8K
 * Total Submissions: 306K
 * Testcase Example:  '"great"\n"rgeat"'
 *
 * Given a string s1, we may represent it as a binary tree by partitioning it
 * to two non-empty substrings recursively.
 * 
 * Below is one possible representation of s1 = "great":
 * 
 * 
 * ⁠   great
 * ⁠  /    \
 * ⁠ gr    eat
 * ⁠/ \    /  \
 * g   r  e   at
 * ⁠          / \
 * ⁠         a   t
 * 
 * 
 * To scramble the string, we may choose any non-leaf node and swap its two
 * children.
 * 
 * For example, if we choose the node "gr" and swap its two children, it
 * produces a scrambled string "rgeat".
 * 
 * 
 * ⁠   rgeat
 * ⁠  /    \
 * ⁠ rg    eat
 * ⁠/ \    /  \
 * r   g  e   at
 * ⁠          / \
 * ⁠         a   t
 * 
 * 
 * We say that "rgeat" is a scrambled string of "great".
 * 
 * Similarly, if we continue to swap the children of nodes "eat" and "at", it
 * produces a scrambled string "rgtae".
 * 
 * 
 * ⁠   rgtae
 * ⁠  /    \
 * ⁠ rg    tae
 * ⁠/ \    /  \
 * r   g  ta  e
 * ⁠      / \
 * ⁠     t   a
 * 
 * 
 * We say that "rgtae" is a scrambled string of "great".
 * 
 * Given two strings s1 and s2 of the same length, determine if s2 is a
 * scrambled string of s1.
 * 
 * Example 1:
 * 
 * 
 * Input: s1 = "great", s2 = "rgeat"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s1 = "abcde", s2 = "caebd"
 * Output: false
 * 
 */
#include<vector>
#include<string>
using namespace std;

// @lc code=start
class Solution {
private:
    unordered_map<string, unordered_map<string, bool>> dp;

public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;

        if (s1 > s2) return isScramble(s2, s1);
        if (dp.count(s1) && dp[s1].count(s2)) return dp[s1][s2];

        string tmp1 = s1, tmp2 = s2;
        sort(tmp1.begin(), tmp1.end());
        sort(tmp2.begin(), tmp2.end());
        if (tmp1 != tmp2) {
            dp[s1][s2] = false;
            return false;
        }
        
        int n = s1.size();
        for (int len=1; len<n; ++len) {
            string s11 = s1.substr(0, len);
            string s12 = s1.substr(len);

            string s21 = s2.substr(0, len);
            string s22 = s2.substr(len);
            if (isScramble(s11, s21) && isScramble(s12, s22)) {
                dp[s1][s2] = true;
                return true;
            }

            s21 = s2.substr(n-len);
            s22 = s2.substr(0, n-len);
            if (isScramble(s11, s21) && isScramble(s12, s22)) {
                dp[s1][s2] = true;
                return true;
            }
        }
        dp[s1][s2] = false;
        return false;
    }
};
// @lc code=end

