#
# @lc app=leetcode id=15 lang=python
#
# [15] 3Sum
#
# https://leetcode.com/problems/3sum/description/
#
# algorithms
# Medium (25.04%)
# Likes:    4776
# Dislikes: 571
# Total Accepted:    684.4K
# Total Submissions: 2.7M
# Testcase Example:  '[-1,0,1,2,-1,-4]'
#
# Given an array nums of n integers, are there elements a, b, c in nums such
# that a + b + c = 0? Find all unique triplets in the array which gives the sum
# of zero.
# 
# Note:
# 
# The solution set must not contain duplicate triplets.
# 
# Example:
# 
# 
# Given array nums = [-1, 0, 1, 2, -1, -4],
# 
# A solution set is:
# [
# ⁠ [-1, 0, 1],
# ⁠ [-1, -1, 2]
# ]
# 
#

# @lc code=start
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        # nums = sorted(nums)

    #     trip_set = set()
    #     for i in range(len(nums)-1):
    #         for j in range(i+1, len(nums)):
    #             neg = -(nums[i] + nums[j])
    #             if self.index(nums, neg, j+1):
    #                 trip_set.add((nums[i], nums[j], neg))
           
    #     return trip_set
    # def index(self, nums, target, start):
    #     for i in range(start, len(nums)):
    #         if nums[i] == target:
    #             return i
    #     return False
       
        # nums.sort()
        # trip_set = set()

        # for i in range(len(nums)-2):
        #     target = - nums[i] 

        #     map = {}
        #     for j in range(i+1, len(nums)):
        #         if nums[j] not in map:
        #             map[target - nums[j]] = nums[j] 
        #         else:
        #             # return map[nums[j]], nums[j]
        #             trip_set.add((nums[i], map[nums[j]], nums[j]))
        # return trip_set

        nums.sort()
        result = []
        for i in range(len(nums)-2):
            if i == 0 or (i>0 and nums[i] != nums[i-1]):
                l = i+1
                r = len(nums)-1
                s = 0-nums[i]
                while l<r:
                    if nums[l] + nums[r] == s:
                        result.append([nums[i], nums[l], nums[r]])
                        while l<r and nums[l] == nums[l+1]:
                            l+=1
                        while l<r and nums[r] == nums[r-1]:
                            r-=1
                        l +=1
                        r -=1

                    elif nums[l] + nums[r] < s:
                        l+=1
                    else:
                        r-=1
        return result

# @lc code=end

sol = Solution()
nums = [-1,0,1,2,-1,-4]
print(sol.threeSum(nums))
