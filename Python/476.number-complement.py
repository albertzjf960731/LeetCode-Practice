#
# @lc app=leetcode id=476 lang=python
#
# [476] Number Complement
#
# https://leetcode.com/problems/number-complement/description/
#
# algorithms
# Easy (62.83%)
# Likes:    608
# Dislikes: 75
# Total Accepted:    118.1K
# Total Submissions: 187.8K
# Testcase Example:  '5'
#
# Given a positive integer, output its complement number. The complement
# strategy is to flip the bits of its binary representation.
# 
# Note:
# 
# The given integer is guaranteed to fit within the range of a 32-bit signed
# integer.
# You could assume no leading zero bit in the integer’s binary
# representation.
# 
# 
# 
# Example 1:
# 
# Input: 5
# Output: 2
# Explanation: The binary representation of 5 is 101 (no leading zero bits),
# and its complement is 010. So you need to output 2.
# 
# 
# 
# Example 2:
# 
# Input: 1
# Output: 0
# Explanation: The binary representation of 1 is 1 (no leading zero bits), and
# its complement is 0. So you need to output 0.
# 
# 
#

# @lc code=start
class Solution(object):
    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """

        # res = 0
        # count = 0
        # while num:
        #     res |= (num & 1 ^ 1) << count
        #     num >>= 1
        #     count += 1
        # return res 

        mask = 1 << 30
        while num & mask == 0:
            mask >>= 1
        mask = (mask << 1) -1
        return num ^ mask


# @lc code=end

sol = Solution()
print(sol.findComplement(5))