/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 *
 * https://leetcode.com/problems/reverse-string-ii/description/
 *
 * algorithms
 * Easy (47.24%)
 * Likes:    345
 * Dislikes: 1010
 * Total Accepted:    77.1K
 * Total Submissions: 163.2K
 * Testcase Example:  '"abcdefg"\n2'
 *
 * 
 * Given a string and an integer k, you need to reverse the first k characters
 * for every 2k characters counting from the start of the string. If there are
 * less than k characters left, reverse all of them. If there are less than 2k
 * but greater than or equal to k characters, then reverse the first k
 * characters and left the other as original.
 * 
 * 
 * Example:
 * 
 * Input: s = "abcdefg", k = 2
 * Output: "bacdfeg"
 * 
 * 
 * 
 * Restrictions: 
 * 
 * ⁠The string consists of lower English letters only.
 * ⁠Length of the given string and k will in the range [1, 10000]
 * 
 */
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for (int left=0; left<s.size(); left+=2*k) {
            for (int i=left, j=min(left+k-1, n-1); i<j; i++, j--) {
                swap(s[i], s[j]);
            }
        }
        return s;
    }
};
// @lc code=end

string reverseLeftWords(string s, int n) {
    reverse(s.begin(), s.begin()+n);
    reverse(s.begin()+n, s.end());
    reverse(s.begin(), s.end());
    return s;
}