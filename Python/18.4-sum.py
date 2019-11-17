#
# @lc app=leetcode id=18 lang=python
#
# [18] 4Sum
#
# https://leetcode.com/problems/4sum/description/
#
# algorithms
# Medium (31.75%)
# Likes:    1330
# Dislikes: 265
# Total Accepted:    272.5K
# Total Submissions: 857.4K
# Testcase Example:  '[1,0,-1,0,-2,2]\n0'
#
# Given an array nums of n integers and an integer target, are there elements
# a, b, c, and d in nums such that a + b + c + d = target? Find all unique
# quadruplets in the array which gives the sum of target.
# 
# Note:
# 
# The solution set must not contain duplicate quadruplets.
# 
# Example:
# 
# 
# Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
# 
# A solution set is:
# [
# ⁠ [-1,  0, 0, 1],
# ⁠ [-2, -1, 1, 2],
# ⁠ [-2,  0, 0, 2]
# ]
# 
# 
#

# @lc code=start
class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
    #     nums.sort()
    #     result = []
    #     self.helper(nums, target, 4, [], result)
    #     return result

    # def helper(self, nums, target, n, path, result):
    #     if len(nums) < n or n < 2:
    #         return 
        
    #     if n == 2:
    #         l, r = 0, len(nums)-1
    #         while l<r:
    #             if nums[l] + nums[r] == target:
    #                 result.append(path + [nums[l], nums[r]])
    #                 l += 1
    #                 r -= 1
    #                 while l<r and nums[l] == nums[l-1]:
    #                     l += 1
    #                 while r>l and nums[r] == nums[r+1]:
    #                     r -= 1
    #             elif nums[l] + nums[r] < target:
    #                 l += 1
    #             else: 
    #                 r -= 1
    #     else:
    #         for i in range(0, len(nums)-n+1):
    #             if target < nums[i] * n or target > nums[-1] * n:
    #                 break    
    #             if i == 0 or (i > 0 and nums[i-1] != nums[i]):
    #                 self.helper(nums[i+1:], target-nums[i], n-1, path+[nums[i]], result)

    #     return


        nums.sort()
        result = []
        for i in range(len(nums)-3):
            if i == 0 or (i>0 and nums[i] != nums[i-1]):
                
                for j in range(i+1, len(nums)-2):
                    if (j == i + 1 or nums[j] != nums[j - 1]):

                        l = j+1
                        r = len(nums)-1
                        s = target-nums[i]-nums[j]

                        while l<r:
                            if nums[l] + nums[r] == s:
                                result.append([nums[i], nums[j], nums[l], nums[r]])
                                l += 1
                                r -= 1
                                while l<r and nums[l] == nums[l-1]:
                                    l += 1
                                while r>l and nums[r] == nums[r+1]:
                                    r -= 1
                            elif nums[l] + nums[r] < s:
                                l += 1
                            else: 
                                r -= 1
        return result
        
# @lc code=end

sol = Solution()
nums = [0,0,0,0]
target = 0
print(sol.fourSum(nums, target))
