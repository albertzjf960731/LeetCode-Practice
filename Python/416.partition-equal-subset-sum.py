#
# @lc app=leetcode id=416 lang=python
#
# [416] Partition Equal Subset Sum
#
# https://leetcode.com/problems/partition-equal-subset-sum/description/
#
# algorithms
# Medium (41.69%)
# Likes:    1660
# Dislikes: 51
# Total Accepted:    120.5K
# Total Submissions: 287.9K
# Testcase Example:  '[1,5,11,5]'
#
# Given a non-empty array containing only positive integers, find if the array
# can be partitioned into two subsets such that the sum of elements in both
# subsets is equal.
# 
# Note:
# 
# 
# Each of the array element will not exceed 100.
# The array size will not exceed 200.
# 
# 
# 
# 
# Example 1:
# 
# 
# Input: [1, 5, 11, 5]
# 
# Output: true
# 
# Explanation: The array can be partitioned as [1, 5, 5] and [11].
# 
# 
# 
# 
# Example 2:
# 
# 
# Input: [1, 2, 3, 5]
# 
# Output: false
# 
# Explanation: The array cannot be partitioned into equal sum subsets.
# 
# 
# 
# 
#

# @lc code=start
class Solution(object):
    def canPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        # One way is to treat problem as 0-1 knapsack that we need to pick some of the elements that sum up to target = sum(nums) / 2. 

        # dp[i][j] = dp[i-1][s] or (s >= nums[i] and dp[i-1][s-nums[i]])


        # target, n = sum(nums), len(nums)
        
        # if target & 1: 
        #     return False
        # target >>= 1
        
        # dp = [True] + [False]*target

        # for num in nums:
        #     for w in range(target, 0, -1):
        #         if (num<=w and dp[w-num]):
        #             dp[w] = True
        #     # dp = [dp[w] or (w >= num and dp[w-num]) for w in range(target+1)]

        #     if dp[target]: 
        #         return True
        # return False


        target, n = sum(nums), len(nums)
        if target & 1: 
            return False
        target >>= 1
        if max(nums)>target:
            return False

        nums.sort(reverse = True)
        return self.dfs(nums, 0, target)
    
    def dfs(self, nums, index, target):
        # if index==len(nums):
        #     return target==0
        if target == 0:
            return True
        for i in range(index,len(nums)):
            if target>=nums[i]:
                if self.dfs(nums, i+1,target-nums[i]):
                    return True
        return False




# @lc code=end

sol = Solution()
nums = [1, 5, 11, 5]
print(sol.canPartition(nums))