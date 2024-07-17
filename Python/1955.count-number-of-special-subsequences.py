#
# @lc app=leetcode id=1955 lang=python3
#
# [1955] Count Number of Special Subsequences
#
# https://leetcode.com/problems/count-number-of-special-subsequences/description/
#
# algorithms
# Hard (50.99%)
# Likes:    516
# Dislikes: 9
# Total Accepted:    11.7K
# Total Submissions: 22.9K
# Testcase Example:  '[0,1,2,2]'
#
# A sequence is special if it consists of a positive number of 0s, followed by
# a positive number of 1s, then a positive number of 2s.
# 
# 
# For example, [0,1,2] and [0,0,1,1,1,2] are special.
# In contrast, [2,1,0], [1], and [0,1,2,0] are not special.
# 
# 
# Given an array nums (consisting of only integers 0, 1, and 2), return the
# number of different subsequences that are special. Since the answer may be
# very large, return it modulo 10^9 + 7.
# 
# A subsequence of an array is a sequence that can be derived from the array by
# deleting some or no elements without changing the order of the remaining
# elements. Two subsequences are different if the set of indices chosen are
# different.
# 
# 
# Example 1:
# 
# 
# Input: nums = [0,1,2,2]
# Output: 3
# Explanation: The special subsequences are bolded [0,1,2,2], [0,1,2,2], and
# [0,1,2,2].
# 
# 
# Example 2:
# 
# 
# Input: nums = [2,2,0,0]
# Output: 0
# Explanation: There are no special subsequences in [2,2,0,0].
# 
# 
# Example 3:
# 
# 
# Input: nums = [0,1,2,0,1,2]
# Output: 7
# Explanation: The special subsequences are bolded:
# - [0,1,2,0,1,2]
# - [0,1,2,0,1,2]
# - [0,1,2,0,1,2]
# - [0,1,2,0,1,2]
# - [0,1,2,0,1,2]
# - [0,1,2,0,1,2]
# - [0,1,2,0,1,2]
# 
# 
# 
# Constraints:
# 
# 
# 1 <= nums.length <= 10^5
# 0 <= nums[i] <= 2
# 
# 
#

# @lc code=start
class Solution:
    def countSpecialSubsequences(self, nums: List[int]) -> int:
        mod = 1e9 + 7
        dp = [[0] * 3 for _ in range(len(nums) + 1)]
        dp[0][0] = 1
        for i in range(nums):
            dp[i + 1][0] = dp[i][0]
            dp[i + 1][1] = dp[i][1]
            dp[i + 1][2] = dp[i][2]
            # double the dp[i-1][0] plus itself
            if nums[i] == 0:
                dp[i + 1][0] = (dp[i][0] * 2 + 1) % mod 
            # [use, not use] + [use, use] + [not use, use]
            elif nums[i] == 1:
                dp[i + 1][1] = (dp[i][0] + dp[i][1] * 2) % mod
            # [use, not use] + [use, use] + [not use, use
            else:
                dp[i + 1][2] = (dp[i][1] + dp[i][2] * 2) % mod
        return dp[-1][-1] % mod
# @lc code=end

