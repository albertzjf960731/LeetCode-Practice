/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 *
 * https://leetcode.com/problems/is-subsequence/description/
 *
 * algorithms
 * Easy (49.23%)
 * Likes:    1705
 * Dislikes: 209
 * Total Accepted:    231.8K
 * Total Submissions: 470.9K
 * Testcase Example:  '"abc"\n"ahbgdc"'
 *
 * Given a string s and a string t, check if s is subsequence of t.
 * 
 * A subsequence of a string is a new string which is formed from the original
 * string by deleting some (can be none) of the characters without disturbing
 * the relative positions of the remaining characters. (ie, "ace" is a
 * subsequence of "abcde" while "aec" is not).
 * 
 * Follow up:
 * If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you
 * want to check one by one to see if T has its subsequence. In this scenario,
 * how would you change your code?
 * 
 * Credits:
 * Special thanks to @pbrother for adding this problem and creating all test
 * cases.
 * 
 * 
 * Example 1:
 * Input: s = "abc", t = "ahbgdc"
 * Output: true
 * Example 2:
 * Input: s = "axc", t = "ahbgdc"
 * Output: false
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= s.length <= 100
 * 0 <= t.length <= 10^4
 * Both strings consists only of lowercase characters.
 * 
 * 
 */
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while (i<s.size() && j<t.size()) {
            if (s[i]==t[j]) i++;
            j ++;
        }
        return i==s.size();

        unordered_map<char, vector<int>> char2pos;
        for (int i=0; i<t.size(); ++i) char2pos[t[i]].push_back(i);
        
        int pre = -1;
        for (char ch: s) {
            auto it = upper_bound(char2pos[ch].begin(), char2pos[ch].end(), pre);
            if (it == char2pos[ch].end()) return false;
            pre = *it;
        }
        return true;
    }
};
// @lc code=end

