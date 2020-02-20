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
        int ans = 0, left = 0;
        unordered_map<char, int> hash_map;

        for (int i=0; i<s.size(); ++i) {
            hash_map[s[i]] = i;
            while (hash_map.size()>k) {
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
