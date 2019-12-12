#
# @lc app=leetcode id=1186 lang=python
#
# [1186] Maximum Subarray Sum with One Deletion
#
# https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/description/
#
# algorithms
# Medium (34.69%)
# Likes:    267
# Dislikes: 10
# Total Accepted:    8.6K
# Total Submissions: 24.9K
# Testcase Example:  '[1,-2,0,3]'
#
# Given an array of integers, return the maximum sum for a non-empty subarray
# (contiguous elements) with at most one element deletion. In other words, you
# want to choose a subarray and optionally delete one element from it so that
# there is still at least one element left and the sum of the remaining
# elements is maximum possible.
# 
# Note that the subarray needs to be non-empty after deleting one element.
# 
# 
# Example 1:
# 
# 
# Input: arr = [1,-2,0,3]
# Output: 4
# Explanation: Because we can choose [1, -2, 0, 3] and drop -2, thus the
# subarray [1, 0, 3] becomes the maximum value.
# 
# Example 2:
# 
# 
# Input: arr = [1,-2,-2,3]
# Output: 3
# Explanation: We just choose [3] and it's the maximum sum.
# 
# 
# Example 3:
# 
# 
# Input: arr = [-1,-1,-1,-1]
# Output: -1
# Explanation: The final subarray needs to be non-empty. You can't choose [-1]
# and delete -1 from it, then get an empty subarray to make the sum equals to
# 0.
# 
# 
# 
# Constraints:
# 
# 
# 1 <= arr.length <= 10^5
# -10^4 <= arr[i] <= 10^4
# 
#

# @lc code=start
class Solution(object):
    def maximumSum(self, nums):
        """
        :type arr: List[int]
        :rtype: int
        """

        dp_end = [0 for _ in range(len(nums))]
        dp_end[0] = nums[0] 
        for i in range(1, len(nums)):   
            dp_end[i] = max(dp_end[i-1]+nums[i], nums[i])
        
        dp_start = [0 for _ in range(len(nums))]
        dp_start[-1] = nums[-1]
        for i in range(len(nums)-2, -1, -1):
            dp_start[i] = max(dp_start[i+1]+nums[i], nums[i])
        
        ans = max(dp_end)
        for i in range(1, len(nums)-1):
            ans = max(ans, dp_end[i-1]+dp_start[i+1])
        return ans


        dp = [0 for _ in range(len(nums))]
        dp_bak = [0 for _ in range(len(nums))]
        dp[0] = nums[0] 
        dp_bak[0] = nums[0]
        for i in range(1, len(nums)):   
            dp[i] = max(dp[i-1]+nums[i], nums[i])
            dp_bak[i] = max(dp_bak[i-1]+nums[i], nums[i])
            if i>1:
                dp[i] = max(dp[i], dp_bak[i-2]+nums[i])
        return max(dp)
        

# @lc code=end
sol = Solution()
nums = [8,-1,6,-7,-4,5,-4,7,-6]
print(sol.maximumSum(nums))
