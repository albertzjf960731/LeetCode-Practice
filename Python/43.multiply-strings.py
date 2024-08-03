#
# @lc app=leetcode id=43 lang=python
#
# [43] Multiply Strings
#
# https://leetcode.com/problems/multiply-strings/description/
#
# algorithms
# Medium (31.90%)
# Likes:    1277
# Dislikes: 592
# Total Accepted:    236.9K
# Total Submissions: 741.5K
# Testcase Example:  '"2"\n"3"'
#
# Given two non-negative integers num1 and num2 represented as strings, return
# the product of num1 and num2, also represented as a string.
# 
# Example 1:
# 
# 
# Input: num1 = "2", num2 = "3"
# Output: "6"
# 
# Example 2:
# 
# 
# Input: num1 = "123", num2 = "456"
# Output: "56088"
# 
# 
# Note:
# 
# 
# The length of both num1 and num2 is < 110.
# Both num1 and num2 contain only digits 0-9.
# Both num1 and num2 do not contain any leading zero, except the number 0
# itself.
# You must not use any built-in BigInteger library or convert the inputs to
# integer directly.
# 
# 
#

# @lc code=start
class Solution(object):
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        vals = [0] * (len(num1) + len(num2))
        for i in range(len(num1)):
            for j in range(len(num2)):
                vals[i+j+1] += int(num1[i]) * int(num2[j])
        for k in range(len(num1)+len(num2)-1, 0, -1):
            vals[k-1] += vals[k] // 10
            vals[k] %= 10
        
        ans = ""
        for v in vals:
            if not ans and v == 0:
                continue
            ans += str(v)
        return "0" if not ans else ans
    
        return str(int(num1)*int(num2))


# @lc code=end

sol = Solution()
print(sol.multiply('0', '99'))