#
# @lc app=leetcode id=80 lang=python
#
# [80] Remove Duplicates from Sorted Array II
#
# https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/
#
# algorithms
# Medium (41.73%)
# Likes:    801
# Dislikes: 602
# Total Accepted:    226.6K
# Total Submissions: 542.5K
# Testcase Example:  '[1,1,1,2,2,3]'
#
# Given a sorted array nums, remove the duplicates in-place such that
# duplicates appeared at most twice and return the new length.
# 
# Do not allocate extra space for another array, you must do this by modifying
# the input array in-place with O(1) extra memory.
# 
# Example 1:
# 
# 
# Given nums = [1,1,1,2,2,3],
# 
# Your function should return length = 5, with the first five elements of nums
# being 1, 1, 2, 2 and 3 respectively.
# 
# It doesn't matter what you leave beyond the returned length.
# 
# Example 2:
# 
# 
# Given nums = [0,0,1,1,1,1,2,3,3],
# 
# Your function should return length = 7, with the first seven elements of nums
# being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.
# 
# It doesn't matter what values are set beyond the returned length.
# 
# 
# Clarification:
# 
# Confused why the returned value is an integer but your answer is an array?
# 
# Note that the input array is passed in by reference, which means modification
# to the input array will be known to the caller as well.
# 
# Internally you can think of this:
# 
# 
# // nums is passed in by reference. (i.e., without making a copy)
# int len = removeDuplicates(nums);
# 
# // any modification to nums in your function would be known by the caller.
# // using the length returned by your function, it prints the first len
# elements.
# for (int i = 0; i < len; i++) {
# print(nums[i]);
# }
# 
# 
#

# @lc code=start
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        # i, j = 0, 0
        # count = 0
        # while i < len(nums) and j < len(nums):
        #     while nums[j] == nums[j+1]:
        #         j += 1
        #     nums[j-count] = nums[j+1]
        #     count += 1
        #     i = j 
        #     j += count
        
        # return i

        # i = 0
        # count = 1
        # for j in range(1, len(nums)):
        #     if nums[j] != nums[i]:
        #         i += 1
        #         nums[i] = nums[j]
        #         count = 1
        #     else:
        #         if count < 2:
        #             i += 1
        #             nums[i] = nums[j]
        #             count += 1
        # return i + 1

        idx = 2
        for i in range(2, len(nums)):
            # if nums[i] == nums[idx-2], then nums[i] == nums[idx-1] == nums[idx-2]
            if nums[i] != nums[idx-2]:
                nums[idx] = nums[i]
                idx += 1
        return idx

# @lc code=end

sol = Solution()
nums = [1,1,1,2,2,3]
sol.removeDuplicates(nums)