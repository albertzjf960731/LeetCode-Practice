#
# @lc app=leetcode id=713 lang=python3
#
# [713] Subarray Product Less Than K
#
# https://leetcode.com/problems/subarray-product-less-than-k/description/
#
# algorithms
# Medium (51.37%)
# Likes:    6827
# Dislikes: 216
# Total Accepted:    414.7K
# Total Submissions: 804.3K
# Testcase Example:  '[10,5,2,6]\n100'
#
# Given an array of integers nums and an integer k, return the number of
# contiguous subarrays where the product of all the elements in the subarray is
# strictly less than k.
# 
# 
# Example 1:
# 
# 
# Input: nums = [10,5,2,6], k = 100
# Output: 8
# Explanation: The 8 subarrays that have product less than 100 are:
# [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
# Note that [10, 5, 2] is not included as the product of 100 is not strictly
# less than k.
# 
# 
# Example 2:
# 
# 
# Input: nums = [1,2,3], k = 0
# Output: 0
# 
# 
# 
# Constraints:
# 
# 
# 1 <= nums.length <= 3 * 10^4
# 1 <= nums[i] <= 1000
# 0 <= k <= 10^6
# 
# 
#

# @lc code=start
class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        left, right = 0, 0
        product = 1
        count = 0
        while right < len(nums):
            product *= nums[right]
            while left <= right and product >= k:
                product //= nums[left]
                left += 1
            count += right - left + 1
            right += 1
        return count
# @lc code=end

