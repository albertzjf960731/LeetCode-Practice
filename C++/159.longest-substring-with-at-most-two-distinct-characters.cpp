/*
 * @lc app=leetcode.cn id=159 lang=cpp
 *
 * [159] Longest Substring with At Most Two Distinct Characters 
 * 
 * Given a string s , find the length of the longest substring t  that contains at most 2 distinct characters.
 * 
 * Example 1:
 * 
 * Input: "eceba"
 * utput: 3
 * Explanation: tis "ece" which its length is 3.
 * Example 2:
 * 
 * Input: "ccaabbb" 
 * Output: 5
 * Explanation: tis "aabbb" which its length is 5.
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
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int ans = 0, left = 0;
        unordered_map<char, int> hash_map;

        for (int i=0; i<s.size(); ++i) {
            hash_map[s[i]] = i;
            while (hash_map.size()>2) {
                if (hash_map[s[left]]==left) 
                    hash_map.erase(s[left]);
                ++left;
            }
            ans = max(ans, i-left+1);
        }
        return ans;
    }
};
// @lc code=end
