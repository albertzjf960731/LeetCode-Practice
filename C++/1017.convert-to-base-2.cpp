/*
 * @lc app=leetcode id=1017 lang=cpp
 *
 * [1017] Convert to Base -2
 *
 * https://leetcode.com/problems/convert-to-base-2/description/
 *
 * algorithms
 * Medium (60.84%)
 * Likes:    454
 * Dislikes: 264
 * Total Accepted:    22.7K
 * Total Submissions: 37.2K
 * Testcase Example:  '2'
 *
 * Given an integer n, return a binary string representing its representation
 * in base -2.
 * 
 * Note that the returned string should not have leading zeros unless the
 * string is "0".
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 2
 * Output: "110"
 * Explantion: (-2)^2 + (-2)^1 = 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 3
 * Output: "111"
 * Explantion: (-2)^2 + (-2)^1 + (-2)^0 = 3
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 4
 * Output: "100"
 * Explantion: (-2)^2 = 4
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= n <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string baseNeg2(int n) {
        if (n==0) return "0";
        
        vector<int> s;
        while (n) {
            s.push_back(n%2);
            n /= 2;
        }

        for (int i=0, carry=0; i<s.size()||carry==1; ++i) {            
            if (i==s.size()) s.push_back(0);

            int sum = s[i] + carry;
            carry = sum / 2;
            s[i] = sum % 2;
                        
            if (i%2==1 && s[i]==1) carry += 1;   
        }

        string ans = "";
        for (int i=s.size()-1; i>=0; --i) 
            ans.push_back(s[i]+'0');
        return ans;
    }
};
// @lc code=end

