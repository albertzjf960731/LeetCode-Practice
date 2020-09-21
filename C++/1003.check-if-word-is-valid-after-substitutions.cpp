/*
 * @lc app=leetcode id=1003 lang=cpp
 *
 * [1003] Check If Word Is Valid After Substitutions
 *
 * https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/description/
 *
 * algorithms
 * Medium (55.36%)
 * Likes:    219
 * Dislikes: 348
 * Total Accepted:    23.2K
 * Total Submissions: 42.1K
 * Testcase Example:  '"aabcbc"'
 *
 * Given a string s, determine if it is valid.
 * 
 * A string s is valid if, starting with an empty string t = "", you can
 * transform t into s after performing the following operation any number of
 * times:
 * 
 * 
 * Insert string "abc" into any position in t. More formally, t becomes tleft +
 * "abc" + tright, where t == tleft + tright. Note that tleft and tright may be
 * empty.
 * 
 * 
 * Return true if s is a valid string, otherwise, return false.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "aabcbc"
 * Output: true
 * Explanation:
 * "" -> "abc" -> "aabcbc"
 * Thus, "aabcbc" is valid.
 * 
 * Example 2:
 * 
 * 
 * Input: s = "abcabcababcc"
 * Output: true
 * Explanation:
 * "" -> "abc" -> "abcabc" -> "abcabcabc" -> "abcabcababcc"
 * Thus, "abcabcababcc" is valid.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "abccba"
 * Output: false
 * Explanation: It is impossible to get "abccba" using the operation.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = "cababc"
 * Output: false
 * Explanation: It is impossible to get "cababc" using the operation.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 2 * 10^4
 * s consists of letters 'a', 'b', and 'c'
 * 
 * 
 */
#include<vector>
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isValid(string str) {
        vector<char> stack;
        for (char ch : str) {
            if (ch == 'c') {
                int n = stack.size();
                if (n<2 || stack[n-1]!='b' || stack[n-2]!='a') return false;
                stack.pop_back(), stack.pop_back();
            } else {
                stack.push_back(ch);
            }
        }
        return stack.size() == 0;
    }
};
// @lc code=end

