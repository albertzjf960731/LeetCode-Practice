#
# @lc app=leetcode id=136 lang=python
#
# [136] Single Number
#
# https://leetcode.com/problems/single-number/description/
#
# algorithms
# Easy (61.87%)
# Likes:    2990
# Dislikes: 116
# Total Accepted:    558.1K
# Total Submissions: 901.6K
# Testcase Example:  '[2,2,1]'
#
# Given a non-empty array of integers, every element appears twice except for
# one. Find that single one.
# 
# Note:
# 
# Your algorithm should have a linear runtime complexity. Could you implement
# it without using extra memory?
# 
# Example 1:
# 
# 
# Input: [2,2,1]
# Output: 1
# 
# 
# Example 2:
# 
# 
# Input: [4,1,2,1,2]
# Output: 4
# 
# 
#

# @lc code=start
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # s = set()
        # for num in nums:
        #     if num in s:
        #         s.remove(num)
        #     else:
        #         s.add(num)
        # return list(s)[0]
        
        # ans = 0
        # for num in nums:
        #     ans = ans ^ num
        # return ans

        return sum(set(nums)) * 2 - sum(nums) 

        
# @lc code=end

