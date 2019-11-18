#
# @lc app=leetcode id=645 lang=python
#
# [645] Set Mismatch
#
# https://leetcode.com/problems/set-mismatch/description/
#
# algorithms
# Easy (41.22%)
# Likes:    484
# Dislikes: 260
# Total Accepted:    57.4K
# Total Submissions: 139.2K
# Testcase Example:  '[1,2,2,4]'
#
# 
# The set S originally contains numbers from 1 to n. But unfortunately, due to
# the data error, one of the numbers in the set got duplicated to another
# number in the set, which results in repetition of one number and loss of
# another number. 
# 
# 
# 
# Given an array nums representing the data status of this set after the error.
# Your task is to firstly find the number occurs twice and then find the number
# that is missing. Return them in the form of an array.
# 
# 
# 
# Example 1:
# 
# Input: nums = [1,2,2,4]
# Output: [2,3]
# 
# 
# 
# Note:
# 
# The given array size will in the range [2, 10000].
# The given array's numbers won't have any order.
# 
# 
#

# @lc code=start
class Solution(object):
    def findErrorNums(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # n = len(nums)
        # s = n*(n+1)//2

        # miss = s - sum(set(nums))
        # dup = sum(nums) + miss - s
        # return [dup, miss]

        for i in range(len(nums)):
            # j = nums[i]-1
            # if nums[i] != i+1:
            # while i != nums[i]-1:
            while nums[i] != nums[nums[i]-1]:
                self.swap(nums, i, nums[i]-1)
            
        for i in range(len(nums)):
            if nums[i] != i+1:
                return [nums[i], i+1]

    def swap(self, nums, i, j):
        temp = nums[i]
        nums[i] = nums[j]
        nums[j] = temp


# @lc code=end

sol = Solution()
nums = [1,2,2,4]
print(sol.findErrorNums(nums))
