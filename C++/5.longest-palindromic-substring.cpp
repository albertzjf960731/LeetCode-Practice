/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

#include <string>

using namespace std; 

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        const int size_s = s.size();

        int max_s = 0, max_l = 0;
        for (int i=0; i<size_s;) {
            int start = i, end = i;
            
            // Skip duplicate characters.
            // don't need to check whether the palindrome is odd or even compared to many brute force solutions.
            while (end+1<size_s and s[end]==s[end+1]) end ++;
            i = end + 1;

            while (start-1>=0 and end+1<size_s and s[start-1]==s[end+1]) {
                start--;
                end++;
            }
            
            if (end-start+1 > max_l) {
                max_l = end-start+1;
                max_s = start;
            }
        }
        return s.substr(max_s, max_l);
    }
};
// @lc code=end

