#
# @lc app=leetcode id=405 lang=python
#
# [405] Convert a Number to Hexadecimal
#
# https://leetcode.com/problems/convert-a-number-to-hexadecimal/description/
#
# algorithms
# Easy (42.67%)
# Likes:    326
# Dislikes: 87
# Total Accepted:    55.1K
# Total Submissions: 128.8K
# Testcase Example:  '26'
#
# 
# Given an integer, write an algorithm to convert it to hexadecimal. For
# negative integer, two’s complement method is used.
# 
# 
# Note:
# 
# All letters in hexadecimal (a-f) must be in lowercase.
# The hexadecimal string must not contain extra leading 0s. If the number is
# zero, it is represented by a single zero character '0'; otherwise, the first
# character in the hexadecimal string will not be the zero character.
# The given number is guaranteed to fit within the range of a 32-bit signed
# integer.
# You must not use any method provided by the library which converts/formats
# the number to hex directly.
# 
# 
# 
# Example 1:
# 
# Input:
# 26
# 
# Output:
# "1a"
# 
# 
# 
# Example 2:
# 
# Input:
# -1
# 
# Output:
# "ffffffff"
# 
# 
#

# @lc code=start
class Solution(object):
    def toHex(self, num):
        """
        :type num: int
        :rtype: str
        """
        
        char = ['0', '1', '2', '3', 
                '4', '5', '6', '7',
                '8', '9', 'a', 'b',
                'c', 'd', 'e', 'f']

        if num == 0:
            return '0'
        elif num<0:
            num = 0xffffffff + 1 + num

        res = ''
        while num:
            res += char[num & 0b1111]
            num >>= 4
        return res[::-1]

# @lc code=end

sol = Solution()
num = -1   
print(sol.toHex(num))