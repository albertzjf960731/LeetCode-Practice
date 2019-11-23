#
# @lc app=leetcode id=152 lang=python
#
# [152] Maximum Product Subarray
#
# https://leetcode.com/problems/maximum-product-subarray/description/
#
# algorithms
# Medium (30.29%)
# Likes:    2731
# Dislikes: 120
# Total Accepted:    259.3K
# Total Submissions: 853.9K
# Testcase Example:  '[2,3,-2,4]'
#
# Given an integer array nums, find the contiguous subarray within an array
# (containing at least one number) which has the largest product.
# 
# Example 1:
# 
# 
# Input: [2,3,-2,4]
# Output: 6
# Explanation: [2,3] has the largest product 6.
# 
# 
# Example 2:
# 
# 
# Input: [-2,0,-1]
# Output: 0
# Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
# 
#

# @lc code=start
class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        # # 因为存在负数，所以需要同时考虑最大乘积和最小乘积
        # dp_max = [0 for _ in range(len(nums))]
        # dp_min = [0 for _ in range(len(nums))]

        # dp_max[0] = dp_min[0] = ans = nums[0]   

        # for i in range(1, len(nums)):
        #     if nums[i] < 0:
        #         dp_max[i] = max(dp_min[i-1]*nums[i], nums[i])
        #         dp_min[i] = min(dp_max[i-1]*nums[i], nums[i])
        #     else:
        #         dp_max[i] = max(dp_max[i-1]*nums[i], nums[i])
        #         dp_min[i] = min(dp_min[i-1]*nums[i], nums[i])
        #     ans = max(ans, dp_max[i])
        # return ans 


        dp_max = dp_min = ans = nums[0]   

        for i in range(1, len(nums)):
            if nums[i] < 0:
                tmp = dp_max
                dp_max = max(dp_min*nums[i], nums[i])
                dp_min = min(tmp*nums[i], nums[i])
            else:
                dp_max = max(dp_max*nums[i], nums[i])
                dp_min = min(dp_min*nums[i], nums[i])
            ans = max(ans, dp_max)
        return ans 





        
# @lc code=end

