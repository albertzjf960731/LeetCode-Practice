/*
 * @lc app=leetcode id=1071 lang=cpp
 *
 * [1071] Greatest Common Divisor of Strings
 *
 * https://leetcode.com/problems/greatest-common-divisor-of-strings/description/
 *
 * algorithms
 * Easy (50.98%)
 * Likes:    1587
 * Dislikes: 315
 * Total Accepted:    87.2K
 * Total Submissions: 171.1K
 * Testcase Example:  '"ABCABC"\n"ABC"'
 *
 * For two strings s and t, we say "t divides s" if and only if s = t + ... + t
 * (i.e., t is concatenated with itself one or more times).
 * 
 * Given two strings str1 and str2, return the largest string x such that x
 * divides both str1 and str2.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: str1 = "ABCABC", str2 = "ABC"
 * Output: "ABC"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: str1 = "ABABAB", str2 = "ABAB"
 * Output: "AB"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: str1 = "LEET", str2 = "CODE"
 * Output: ""
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= str1.length, str2.length <= 1000
 * str1 and str2 consist of English uppercase letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1.size() == 0) return str2;
        if (str2.size() == 0) return str1; 
        if (str1.size() < str2.size()) swap(str1, str2);

        int n1 =  str1.size(), n2 = str2.size();
        for (int i=1; i<=n2; ++i) {
            if (str1[n1-i] != str2[n2-i]) return "";
            str1.pop_back();
        }
        return gcdOfStrings(str1, str2);


        if (str1.size() < str2.size()) return gcdOfStrings(str2, str1);
        if (str2.empty()) return str1;
        if (str1.substr(0, str2.size()) != str2) return "";
        return gcdOfStrings(str1.substr(str2.size()), str2);

        if (str1 + str2 != str2 + str1) return "";
        int gcdLength = gcd(str1.size(), str2.size());
        return str1.substr(0, gcdLength);
    }
};
// @lc code=end

