#
# @lc app=leetcode id=263 lang=python
#
# [263] Ugly Number
#
# https://leetcode.com/problems/ugly-number/description/
#
# algorithms
# Easy (41.02%)
# Likes:    299
# Dislikes: 511
# Total Accepted:    176.4K
# Total Submissions: 429.6K
# Testcase Example:  '6'
#
# Write a program to check whether a given number is an ugly number.
# 
# Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
# 
# Example 1:
# 
# 
# Input: 6
# Output: true
# Explanation: 6 = 2 × 3
# 
# Example 2:
# 
# 
# Input: 8
# Output: true
# Explanation: 8 = 2 × 2 × 2
# 
# 
# Example 3:
# 
# 
# Input: 14
# Output: false 
# Explanation: 14 is not ugly since it includes another prime factor 7.
# 
# 
# Note:
# 
# 
# 1 is typically treated as an ugly number.
# Input is within the 32-bit signed integer range: [−2^31,  2^31 − 1].
# 
#

# @lc code=start
class Solution(object):
    def isUgly(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num == 0:
            return False
        for divisor in [2, 3, 5]:
            while num % divisor == 0:
                num = num // divisor
        return num == 1
# @lc code=end

