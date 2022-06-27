/*
 * @lc app=leetcode id=522 lang=cpp
 *
 * [522] Longest Uncommon Subsequence II
 *
 * https://leetcode.com/problems/longest-uncommon-subsequence-ii/description/
 *
 * algorithms
 * Medium (40.10%)
 * Likes:    388
 * Dislikes: 1096
 * Total Accepted:    43.8K
 * Total Submissions: 109K
 * Testcase Example:  '["aba","cdc","eae"]'
 *
 * Given an array of strings strs, return the length of the longest uncommon
 * subsequence between them. If the longest uncommon subsequence does not
 * exist, return -1.
 * 
 * An uncommon subsequence between an array of strings is a string that is a
 * subsequence of one string but not the others.
 * 
 * A subsequence of a string s is a string that can be obtained after deleting
 * any number of characters from s.
 * 
 * 
 * For example, "abc" is a subsequence of "aebdc" because you can delete the
 * underlined characters in "aebdc" to get "abc". Other subsequences of "aebdc"
 * include "aebdc", "aeb", and "" (empty string).
 * 
 * 
 * 
 * Example 1:
 * Input: strs = ["aba","cdc","eae"]
 * Output: 3
 * Example 2:
 * Input: strs = ["aaa","aaa","aa"]
 * Output: -1
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= strs.length <= 50
 * 1 <= strs[i].length <= 10
 * strs[i] consists of lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        // int ans = -1, n = strs.size();
        // for (int i=0; i<n; ++i) {
        //     int j = 0;
        //     for (; j<n; ++j) {
        //         if (i == j) continue;
        //         if (isSub(strs[i], strs[j])) break;
        //     }
        //     if (j==n) ans = max(ans, (int)strs[i].size());
        // }
        // return ans;

        sort(strs.begin(), strs.end(), [](string& a, string& b) {
            if (a.size() == b.size()) return a > b;
            return a.size() > b.size();
        });
                
        unordered_set<string> hset;
        int n = strs.size();
        for (int i=0; i<n; ++i) {
            if (i==n-1 || strs[i]!=strs[i+1]) {
                bool found = true;
                for (auto str: hset) {
                    if (isSub(strs[i], str)) {
                        found = false;
                        break;
                    }
                }
                if (found) return strs[i].size();
            }
            hset.insert(strs[i]);
        }
        return -1;
    }
    
    bool isSub(string& sub, string& str) {
        int i = 0;
        for (char ch: str) {
            if (ch == sub[i]) i++;
            if (i == sub.size()) break;
        }
        return i==sub.size();
    }
};
// @lc code=end

