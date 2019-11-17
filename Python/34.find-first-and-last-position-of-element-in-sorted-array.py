#
# @lc app=leetcode id=34 lang=python
#
# [34] Find First and Last Position of Element in Sorted Array
#
# https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
#
# algorithms
# Medium (34.48%)
# Likes:    2177
# Dislikes: 100
# Total Accepted:    372.8K
# Total Submissions: 1.1M
# Testcase Example:  '[5,7,7,8,8,10]\n8'
#
# Given an array of integers nums sorted in ascending order, find the starting
# and ending position of a given target value.
# 
# Your algorithm's runtime complexity must be in the order of O(log n).
# 
# If the target is not found in the array, return [-1, -1].
# 
# Example 1:
# 
# 
# Input: nums = [5,7,7,8,8,10], target = 8
# Output: [3,4]
# 
# Example 2:
# 
# 
# Input: nums = [5,7,7,8,8,10], target = 6
# Output: [-1,-1]
# 
#

# @lc code=start
class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """

        # start, end = -1, -1
        # for i in range(len(nums)):
        #     if nums[i] == target and start == -1:
        #         start = i      
        #     if nums[i] == target and start != -1:
        #         end = i
        # return [start, end]

        start, end = 0, len(nums)-1
        while start <= end:
            mid = (start + end) // 2

            if nums[mid] < target:
                start = mid + 1
            elif nums[mid] > target:
                end = mid - 1 
            else:
                start, end = mid, mid
                while start >= 0 and nums[start]== target:
                    start -= 1
                while end < len(nums) and nums[end] == target:
                    end += 1
                return [start+1, end-1]
        return [-1, -1]
# @lc code=end

sol = Solution()
nums = [5,7,7,8,8,10]
target = 6
print(sol.searchRange(nums, target))
