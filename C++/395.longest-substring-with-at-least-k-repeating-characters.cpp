/*
 * @lc app=leetcode id=395 lang=cpp
 *
 * [395] Longest Substring with At Least K Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/description/
 *
 * algorithms
 * Medium (40.21%)
 * Likes:    1122
 * Dislikes: 98
 * Total Accepted:    66.2K
 * Total Submissions: 164.4K
 * Testcase Example:  '"aaabb"\n3'
 *
 * 
 * Find the length of the longest substring T of a given string (consists of
 * lowercase letters only) such that every character in T appears no less than
 * k times.
 * 
 * 
 * Example 1:
 * 
 * Input:
 * s = "aaabb", k = 3
 * 
 * Output:
 * 3
 * 
 * The longest substring is "aaa", as 'a' is repeated 3 times.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * s = "ababbc", k = 2
 * 
 * Output:
 * 5
 * 
 * The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is
 * repeated 3 times.
 * 
 * 
 */
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans = 0;
        
        for (int cnt=1; cnt<=26; ++cnt) {
            
            int unique_cnt = 0;
            vector<int> char_cnts(26);
            for (int left=0, right=0; right<s.size(); right++) {
                bool valid = true;
                
                if (char_cnts[s[right]-'a']==0) 
                    ++unique_cnt;
                char_cnts[s[right]-'a'] ++;
                
                while (unique_cnt>cnt) {
                    char_cnts[s[left]-'a']--;
                    if (char_cnts[s[left]-'a'] == 0) 
                        --unique_cnt;
                    left ++;
                }
                
                for (int j=0; j<26; ++j) {
                    if (char_cnts[j]>0 && char_cnts[j]<k) 
                        valid = false;
                }
                if (valid) 
                    ans = max(ans, right-left+1);  
            }
        }    
        return ans;
    }
};
// @lc code=end

