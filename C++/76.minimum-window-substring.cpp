/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (32.68%)
 * Likes:    3195
 * Dislikes: 233
 * Total Accepted:    308.6K
 * Total Submissions: 942.3K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 * 
 * Example:
 * 
 * 
 * Input: S = "ADOBECODEBANC", T = "ABC"
 * Output: "BANC"
 * 
 * 
 * Note:
 * 
 * 
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 * If there is such window, you are guaranteed that there will always be only
 * one unique minimum window in S.
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
    string minWindow(string s, string t) {
        unordered_map<char, int> cnts;
        for (char c: t) cnts[c] += 1;
        int cnt = t.size();
        
        int ans_left=0, ans_len = INT_MAX;
        for (int left=0, right=0; right<s.size(); ++right) {
            
            char c_r = s[right];
            if (cnts[c_r] > 0) cnt -= 1;
            cnts[c_r] -= 1;        
                
            while (cnt == 0) {
                int len = right - left + 1;
                if (len < ans_len) {
                    ans_len = len;
                    ans_left = left;
                }

                char c_l = s[left];
                if (cnts[c_l] == 0) cnt += 1;
                cnts[c_l] += 1;
                left += 1;
            }
        }
        return ans_len == INT_MAX ? "" : s.substr(ans_left, ans_len);
    }
};
// @lc code=end

