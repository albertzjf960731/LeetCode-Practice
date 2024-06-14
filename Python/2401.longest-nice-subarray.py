#
# @lc app=leetcode id=2401 lang=python3
#
# [2401] Longest Nice Subarray
#
# https://leetcode.com/problems/longest-nice-subarray/description/
#
# algorithms
# Medium (50.87%)
# Likes:    1254
# Dislikes: 29
# Total Accepted:    31.2K
# Total Submissions: 61K
# Testcase Example:  '[1,3,8,48,10]'
#
# You are given an array nums consisting of positive integers.
# 
# We call a subarray of nums nice if the bitwise AND of every pair of elements
# that are in different positions in the subarray is equal to 0.
# 
# Return the length of the longest nice subarray.
# 
# A subarray is a contiguous part of an array.
# 
# Note that subarrays of length 1 are always considered nice.
# 
# 
# Example 1:
# 
# 
# Input: nums = [1,3,8,48,10]
# Output: 3
# Explanation: The longest nice subarray is [3,8,48]. This subarray satisfies
# the conditions:
# - 3 AND 8 = 0.
# - 3 AND 48 = 0.
# - 8 AND 48 = 0.
# It can be proven that no longer nice subarray can be obtained, so we return
# 3.
# 
# Example 2:
# 
# 
# Input: nums = [3,1,5,11,13]
# Output: 1
# Explanation: The length of the longest nice subarray is 1. Any subarray of
# length 1 can be chosen.
# 
# 
# 
# Constraints:
# 
# 
# 1 <= nums.length <= 10^5
# 1 <= nums[i] <= 10^9
# 
# 
#

# @lc code=start
class Solution:
    def longestNiceSubarray(self, nums: List[int]) -> int:
        left ,right = 0, 0
        val = 0
        ans = 1
        while right < len(nums):
            while (nums[right] & val) != 0:
                val = val ^ nums[left]
                left += 1
            val = val | nums[right]

            ans = max(ans, right - left + 1)
            right += 1
        return ans
        
# @lc code=end

