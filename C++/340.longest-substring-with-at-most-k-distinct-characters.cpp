/*
 * @lc app=leetcode.cn id=340 lang=cpp
 *
 * [340] Longest Substring with At Most k Distinct Characters 
 * 
 * Given a string, find the length of the longest substring T that contains at most k distinct characters.
 * 
 * For example, Given s = “eceba” and k = 2,
 * 
 * T is "ece" which its length is 3.
 * 
 */
#include <string> 
#include <unordered_map>
#include <map>
#include <iostream>

using namespace std; 

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int ans = 0;
        unordered_map<char, int> last_idx;

        for (int left=0, right=0; right<s.size(); ++right) {
            last_idx[s[right]] = right;
            while (last_idx.size() > k) {
                if (last_idx[s[left]] == left)
                    last_idx.erase(s[left]);
                left ++;
            }
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};
// @lc code=end
