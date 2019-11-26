#
# @lc app=leetcode id=7 lang=python
#
# [7] Reverse Integer
#
# https://leetcode.com/problems/reverse-integer/description/
#
# algorithms
# Easy (25.52%)
# Likes:    2548
# Dislikes: 3969
# Total Accepted:    844.7K
# Total Submissions: 3.3M
# Testcase Example:  '123'
#
# Given a 32-bit signed integer, reverse digits of an integer.
# 
# Example 1:
# 
# 
# Input: 123
# Output: 321
# 
# 
# Example 2:
# 
# 
# Input: -123
# Output: -321
# 
# 
# Example 3:
# 
# 
# Input: 120
# Output: 21
# 
# 
# Note:
# Assume we are dealing with an environment which could only store integers
# within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
# of this problem, assume that your function returns 0 when the reversed
# integer overflows.
# 
#

# @lc code=start
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        # x_str = str(x)
        # neg = False
        # if x_str[0] == '-':
        #     x_str = x_str[1:]
        #     neg = True

        # x_str_rev = x_str[::-1]
        # x_rev = int(x_str_rev)
        # if neg:
        #     x_rev = -x_rev     
        # if x_rev > 2**31-1 or x_rev < -2**31:
        #     return 0  
        # return x_rev

        sign = 1 
        if x == 0:
            return 0
        elif x < 0:
            x = -x 
            sign = -1 
        
        x_rev = 0
        while x > 0:
            x_rev = x_rev * 10 + x % 10
            x = x // 10 
        
        x_rev *= sign
        if x_rev > 2**31-1 or x_rev < -2**31:
            return 0  
        return x_rev
        
# @lc code=end

