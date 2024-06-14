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

        n = len(nums)
        maxProd, minProd = [1] * n, [1] * n
        maxProd[0] = minProd[0] = ans = nums[0]
        for i in range(1, n):
            if nums[i] > 0:
                maxProd[i] = max(nums[i], maxProd[i-1] * nums[i])
                minProd[i] = min(nums[i], minProd[i-1] * nums[i])
            elif nums[i] < 0:
                maxProd[i] = max(nums[i], minProd[i-1] * nums[i])
                minProd[i] = min(nums[i], maxProd[i-1] * nums[i])
            elif nums[i] == 0:
                maxProd[i] = 0
                minProd[i] = 0
            ans = max(ans, maxProd[i])
        return ans

# @lc code=end

