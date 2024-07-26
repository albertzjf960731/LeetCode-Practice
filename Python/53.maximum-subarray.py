#
# @lc app=leetcode id=53 lang=python
#
# [53] Maximum Subarray
#
# https://leetcode.com/problems/maximum-subarray/description/
#
# algorithms
# Easy (44.90%)
# Likes:    5385
# Dislikes: 221
# Total Accepted:    671.9K
# Total Submissions: 1.5M
# Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
#
# Given an integer array nums, find the contiguous subarray (containing at
# least one number) which has the largest sum and return its sum.
# 
# Example:
# 
# 
# Input: [-2,1,-3,4,-1,2,1,-5,4],
# Output: 6
# Explanation: [4,-1,2,1] has the largest sum = 6.
# 
# 
# Follow up:
# 
# If you have figured out the O(n) solution, try coding another solution using
# the divide and conquer approach, which is more subtle.
# 
#

# @lc code=start
class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # s, m = nums[0], nums[0]
        # for num in nums[1:]:
        #     s = max(num, s+num)
        #     m = max(m, s)
        # return m

        dp = [0 for _ in range(len(nums))]
        dp[0] = nums[0] 
        ans = nums[0]
        for i in range(1, len(nums)):
            if dp[i-1] < 0:
                dp[i] = nums[i]
            else:
                dp[i] = dp[i-1] + nums[i]
            ans = max(ans, dp[i])
        return ans

        for i in range(1, len(nums)):
            dp[i] = max(dp[i-1] + nums[i], nums[i])
        return max(dp)

        pre, ans = nums[0], nums[0]
        for num in nums[1:]:
            if pre < 0:
                pre = num
            else:
                pre = pre + num
            ans = max(ans, pre)
        return ans
    
    def maxSumMatrix(self, matrix):
        if not matrix:
            return 0
        rows, cols = len(matrix), len(matrix[0])
        ans = float('-inf')
        for i in range(rows):
            dp = [0 for _ in range(cols)]
            for j in range(i, rows):
                for k in range(cols):
                    dp[k] += matrix[j][k]
                ans = max(ans, self.maxSubArray(dp))
        return ans

# @lc code=end

