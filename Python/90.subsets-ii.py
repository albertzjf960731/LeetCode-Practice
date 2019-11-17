#
# @lc app=leetcode id=90 lang=python
#
# [90] Subsets II
#
# https://leetcode.com/problems/subsets-ii/description/
#
# algorithms
# Medium (44.18%)
# Likes:    1150
# Dislikes: 56
# Total Accepted:    232.6K
# Total Submissions: 525.6K
# Testcase Example:  '[1,2,2]'
#
# Given a collection of integers that might contain duplicates, nums, return
# all possible subsets (the power set).
# 
# Note: The solution set must not contain duplicate subsets.
# 
# Example:
# 
# 
# Input: [1,2,2]
# Output:
# [
# ⁠ [2],
# ⁠ [1],
# ⁠ [1,2,2],
# ⁠ [2,2],
# ⁠ [1,2],
# ⁠ []
# ]
# 
# 
#

# @lc code=start
class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """


        # # 迭代
        # result = [[]]
        # nums.sort()
        # for num in nums:
        #     temp = result.copy()
        #     for item in temp:
        #         if item + [num] not in result:
        #             result += [item+[num]]
        # return result


        # 递归
    #     nums.sort()
    #     result = []
    #     self.dfs(nums, 0, [], result)
    #     return result

    # def dfs(self, nums, index, path, result):
    #     if path not in result:
    #         result.append(path)
    #     for i in range(index, len(nums)):
    #         self.dfs(nums, i+1, path+[nums[i]], result)

        # 位操作
        nums.sort()
        result = []
        for i in range(1<<len(nums)):
            temp = []
            for j in range(len(nums)):
                if i & 1 << j:
                    temp.append(nums[j])
            if temp not in result:
                result.append(temp)
        return result

# @lc code=end

sol = Solution()
nums = [1,2,2]
print(sol.subsetsWithDup(nums))