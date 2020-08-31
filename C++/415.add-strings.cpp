/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 */
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        
        int carry = 0;
        int i = num1.size()-1, j = num2.size()-1;
        while (i>=0 || j>=0 || carry) {
            int sum = (i>=0 ? num1[i]-'0' : 0) + (j>=0 ? num2[j]-'0' : 0) + carry;
            carry = sum / 10;
            ans = to_string(sum % 10) + ans;
            
            i--;
            j--;
        }
        return ans;
    }
};
// @lc code=end

