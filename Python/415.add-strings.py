#
# @lc app=leetcode id=415 lang=python
#
# [415] Add Strings
#
# https://leetcode.com/problems/add-strings/description/
#
# algorithms
# Easy (45.05%)
# Likes:    553
# Dislikes: 185
# Total Accepted:    125K
# Total Submissions: 276.3K
# Testcase Example:  '"0"\n"0"'
#
# Given two non-negative integers num1 and num2 represented as string, return
# the sum of num1 and num2.
# 
# Note:
# 
# The length of both num1 and num2 is < 5100.
# Both num1 and num2 contains only digits 0-9.
# Both num1 and num2 does not contain any leading zero.
# You must not use any built-in BigInteger library or convert the inputs to
# integer directly.
# 
# 
#

# @lc code=start
class Solution(object):
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """

        res = ''
        i = len(num1)-1
        j = len(num2)-1
        carry = 0
        while i>=0 or j>=0 or carry:
            s = carry 
            if i >= 0:
                s += (ord(num1[i]) -48)
            if j >= 0:
                s += (ord(num2[j]) -48)

            carry = s // 10
            res = chr((s%10)+48) + res

            i -= 1
            j -= 1
        return res
    
# @lc code=end

sol = Solution()
num1, num2 = '0', '0'
print(sol.addStrings(num1, num2))