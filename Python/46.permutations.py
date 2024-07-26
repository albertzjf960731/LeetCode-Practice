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

    #     # === 回溯 ===
        path = []
        ans = []
        self.dfs(nums, path, ans)
        return ans
    
    def dfs(self, nums, path, ans):
        if len(path) == len(nums):
            ans.append(path.copy())
        
        for num in nums:
            if num not in path:
                path.append(num)
                self.dfs(nums, path, ans)
                path.pop()
    
        # res = [[]]
        # for i in range(len(nums)):
        #     temp = []
        #     for item in res:
        #         for j in range(len(item)+1):
        #             # 插入
        #             temp.append(item[:j] + [nums[i]] + item[j:])
        #     res = temp
        # return res
# @lc code=end

sol = Solution()
nums = [1,2,3]
sol.permute(nums)