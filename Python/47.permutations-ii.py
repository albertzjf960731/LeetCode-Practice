#
# @lc app=leetcode id=47 lang=python
#
# [47] Permutations II
#
# https://leetcode.com/problems/permutations-ii/description/
#
# algorithms
# Medium (42.82%)
# Likes:    1332
# Dislikes: 48
# Total Accepted:    284.5K
# Total Submissions: 664.4K
# Testcase Example:  '[1,1,2]'
#
# Given a collection of numbers that might contain duplicates, return all
# possible unique permutations.
# 
# Example:
# 
# 
# Input: [1,1,2]
# Output:
# [
# ⁠ [1,1,2],
# ⁠ [1,2,1],
# ⁠ [2,1,1]
# ]
# 
# 
#

# @lc code=start
class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        self.dfs(nums, res, [])
        return res
   
    def dfs(self, nums, res, path):
        # if len(path) == len(nums):
        #     res.append(path)
        #     return 
        if not nums and path not in res:
            res.append(path)

        for i in range(len(nums)):
            self.dfs(nums[:i]+nums[i+1:], res, path+[nums[i]])

# @lc code=end

