/*
 * @lc app=leetcode id=1417 lang=cpp
 *
 * [1417] Reformat The String
 *
 * https://leetcode.com/problems/reformat-the-string/description/
 *
 * algorithms
 * Easy (56.09%)
 * Likes:    424
 * Dislikes: 79
 * Total Accepted:    44.8K
 * Total Submissions: 79.9K
 * Testcase Example:  '"a0b1c2"'
 *
 * You are given an alphanumeric string s. (Alphanumeric string is a string
 * consisting of lowercase English letters and digits).
 * 
 * You have to find a permutation of the string where no letter is followed by
 * another letter and no digit is followed by another digit. That is, no two
 * adjacent characters have the same type.
 * 
 * Return the reformatted string or return an empty string if it is impossible
 * to reformat the string.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "a0b1c2"
 * Output: "0a1b2c"
 * Explanation: No two adjacent characters have the same type in "0a1b2c".
 * "a0b1c2", "0a1b2c", "0c2a1b" are also valid permutations.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "leetcode"
 * Output: ""
 * Explanation: "leetcode" has only characters so we cannot separate them by
 * digits.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "1229857369"
 * Output: ""
 * Explanation: "1229857369" has only digits so we cannot separate them by
 * characters.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 500
 * s consists of only lowercase English letters and/or digits.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string reformat(string s) {
        int alph_cnt = 0, num_cnt = 0;
        for (char c: s) {
            if (isdigit(c)) num_cnt += 1;
            else alph_cnt += 1;
        }
        
        if (abs(alph_cnt - num_cnt) > 1) return "";
                
        bool flag = num_cnt > alph_cnt;
        int i = 0, j = 1;
        while (i<s.size() && j<s.size()) {
            while (i<s.size() && isdigit(s[i]) == flag) i += 2;
            while (j<s.size() && isdigit(s[j]) != flag) j += 2;
            
            if (isdigit(s[i]) != flag && isdigit(s[j]) == flag) {
                swap(s[i], s[j]);
                i += 2;
                j += 2;
            }
        }
        return s;
    }
};
// @lc code=end

