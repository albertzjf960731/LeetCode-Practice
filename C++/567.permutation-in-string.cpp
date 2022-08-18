/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 *
 * https://leetcode.com/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (40.03%)
 * Likes:    987
 * Dislikes: 52
 * Total Accepted:    74.8K
 * Total Submissions: 186.8K
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * Given two strings s1 and s2, write a function to return true if s2 contains
 * the permutation of s1. In other words, one of the first string's
 * permutations is the substring of the second string.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s1 = "ab" s2 = "eidbaooo"
 * Output: True
 * Explanation: s2 contains one permutation of s1 ("ba").
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:s1= "ab" s2 = "eidboaoo"
 * Output: False
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The input strings only contain lower case letters.
 * The length of both given strings is in range [1, 10,000].
 * 
 * 
 */
#include<string>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size()>s2.size()) 
            return false;
        
        // unordered_map<char, int> cnt1, cnt2;
        vector<int> cnt1(26, 0), cnt2(26, 0);
        
        for (int i=0; i<s1.size(); i++) {
            cnt1[s1[i]-'a'] ++;
            cnt2[s2[i]-'a'] ++;
        }
        if (cnt1==cnt2)
            return true;
        for (int i=s1.size(); i<s2.size(); i++) {
            cnt2[s2[i]-'a']++;
            cnt2[s2[i-s1.size()]-'a']--;
            if (cnt1==cnt2) 
                return true;
        }
        return false;

        if (s1.size() > s2.size()) return false;
        
        unordered_map<char, int> cnts;
        for (char c: s1) cnts[c] += 1;
        int cnt = s1.size();
        
        for (int left=0, right=0; right<s2.size(); ++right) {
            if (cnts[s2[right]] > 0) cnt -= 1;
            cnts[s2[right]] -= 1;
            
            if (right < s1.size()-1) continue;
            if (cnt == 0) return true;
            
            if (cnts[s2[left]] >= 0) cnt += 1;
            cnts[s2[left]] += 1;
            left += 1;
        }
        return false;
    }
};
// @lc code=end

