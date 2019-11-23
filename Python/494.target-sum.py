#
# @lc app=leetcode id=494 lang=python
#
# [494] Target Sum
#
# https://leetcode.com/problems/target-sum/description/
#
# algorithms
# Medium (45.91%)
# Likes:    1729
# Dislikes: 82
# Total Accepted:    119.5K
# Total Submissions: 259.9K
# Testcase Example:  '[1,1,1,1,1]\n3'
#
# 
# You are given a list of non-negative integers, a1, a2, ..., an, and a target,
# S. Now you have 2 symbols + and -. For each integer, you should choose one
# from + and - as its new symbol.
# ⁠
# 
# Find out how many ways to assign symbols to make sum of integers equal to
# target S.  
# 
# 
# Example 1:
# 
# Input: nums is [1, 1, 1, 1, 1], S is 3. 
# Output: 5
# Explanation: 
# 
# -1+1+1+1+1 = 3
# +1-1+1+1+1 = 3
# +1+1-1+1+1 = 3
# +1+1+1-1+1 = 3
# +1+1+1+1-1 = 3
# 
# There are 5 ways to assign symbols to make the sum of nums be target 3.
# 
# 
# 
# Note:
# 
# The length of the given array is positive and will not exceed 20. 
# The sum of elements in the given array will not exceed 1000.
# Your output answer is guaranteed to be fitted in a 32-bit integer.
# 
# 
#

# @lc code=start
class Solution(object):
    def findTargetSumWays(self, nums, target):
        """
        :type nums: List[int]
        :type S: int
        :rtype: int
        """
        # sum(P) - sum(N) = target
        # sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)
        # 2 * sum(P) = target + sum(nums)

        s = sum(nums)
        if s < target or (s+target) % 2==1:
            return 0 

        target = (target+sum(nums)) // 2

        dp = [0 for _ in range(target+1)]
        dp[0] = 1

        for num in nums:
            for w in range(target, num-1, -1):
                dp[w] = dp[w] + dp[w-num]
        return dp[target]



        s = sum(nums)
        if s < target or (s+target) % 2==1:
            return 0 
        target = (target+sum(nums)) // 2

        self.ans = 0
        self.dfs(nums, 0, target)
        return self.ans
    
    def dfs(self, nums, index, target):
        if target == 0:
            self.ans += 1 
        for i in range(index,len(nums)):
            if target>=nums[i]:
                self.dfs(nums, i+1,target-nums[i])

        
# @lc code=end

sol = Solution()
nums = [1000]
target = -1000
print(sol.findTargetSumWays(nums, target))