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
        nums.sort()
        
        path = []
        ans = []
        visited = [False] * len(nums)
        self.dfs(nums, path, visited, ans)
        return ans
    
    def dfs(self, nums, path, visited, ans):
        if len(path) == len(nums):
            ans.append(path.copy())
        
        for i in range(len(nums)):
            if visited[i]:
                continue
            # previous element is reset and not visited
            if i> 0 and nums[i] == nums[i-1] and not visited[i-1]:
                continue
            
            path.append(nums[i])
            visited[i] = True
            self.dfs(nums, path, visited, ans)
            visited[i] = False
            path.pop()

        # res = [[]]
        # for i in range(len(nums)):
        #     temp = []
        #     for item in res:
        #         for j in range(len(item)+1):
        #             # 插入
        #             temp.append(item[:j] + [nums[i]] + item[j:])
        #             if j<len(item) and nums[i]==item[j]: 
        #                 break
        #     res = temp
        # return res
        

# @lc code=end

