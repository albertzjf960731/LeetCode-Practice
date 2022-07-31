/*
 * @lc app=leetcode id=916 lang=cpp
 *
 * [916] Word Subsets
 *
 * https://leetcode.com/problems/word-subsets/description/
 *
 * algorithms
 * Medium (52.57%)
 * Likes:    1084
 * Dislikes: 139
 * Total Accepted:    55K
 * Total Submissions: 104.4K
 * Testcase Example:  '["amazon","apple","facebook","google","leetcode"]\n["e","o"]'
 *
 * You are given two string arrays words1 and words2.
 * 
 * A string b is a subset of string a if every letter in b occurs in a
 * including multiplicity.
 * 
 * 
 * For example, "wrr" is a subset of "warrior" but is not a subset of
 * "world".
 * 
 * 
 * A string a from words1 is universal if for every string b in words2, b is a
 * subset of a.
 * 
 * Return an array of all the universal strings in words1. You may return the
 * answer in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 =
 * ["e","o"]
 * Output: ["facebook","google","leetcode"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 =
 * ["l","e"]
 * Output: ["apple","google","leetcode"]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= words1.length, words2.length <= 10^4
 * 1 <= words1[i].length, words2[i].length <= 10
 * words1[i] and words2[i] consist only of lowercase English letters.
 * All the strings of words1 are unique.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> c_cnts(26, 0);
        for (string t : words2) {
            
            vector<int> tmp(26, 0);
            for (char c: t) tmp[c-'a'] += 1;
            for (int i=0; i<26; ++i) c_cnts[i] = max(c_cnts[i], tmp[i]);
        }       
        
        vector<string> ans;
        
        for (string s: words1) {
            vector<int> tmp(26, 0);
            for (char c: s) tmp[c-'a'] += 1;
            
            bool flag = true;
            for (int i=0; i<26; ++i) {
                if (tmp[i] < c_cnts[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) ans.push_back(s);
        }
        return ans;
    }
};
// @lc code=end

