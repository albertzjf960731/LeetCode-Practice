#
# @lc app=leetcode id=504 lang=python
#
# [504] Base 7
#
# https://leetcode.com/problems/base-7/description/
#
# algorithms
# Easy (45.34%)
# Likes:    176
# Dislikes: 131
# Total Accepted:    47.2K
# Total Submissions: 104K
# Testcase Example:  '100'
#
# Given an integer, return its base 7 string representation.
# 
# Example 1:
# 
# Input: 100
# Output: "202"
# 
# 
# 
# Example 2:
# 
# Input: -7
# Output: "-10"
# 
# 
# 
# Note:
# The input will be in range of [-1e7, 1e7].
# 
#

# @lc code=start
class Solution(object):
    def convertToBase7(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num == 0:
            return '0'
        sign = '-' if num<0 else ''
        num = abs(num)

        res = ''
        divisor = 7
        while num:
            res = str(num % divisor) + res 
            num //= divisor
            # divisor <<=1         
        return sign + res 

# @lc code=end

sol = Solution()
num = -7
print(sol.convertToBase7(num))