#
# @lc app=leetcode id=46 lang=python
#
# [46] Permutations
#
# https://leetcode.com/problems/permutations/description/
#
# algorithms
# Medium (58.27%)
# Likes:    2609
# Dislikes: 84
# Total Accepted:    458.9K
# Total Submissions: 787.5K
# Testcase Example:  '[1,2,3]'
#
# Given a collection of distinct integers, return all possible permutations.
# 
# Example:
# 
# 
# Input: [1,2,3]
# Output:
# [
# ⁠ [1,2,3],
# ⁠ [1,3,2],
# ⁠ [2,1,3],
# ⁠ [2,3,1],
# ⁠ [3,1,2],
# ⁠ [3,2,1]
# ]
# 
# 
#

# @lc code=start
class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """

        # === 回溯 ===
        res = []
        self.dfs(nums, res, [])
        return res
   
    def dfs(self, nums, res, path):
        if len(path) == len(nums):
            res.append(path)
            return 

        for i in range(len(nums)):
            if nums[i] not in path:
                self.dfs(nums, res, path+[nums[i]])


# @lc code=end

sol = Solution()
nums = [1,2,3]
sol.permute(nums)