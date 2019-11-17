#
# @lc app=leetcode id=29 lang=python
#
# [29] Divide Two Integers
#
# https://leetcode.com/problems/divide-two-integers/description/
#
# algorithms
# Medium (16.17%)
# Likes:    832
# Dislikes: 4001
# Total Accepted:    225.5K
# Total Submissions: 1.4M
# Testcase Example:  '10\n3'
#
# Given two integers dividend and divisor, divide two integers without using
# multiplication, division and mod operator.
# 
# Return the quotient after dividing dividend by divisor.
# 
# The integer division should truncate toward zero.
# 
# Example 1:
# 
# 
# Input: dividend = 10, divisor = 3
# Output: 3
# 
# Example 2:
# 
# 
# Input: dividend = 7, divisor = -3
# Output: -2
# 
# Note:
# 
# 
# Both dividend and divisor will be 32-bit signed integers.
# The divisor will never be 0.
# Assume we are dealing with an environment which could only store integers
# within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
# of this problem, assume that your function returns 2^31 − 1 when the division
# result overflows.
# 
# 
#

# @lc code=start
class Solution(object):
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """

        # quotient = 0
        # remain = dividend
        # neg = -1 if dividend ^ divisor < 0 else 1

        # remain -= divisor * neg
        # while dividend ^ remain >= 0:
        #     quotient += neg
        #     remain -= divisor * neg
        
        # if dividend < 0:
        #     quotient += neg
        # return quotient

        positive = 1 if (dividend < 0) == (divisor < 0) else -1

        dividend, divisor = abs(dividend), abs(divisor)
        res = 0

        while dividend >= divisor:
            temp, i = divisor, 1
            while dividend  >= temp:
                dividend -= temp
                res += i 
                i <<= 1
                temp <<=1
        res *= positive
        return min(max(-2147483648, res), 2147483647)

# @lc code=end

sol = Solution()
print(sol.divide(1, 1))