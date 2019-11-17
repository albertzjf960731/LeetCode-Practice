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
    #     res = ''
    #     for j in range(len(num2)-1, -1, -1):
    #         res = self.add(res, self.mul(num1, num2[j])+'0'*(len(num2)-1-j))
    #     res = res.lstrip('0')
    #     if not res:
    #         res = '0'
    #     return res

    # def mul(self, num1, n2):
    #     if num1=='0' or n2 == '0':
    #         return '0'
    #     res = ''
    #     carry = 0
    #     for n1 in num1[::-1]:
    #         p = int(n1) * int(n2) + carry
    #         carry = p // 10
    #         res = str(p%10) + res
    #     if carry:
    #         res = str(carry) + res
    #     return res

    # def add(self, num1, num2):
    #     res = ''
    #     i = len(num1)-1
    #     j = len(num2)-1
    #     carry = 0
    #     while i>=0 and j >=0:
    #         s = int(num1[i]) + int(num2[j]) + carry
    #         carry = s // 10
    #         res = str(s%10) + res
    #         i -= 1
    #         j -= 1
    #     while i >=0:
    #         s = int(num1[i]) + carry
    #         carry = s // 10
    #         res = str(s%10) + res
    #         i -= 1 
    #     while j >=0:
    #         s = int(num2[j]) + carry
    #         carry = s // 10
    #         res = str(s%10) + res
    #         j -= 1 
    #     if carry:
    #         res = str(carry) + res
    #     return res
    
        return str(int(num1)*int(num2))


# @lc code=end

sol = Solution()
print(sol.multiply('0', '99'))