/*
 * @lc app=leetcode id=1239 lang=cpp
 *
 * [1239] Maximum Length of a Concatenated String with Unique Characters
 *
 * https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/
 *
 * algorithms
 * Medium (50.54%)
 * Likes:    3192
 * Dislikes: 225
 * Total Accepted:    164.1K
 * Total Submissions: 314.1K
 * Testcase Example:  '["un","iq","ue"]'
 *
 * You are given an array of strings arr. A string s is formed by the
 * concatenation of a subsequence of arr that has unique characters.
 * 
 * Return the maximum possible length of s.
 * 
 * A subsequence is an array that can be derived from another array by deleting
 * some or no elements without changing the order of the remaining elements.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = ["un","iq","ue"]
 * Output: 4
 * Explanation: All the valid concatenations are:
 * - ""
 * - "un"
 * - "iq"
 * - "ue"
 * - "uniq" ("un" + "iq")
 * - "ique" ("iq" + "ue")
 * Maximum length is 4.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = ["cha","r","act","ers"]
 * Output: 6
 * Explanation: Possible longest valid concatenations are "chaers" ("cha" +
 * "ers") and "acters" ("act" + "ers").
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
 * Output: 26
 * Explanation: The only string in arr has all 26 characters.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 16
 * 1 <= arr[i].length <= 26
 * arr[i] contains only lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> dp{bitset<26>()};
        
        int ans = 0;
        for (string word : arr) {
            bitset<26> cur;
            for (char c : word) cur.set(c - 'a');
            
            int n = cur.count();
            if (n < word.size()) continue;
            
            for (int i = dp.size()-1; i>=0; --i) {
                bitset<26> t = dp[i];
                if ((t & cur).any()) continue;
                
                dp.push_back(t | cur);
                ans = max(ans, (int)t.count()+n);
            }
        }
        return ans;

        return DFS(arr, "", 0);
    }
    
    int DFS(vector<string>& arr, string cur, int idx) {
        unordered_set<char> hset(cur.begin(), cur.end());
        if (hset.size() != cur.size()) return 0;
        
        int ans = cur.size();
        for (int i=idx; i<arr.size(); ++i) {
            ans = max(ans, DFS(arr, cur+arr[i], i+1));
        }
        return ans;
    }
};
// @lc code=end

