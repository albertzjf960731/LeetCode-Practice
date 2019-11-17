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
    # def __init__(self):
    #     self.res = []

    # def combinationSum(self, candidates, target):
    #     """
    #     :type candidates: List[int]
    #     :type target: int
    #     :rtype: List[List[int]]
    #     """
    #     # res = []

    #     # for i in range(len(candidates)):
    #     #     if candidates[i] == target:
    #     #         res.append([candidates[i]])
            
    #     #     for j in range(i, len(candidates)):
    #     #         if candidates[i] + candidates[j] == target:
    #     #             res.append([candidates[i], candidates[j]])
                
    #     #         for k in range(j, len(candidates)):
    #     #             if candidates[i] + candidates[j] + candidates[k] == target:
    #     #                 res.append([candidates[i], candidates[j], candidates[k]])
        
    #     # return res
    #     candidates.sort()
    #     self.backtrack([], candidates, target, 0)
    #     return self.res   

    # def backtrack(self,temp_res, candidates, remain, start):
    #     # if remain < 0:
    #     #     return 
    #     if remain == 0:
    #         self.res.append(temp_res.copy())
    #     else:
    #         for i in range(start, len(candidates)):
    #             if remain-candidates[i] < 0:
    #                 break
                
    #             temp_res.append(candidates[i])
    #             self.backtrack(temp_res, candidates, remain-candidates[i], i)
    #             temp_res.pop()
    def combinationSum(self, candidates, target):
        res = []
        candidates.sort()
        self.dfs(candidates, target, 0, [], res)    
        return res

    def dfs(self, nums, target, index, path, res):
        if target < 0:
            return 
        elif target == 0:
            res.append(path)
        else:
            for i in range(index, len(nums)):
                self.dfs(nums, target-nums[i], i, path + [nums[i]], res)

        
# @lc code=end

sol = Solution()
candidates = [2, 3, 6, 7]
sol.combinationSum(candidates, 7)