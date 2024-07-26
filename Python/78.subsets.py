#
# @lc app=leetcode id=78 lang=python
#
# [78] Subsets
#
# https://leetcode.com/problems/subsets/description/
#
# algorithms
# Medium (55.99%)
# Likes:    2520
# Dislikes: 61
# Total Accepted:    439.6K
# Total Submissions: 783.5K
# Testcase Example:  '[1,2,3]'
#
# Given a set of distinct integers, nums, return all possible subsets (the
# power set).
# 
# Note: The solution set must not contain duplicate subsets.
# 
# Example:
# 
# 
# Input: nums = [1,2,3]
# Output:
# [
# ⁠ [3],
# [1],
# [2],
# [1,2,3],
# [1,3],
# [2,3],
# [1,2],
# []
# ]
# 
#

# @lc code=start
class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
    #     results = []
    #     n = len(nums)
    #     for i in range(n+1):
    #         result = []
    #         self.combinations(nums, i, result, [], 0)
    #         results.extend(result)
    #     return results

    # def combinations(self, nums, k, result, temp, start):
    #     combs = [[]]
    #     if len(temp) == k:
    #         result.append(temp)
    #         return None
    #     for i in range(start, len(nums)):
    #         self.combinations(nums, k, result, temp+[nums[i]], i+1)


        # # 迭代
        # result = [[]]
        # for num in nums:
        #     result += [item+[num] for item in result]
        # return result


        # 递归
        path = []
        ans = []
        self.dfs(nums, 0, path, ans)
        return ans

    def dfs(self, nums, idx, path, ans):
        ans.append(path.copy())
        for i in range(idx, len(nums)):
            path.append(nums[i])
            self.dfs(nums, i+1, path, ans)
            path.pop()
        
        # # 位操作
        # result = []
        # for i in range(1<<len(nums)):
        #     temp = []
        #     for j in range(len(nums)):
        #         if i & (1<<j):
        #             temp.append(nums[j])
        #     result.append(temp)
        # return result

# @lc code=end

sol = Solution()
nums = [1,2,3]
print(sol.subsets(nums))