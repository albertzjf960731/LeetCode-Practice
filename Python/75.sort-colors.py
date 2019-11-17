#
# @lc app=leetcode id=75 lang=python
#
# [75] Sort Colors
#
# https://leetcode.com/problems/sort-colors/description/
#
# algorithms
# Medium (43.64%)
# Likes:    2116
# Dislikes: 179
# Total Accepted:    373.9K
# Total Submissions: 855.9K
# Testcase Example:  '[2,0,2,1,1,0]'
#
# Given an array with n objects colored red, white or blue, sort them in-place
# so that objects of the same color are adjacent, with the colors in the order
# red, white and blue.
# 
# Here, we will use the integers 0, 1, and 2 to represent the color red, white,
# and blue respectively.
# 
# Note: You are not suppose to use the library's sort function for this
# problem.
# 
# Example:
# 
# 
# Input: [2,0,2,1,1,0]
# Output: [0,0,1,1,2,2]
# 
# Follow up:
# 
# 
# A rather straight forward solution is a two-pass algorithm using counting
# sort.
# First, iterate the array counting number of 0's, 1's, and 2's, then overwrite
# array with total number of 0's, then 1's and followed by 2's.
# Could you come up with a one-pass algorithm using only constant space?
# 
# 
#

# @lc code=start
class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        
        # num_zero, num_one, num_two = 0, 0, 0
        # for num in nums:
        #     if num == 0:
        #         num_zero += 1
        #     elif num == 1:
        #         num_one += 1
        #     elif num == 2:
        #         num_two += 1
        
        # for i in range(len(nums)):
        #     if num_zero > 0:
        #         nums[i] = 0
        #         num_zero -= 1
        #     elif num_one > 0:
        #         nums[i] = 1
        #         num_one -= 1
        #     elif num_two > 0:
        #         nums[i] = 2
        #         num_two -= 1
        
        zero, one, two = -1, -1, -1
        for num in nums:
            if num == 0:
                two += 1
                nums[two] = 2
                one += 1
                nums[one] = 1
                zero += 1
                nums[zero] = 0 
            if num == 1:
                two += 1
                nums[two] = 2
                one += 1 
                nums[one] = 1 
            if num == 2:
                two += 1
                nums[two] = 2
                   


# @lc code=end

sol = Solution()
nums = [2,0,2,1,1,0]
print(sol.sortColors(nums))