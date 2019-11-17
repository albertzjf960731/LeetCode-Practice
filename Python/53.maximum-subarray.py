#
# @lc app=leetcode id=53 lang=python
#
# [53] Maximum Subarray
#
# https://leetcode.com/problems/maximum-subarray/description/
#
# algorithms
# Easy (44.90%)
# Likes:    5385
# Dislikes: 221
# Total Accepted:    671.9K
# Total Submissions: 1.5M
# Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
#
# Given an integer array nums, find the contiguous subarray (containing at
# least one number) which has the largest sum and return its sum.
# 
# Example:
# 
# 
# Input: [-2,1,-3,4,-1,2,1,-5,4],
# Output: 6
# Explanation: [4,-1,2,1] has the largest sum = 6.
# 
# 
# Follow up:
# 
# If you have figured out the O(n) solution, try coding another solution using
# the divide and conquer approach, which is more subtle.
# 
#

# @lc code=start
class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # s, m = nums[0], nums[0]
        # for num in nums[1:]:
        #     s = max(num, s+num)
        #     m = max(m, s)
        # return m

        s, m = nums[0], nums[0]
        for num in nums[1:]:
            if s < 0:
                s = num
            else:
                s = s + num
            m = max(m, s)
        return m
# @lc code=end

