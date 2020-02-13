/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 *
 * https://leetcode.com/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (49.40%)
 * Likes:    755
 * Dislikes: 73
 * Total Accepted:    124K
 * Total Submissions: 250.9K
 * Testcase Example:  '"abccccdd"'
 *
 * Given a string which consists of lowercase or uppercase letters, find the
 * length of the longest palindromes that can be built with those letters.
 * 
 * This is case sensitive, for example "Aa" is not considered a palindrome
 * here.
 * 
 * Note:
 * Assume the length of given string will not exceed 1,010.
 * 
 * 
 * Example: 
 * 
 * Input:
 * "abccccdd"
 * 
 * Output:
 * 7
 * 
 * Explanation:
 * One longest palindrome that can be built is "dccaccd", whose length is 7.
 * 
 * 
 */
#include<string>
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> cnts;
        for (char ch: str) cnts[ch]++;
        
        int odd=0, ans=0;
        for (auto it=cnts.begin(); it!=cnts.end(); it++) {
            if (it->second%2==0)
                ans += it->second;
            else {
                ans += it->second-1;
                odd = 1;
            }
        }
        return ans + odd;
    }
};
// @lc code=end

