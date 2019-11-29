#
# @lc app=leetcode id=16 lang=python
#
# [16] 3Sum Closest
#
# https://leetcode.com/problems/3sum-closest/description/
#
# algorithms
# Medium (45.72%)
# Likes:    1428
# Dislikes: 104
# Total Accepted:    393.6K
# Total Submissions: 860.9K
# Testcase Example:  '[-1,2,1,-4]\n1'
#
# Given an array nums of n integers and an integer target, find three integers
# in nums such that the sum is closest to target. Return the sum of the three
# integers. You may assume that each input would have exactly one solution.
# 
# Example:
# 
# 
# Given array nums = [-1, 2, 1, -4], and target = 1.
# 
# The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
# 
# 
#

# @lc code=start
class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        # res = 0
        # d_min = float('inf')
        # for i in range(len(nums)-2):
        #     for j in range(i+1, len(nums)-1):
        #         for k in range(j+1, len(nums)):
        #             s = nums[i] + nums[j] + nums[k]
        #             d = abs(target - s)
        #             if d < d_min:
        #                 d_min = d 
        #                 res = s 
        # return res  

        nums.sort()
        s_min = nums[0] + nums[1] + nums[2]
        s_max = nums[-3] + nums[-2] + nums[-1]

        if target < s_min:
            return s_min 
        elif target > s_max:
            return s_max
        else: 
            ans = 0
            d_min = float('inf')
            for i in range(len(nums)-2):
                l, r = i+1, len(nums)-1 
                while l < r:
                    s = nums[i] + nums[l] + nums[r]
                    d = abs(s - target)

                    if d < d_min:
                        d_min = d
                        ans = s 

                    if s < target:
                        l += 1
                    elif s == target:
                        return s 
                    else:
                        r -= 1

        return ans

# @lc code=end

sol = Solution()
nums = [0, 2, 1, -4]
target = 1
sol.threeSumClosest(nums, target)