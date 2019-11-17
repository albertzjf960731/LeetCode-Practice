#
# @lc app=leetcode id=40 lang=python
#
# [40] Combination Sum II
#
# https://leetcode.com/problems/combination-sum-ii/description/
#
# algorithms
# Medium (44.11%)
# Likes:    1153
# Dislikes: 51
# Total Accepted:    260.6K
# Total Submissions: 590.9K
# Testcase Example:  '[10,1,2,7,6,1,5]\n8'
#
# Given a collection of candidate numbers (candidates) and a target number
# (target), find all unique combinations in candidates where the candidate
# numbers sums to target.
# 
# Each number in candidates may only be used once in the combination.
# 
# Note:
# 
# 
# All numbers (including target) will be positive integers.
# The solution set must not contain duplicate combinations.
# 
# 
# Example 1:
# 
# 
# Input: candidates = [10,1,2,7,6,1,5], target = 8,
# A solution set is:
# [
# ⁠ [1, 7],
# ⁠ [1, 2, 5],
# ⁠ [2, 6],
# ⁠ [1, 1, 6]
# ]
# 
# 
# Example 2:
# 
# 
# Input: candidates = [2,5,2,1,2], target = 5,
# A solution set is:
# [
# [1,2,2],
# [5]
# ]
# 
# 
#

# @lc code=start
class Solution(object):
    def combinationSum2(self, nums, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        res = []
        nums.sort()
        self.dfs(nums, target, -1, [], res)
        return res


    def dfs(self, nums, target, index, path, res):
        # if target < 0:
        #     return 
        if target == 0 and path not in res:
            res.append(path)
        else:
            for i in range(index+1, len(nums)):
                if target-nums[i] < 0:
                    break
                self.dfs(nums, target-nums[i], i, path + [nums[i]], res)

# @lc code=end

sol = Solution()
nums = [10,1,2,7,6,1,5]
target = 8
print(sol.combinationSum2(nums, target))