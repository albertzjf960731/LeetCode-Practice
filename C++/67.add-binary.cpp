/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (41.47%)
 * Likes:    1278
 * Dislikes: 235
 * Total Accepted:    366.8K
 * Total Submissions: 883.4K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 * 
 * The input strings are both non-empty and contains only characters 1 or 0.
 * 
 * Example 1:
 * 
 * 
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * 
 * 
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * 
 */
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        
        int carry = 0;
        int i = a.size()-1, j = b.size() - 1;
        while (i>=0 || j>=0 || carry) {
            int sum = (i>=0 ? a[i]-'0' : 0) + (j>=0 ? b[j]-'0' : 0) + carry;
            carry = sum / 2;
            ans = to_string(sum % 2) + ans;
            
            i -= 1;
            j -= 1;
        }
        return ans;
    }
};
// @lc code=end

