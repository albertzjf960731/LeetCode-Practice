#
# @lc app=leetcode id=283 lang=python
#
# [283] Move Zeroes
#
# https://leetcode.com/problems/move-zeroes/description/
#
# algorithms
# Easy (55.49%)
# Likes:    2554
# Dislikes: 91
# Total Accepted:    562.1K
# Total Submissions: 1M
# Testcase Example:  '[0,1,0,3,12]'
#
# Given an array nums, write a function to move all 0's to the end of it while
# maintaining the relative order of the non-zero elements.
# 
# Example:
# 
# 
# Input: [0,1,0,3,12]
# Output: [1,3,12,0,0]
# 
# Note:
# 
# 
# You must do this in-place without making a copy of the array.
# Minimize the total number of operations.
# 
#

# @lc code=start
class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        # i, count = 0, 0
        # while i+count <= len(nums)-1:
        #     if nums[i] == 0:
        #         count += 1
        #     else:
        #         i += 1
        #     nums[i] = nums[i+count]

        # for j in range(i+count-1, len(nums)):
        #     nums[j] = 0

        # zero_count = 0
        # for i in range(len(nums)):
        #     if nums[i] != 0:
        #         nums[i], nums[zero_count] = nums[zero_count], nums[i]
        #         zero_count += 1

        idx = 0 
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[idx] = nums[i]
                idx += 1
        while idx < len(nums):
            nums[idx] = 0
            idx += 1
        
# @lc code=end

sol = Solution()
nums = [0,1,0,3,12]
sol.moveZeroes(nums)