#
# @lc app=leetcode id=77 lang=python
#
# [77] Combinations
#
# https://leetcode.com/problems/combinations/description/
#
# algorithms
# Medium (50.50%)
# Likes:    1007
# Dislikes: 58
# Total Accepted:    237.6K
# Total Submissions: 469.7K
# Testcase Example:  '4\n2'
#
# Given two integers n and k, return all possible combinations of k numbers out
# of 1 ... n.
# 
# Example:
# 
# 
# Input: n = 4, k = 2
# Output:
# [
# ⁠ [2,4],
# ⁠ [3,4],
# ⁠ [2,3],
# ⁠ [1,2],
# ⁠ [1,3],
# ⁠ [1,4],
# ]
# 
# 
#

# @lc code=start
class Solution(object):
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """

        # from itertools import combinations
        # return list(combinations(range(1, n+1), k))

        # if k == 0:
        #     return [[]]
        # return [pre + [i] 
        #         for i in range(k, n+1) 
        #         for pre in self.combine(i-1, k-1)]

        # 有序，在前加[i]
        # combs = [[]]
        # for _ in range(k):
        #     combs = [[i] + c 
        #             for c in combs 
        #                 for i in range(1, c[0] if c else n+1)]
        #     # print(combs)
        # return combs
        
    #     self.result = []
    #     self.n = n
    #     self.k = k
    #     self.helper([], 1)
    #     return self.result

    # def helper(self, temp, start):
    #     if len(temp) == self.k:
    #         self.result.append(temp)
    #         return None
    #     for i in range(start, self.n+1):
    #         self.helper(temp+[i], i+1)

        


# @lc code=end

sol = Solution()
print(sol.combine(4, 2))