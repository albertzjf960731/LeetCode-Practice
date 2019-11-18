#
# @lc app=leetcode id=342 lang=python
#
# [342] Power of Four
#
# https://leetcode.com/problems/power-of-four/description/
#
# algorithms
# Easy (40.83%)
# Likes:    365
# Dislikes: 167
# Total Accepted:    128K
# Total Submissions: 313.2K
# Testcase Example:  '16'
#
# Given an integer (signed 32 bits), write a function to check whether it is a
# power of 4.
# 
# Example 1:
# 
# 
# Input: 16
# Output: true
# 
# 
# 
# Example 2:
# 
# 
# Input: 5
# Output: false
# 
# 
# Follow up: Could you solve it without loops/recursion?
#

# @lc code=start
class Solution(object):
    def isPowerOfFour(self, num):
        """
        :type num: int
        :rtype: bool
        """
        num_bit = bin(num)
        return num > 0 and num_bit.count('1') == 1 and num_bit.count('0') % 2 == 1

        (num & (num - 1)) == 0 and (num & 0b01010101010101010101010101010101) != 0

# @lc code=end

sol = Solution()
num = 16
print(sol.isPowerOfFour(num))