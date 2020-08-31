/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (32.15%)
 * Likes:    1323
 * Dislikes: 621
 * Total Accepted:    243.1K
 * Total Submissions: 755.7K
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 * 
 * Example 1:
 * 
 * 
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * 
 * Example 2:
 * 
 * 
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 * 
 * 
 * Note:
 * 
 * 
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contain only digits 0-9.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */
#include<vector>
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    string multiply(string nums1, string nums2) {
        vector<int> val(nums1.size()+nums2.size(), 0);
        for (int i=nums1.size()-1; i>=0; --i) {
            for (int j=nums2.size()-1; j>=0; --j) {
                int mul = (nums1[i]-'0') * (nums2[j]-'0');
                int sum = mul + val[i+j+1];
                val[i+j+1] = sum % 10;
                val[i+j] += sum / 10;
            }
        }
        
        string res = "";
        for (int num: val) {
            if (res.empty() && num==0) continue;
            res.push_back(num + '0');
        }
        return res.empty() ? "0" : res;
    }
};
// @lc code=end
