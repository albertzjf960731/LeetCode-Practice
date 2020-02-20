/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 *
 * https://leetcode.com/problems/valid-palindrome-ii/description/
 *
 * algorithms
 * Easy (35.78%)
 * Likes:    1158
 * Dislikes: 84
 * Total Accepted:    123.5K
 * Total Submissions: 344.9K
 * Testcase Example:  '"aba"'
 *
 * 
 * Given a non-empty string s, you may delete at most one character.  Judge
 * whether you can make it a palindrome.
 * 
 * 
 * Example 1:
 * 
 * Input: "aba"
 * Output: True
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "abca"
 * Output: True
 * Explanation: You could delete the character 'c'.
 * 
 * 
 * 
 * Note:
 * 
 * The string will only contain lowercase characters a-z.
 * The maximum length of the string is 50000.
 * 
 * 
 */
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    bool validPalindrome(string s) {
        int l=0, r=s.size()-1;
        while (l<r) {
            if (s[l]!=s[r]) 
                return isValid(s, l+1, r) || isValid(s, l, r-1);
            l++;
            r--;
        }
        return true;
    }
    bool isValid(string &s, int l, int r) {
        while (l<r)
            if (s[l++] != s[r--])
                return false;
        return true;
    }
};
// @lc code=end

