/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (34.01%)
 * Likes:    901
 * Dislikes: 2490
 * Total Accepted:    487.6K
 * Total Submissions: 1.4M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 * 
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "race a car"
 * Output: false
 * 
 * 
 */
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int l=0, r=s.size()-1;
        while (l<r) {
            while (l<r && !isalnum(s[l])) l++;
            while (l<r && !isalnum(s[r])) r--;
            if (tolower(s[l++]) != tolower(s[r--]))
                return false;
        }
        return true;
    }
};
// @lc code=end

