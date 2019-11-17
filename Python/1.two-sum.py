#
# @lc app=leetcode id=1 lang=python
#
# [1] Two Sum
#
# https://leetcode.com/problems/two-sum/description/
#
# algorithms
# Easy (44.68%)
# Likes:    12266
# Dislikes: 429
# Total Accepted:    2.2M
# Total Submissions: 5M
# Testcase Example:  '[2,7,11,15]\n9'
#
# Given an array of integers, return indices of the two numbers such that they
# add up to a specific target.
# 
# You may assume that each input would have exactly one solution, and you may
# not use the same element twice.
# 
# Example:
# 
# 
# Given nums = [2, 7, 11, 15], target = 9,
# 
# Because nums[0] + nums[1] = 2 + 7 = 9,
# return [0, 1].
# 
#

# @lc code=start
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        # # Brute Force
        # for i in range(len(nums)-1):
        #     for j in range(i+1, len(nums)):
        #         if nums[i] + nums[j] == target:
        #             return i, j

        # # Two-Pass Hash Table

        # hash_table = {}
        # for index, value in enumerate(nums):
        #     hash_table[value] = index
        # for i in range(len(nums)):
        #     sub = target - nums[i]
        #     if sub in hash_table:
        #         return [i, hash_table[sub]]

        # # One-Pass Hash Table
        # hash_table = {}
        # for index, value in enumerate(nums):
        #     sub = target - value
        #     if sub in hash_table:
        #         return [hash_table[sub], index]
        #     hash_table[value] = index

        map = {}
        for i in range(len(nums)):
            if nums[i] not in map:
                map[target - nums[i]] = i 
            else:
                return map[nums[i]], i 
        return -1, -1
# @lc code=end

