#
# @lc app=leetcode id=693 lang=python
#
# [693] Binary Number with Alternating Bits
#
# https://leetcode.com/problems/binary-number-with-alternating-bits/description/
#
# algorithms
# Easy (58.42%)
# Likes:    339
# Dislikes: 73
# Total Accepted:    49.3K
# Total Submissions: 84.2K
# Testcase Example:  '5'
#
# Given a positive integer, check whether it has alternating bits: namely, if
# two adjacent bits will always have different values.
# 
# Example 1:
# 
# Input: 5
# Output: True
# Explanation:
# The binary representation of 5 is: 101
# 
# 
# 
# Example 2:
# 
# Input: 7
# Output: False
# Explanation:
# The binary representation of 7 is: 111.
# 
# 
# 
# Example 3:
# 
# Input: 11
# Output: False
# Explanation:
# The binary representation of 11 is: 1011.
# 
# 
# 
# Example 4:
# 
# Input: 10
# Output: True
# Explanation:
# The binary representation of 10 is: 1010.
# 
# 
#

# @lc code=start
class Solution(object):
    def hasAlternatingBits(self, n):
        """
        :type n: int
        :rtype: bool
        """

        # while n:
        #     cur = n & 1
        #     n >>= 1
        #     if n & 1 == cur :
        #         return False
        # return True       

        a = n ^ (n>>1)  
        return (a & (a+1)) == 0 


# @lc code=end

sol = Solution()
print(sol.hasAlternatingBits(4))