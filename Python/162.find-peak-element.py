#
# @lc app=leetcode id=162 lang=python
#
# [162] Find Peak Element
#
# https://leetcode.com/problems/find-peak-element/description/
#
# algorithms
# Medium (42.07%)
# Likes:    1093
# Dislikes: 1586
# Total Accepted:    280.6K
# Total Submissions: 666.4K
# Testcase Example:  '[1,2,3,1]'
#
# A peak element is an element that is greater than its neighbors.
# 
# Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and
# return its index.
# 
# The array may contain multiple peaks, in that case return the index to any
# one of the peaks is fine.
# 
# You may imagine that nums[-1] = nums[n] = -∞.
# 
# Example 1:
# 
# 
# Input: nums = [1,2,3,1]
# Output: 2
# Explanation: 3 is a peak element and your function should return the index
# number 2.
# 
# Example 2:
# 
# 
# Input: nums = [1,2,1,3,5,6,4]
# Output: 1 or 5 
# Explanation: Your function can return either index number 1 where the peak
# element is 2, 
# or index number 5 where the peak element is 6.
# 
# 
# Note:
# 
# Your solution should be in logarithmic complexity.
# 
#

# @lc code=start
class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # if len(nums) == 1:
        #     return 0

        # for i in range(len(nums)):
        #     if i == 0 and i < len(nums)-1 and nums[i] > nums[i+1]:
        #         return i 
        #     if i == len(nums)- 1 and i > 0  and nums[i] > nums[i-1]:
        #         return i 
        #     if nums[i] > nums[i-1] and nums[i] > nums[i+1]:
        #         return i 

        # 假设只有一个 peak 就好了
        l, r = 0, len(nums)-1 
        while l < r:
            m = (l+r)//2
            if nums[m] > nums[m+1] and nums[m] > nums[m-1]:
                return m 
            if nums[m] < nums[m+1]:
                l = m+1
            else:
                r = m-1
        return l if nums[l] >= nums[r] else r 

# @lc code=end

sol = Solution()
nums = [1]
print(sol.findPeakElement(nums))