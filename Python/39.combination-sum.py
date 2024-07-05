#
# @lc app=leetcode id=39 lang=python
#
# [39] Combination Sum
#
# https://leetcode.com/problems/combination-sum/description/
#
# algorithms
# Medium (51.42%)
# Likes:    2601
# Dislikes: 79
# Total Accepted:    415.1K
# Total Submissions: 805.9K
# Testcase Example:  '[2,3,6,7]\n7'
#
# Given a set of candidate numbers (candidates) (without duplicates) and a
# target number (target), find all unique combinations in candidates where the
# candidate numbers sums to target.
# 
# The same repeated number may be chosen from candidates unlimited number of
# times.
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
# Input: candidates = [2,3,6,7], target = 7,
# A solution set is:
# [
# ⁠ [7],
# ⁠ [2,2,3]
# ]
# 
# 
# Example 2:
# 
# 
# Input: candidates = [2,3,5], target = 8,
# A solution set is:
# [
# [2,2,2,2],
# [2,3,3],
# [3,5]
# ]
# 
# 
#

# @lc code=start
class Solution(object):
    def combinationSum(self, candidates, target):
        candidates.sort()
        ans = []
        path = []
        self.dfs(candidates, target, 0, path, ans)
        return ans

    def dfs(self, nums, target, idx, path, ans):
        if target == 0:
            ans.append(path.copy())
            return
        for i in range(idx, len(nums)):
            if nums[i] > target:
                return
            path.append(nums[i])
            self.dfs(nums, target-nums[i], i, path, ans)
            path.pop()

        
# @lc code=end

sol = Solution()
candidates = [2, 3, 6, 7]
sol.combinationSum(candidates, 7)