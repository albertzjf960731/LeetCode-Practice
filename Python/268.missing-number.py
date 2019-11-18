#
# @lc app=leetcode id=268 lang=python
#
# [268] Missing Number
#
# https://leetcode.com/problems/missing-number/description/
#
# algorithms
# Easy (49.50%)
# Likes:    1159
# Dislikes: 1582
# Total Accepted:    341K
# Total Submissions: 687.6K
# Testcase Example:  '[3,0,1]'
#
# Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find
# the one that is missing from the array.
# 
# Example 1:
# 
# 
# Input: [3,0,1]
# Output: 2
# 
# 
# Example 2:
# 
# 
# Input: [9,6,4,2,3,5,7,0,1]
# Output: 8
# 
# 
# Note:
# Your algorithm should run in linear runtime complexity. Could you implement
# it using only constant extra space complexity?
#

# @lc code=start
class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # ans = 0
        # for i in range(len(nums)):
        #     ans = ans ^ i ^ nums[i]
        # return ans ^ len(nums)
        

        n = len(nums)
        ans = n*(n+1)/2 - sum(nums)
        return ans
        
# @lc code=end

