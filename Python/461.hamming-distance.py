#
# @lc app=leetcode id=461 lang=python
#
# [461] Hamming Distance
#
# https://leetcode.com/problems/hamming-distance/description/
#
# algorithms
# Easy (70.76%)
# Likes:    1437
# Dislikes: 138
# Total Accepted:    267.5K
# Total Submissions: 377.9K
# Testcase Example:  '1\n4'
#
# The Hamming distance between two integers is the number of positions at which
# the corresponding bits are different.
# 
# Given two integers x and y, calculate the Hamming distance.
# 
# Note:
# 0 ≤ x, y < 2^31.
# 
# 
# Example:
# 
# Input: x = 1, y = 4
# 
# Output: 2
# 
# Explanation:
# 1   (0 0 0 1)
# 4   (0 1 0 0)
# ⁠      ↑   ↑
# 
# The above arrows point to positions where the corresponding bits are
# different.
# 
# 
#

# @lc code=start
class Solution(object):
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        # return bin(x ^ y).count('1')
        
        n = x ^ y
        ans = 0
        # while n&0xffffffff != 0:
        #     ans += 1
        #     n = n & (n-1) 

        while n:
            if n & 1 == 1:
                ans += 1
            n = n>>1
        return ans 
 

# @lc code=end

