#
# @lc app=leetcode id=665 lang=python
#
# [665] Non-decreasing Array
#
# https://leetcode.com/problems/non-decreasing-array/description/
#
# algorithms
# Easy (19.39%)
# Likes:    1307
# Dislikes: 302
# Total Accepted:    68.3K
# Total Submissions: 352.7K
# Testcase Example:  '[4,2,3]'
#
# 
# Given an array with n integers, your task is to check if it could become
# non-decreasing by modifying at most 1 element.
# 
# 
# 
# We define an array is non-decreasing if array[i]  holds for every i (1 
# 
# Example 1:
# 
# Input: [4,2,3]
# Output: True
# Explanation: You could modify the first 4 to 1 to get a non-decreasing
# array.
# 
# 
# 
# Example 2:
# 
# Input: [4,2,1]
# Output: False
# Explanation: You can't get a non-decreasing array by modify at most one
# element.
# 
# 
# 
# Note:
# The n belongs to [1, 10,000].
# 
#

# @lc code=start
class Solution(object):
    def checkPossibility(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        count = 1
        for i in range(len(nums)-1):
            if nums[i] <= nums[i+1]:
                continue

            # nums[i] > nums[i+1]
            if not count:
                return False

            if i-1>=0 and nums[i-1] > nums[i+1]:
                nums[i+1] = nums[i]
            else:
                nums[i] = nums[i+1]
            count = 0
        return True
# @lc code=end

sol = Solution()
# nums = [3,4,2,3]
nums = [4,2,3]
print(sol.checkPossibility(nums))