/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 *
 * https://leetcode.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (38.95%)
 * Likes:    1091
 * Dislikes: 297
 * Total Accepted:    260.5K
 * Total Submissions: 668.5K
 * Testcase Example:  '"egg"\n"add"'
 *
 * Given two strings s and t, determine if they are isomorphic.
 * 
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * 
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character but a character may map to itself.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "egg", t = "add"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "foo", t = "bar"
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: s = "paper", t = "title"
 * Output: true
 * 
 * Note:
 * You may assume both s and t have the same length.
 * 
 */
#include<vector>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> s2i(256, 0), t2i(256, 0);
        for (int i=0; i<s.size(); i++) {
            if (s2i[s[i]] != t2i[t[i]])
                return false;
            s2i[s[i]] = i+1;
            t2i[t[i]] = i+1;
        }
        return true;
    }
};
// @lc code=end

