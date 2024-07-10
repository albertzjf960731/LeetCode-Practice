#
# @lc app=leetcode id=371 lang=python
#
# [371] Sum of Two Integers
#
# https://leetcode.com/problems/sum-of-two-integers/description/
#
# algorithms
# Easy (50.78%)
# Likes:    903
# Dislikes: 1704
# Total Accepted:    154.7K
# Total Submissions: 304.6K
# Testcase Example:  '1\n2'
#
# Calculate the sum of two integers a and b, but you are not allowed to use the
# operator + and -.
# 
# 
# Example 1:
# 
# 
# Input: a = 1, b = 2
# Output: 3
# 
# 
# 
# Example 2:
# 
# 
# Input: a = -2, b = 3
# Output: 1
# 
# 
# 
# 
#

# @lc code=start
class Solution(object):
    def getSum(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        # s = a ^ b 
        # carry = (a & b) << 1
        # a ^ b 表示没有考虑进位的情况下两数的和，(a & b) << 1 就是进位。


        # in Python, every integer is associated with its two's complement and its sign.
        # However, doing bit operation "& mask" loses the track of sign. 
        # Therefore, after the while loop, a is the two's complement of the final result as a 32-bit unsigned integer. 
        
        mask = 0xffffffff
        while b:
            a, b = (a ^ b) & mask, ((a & b) << 1) & mask
        
        # a is negative if the first bit is 1
        if a <= 0x7fffffff:
            return a
        else:
            return ~(a ^ mask)
 
        # return sum([a, b])

# @lc code=end

sol = Solution()
print(sol.getSum(-1, 1))