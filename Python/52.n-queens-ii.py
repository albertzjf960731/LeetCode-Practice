#
# @lc app=leetcode id=52 lang=python
#
# [52] N-Queens II
#
# https://leetcode.com/problems/n-queens-ii/description/
#
# algorithms
# Hard (54.29%)
# Likes:    342
# Dislikes: 129
# Total Accepted:    112.9K
# Total Submissions: 207.7K
# Testcase Example:  '4'
#
# The n-queens puzzle is the problem of placing n queens on an n×n chessboard
# such that no two queens attack each other.
# 
# 
# 
# Given an integer n, return the number of distinct solutions to the n-queens
# puzzle.
# 
# Example:
# 
# 
# Input: 4
# Output: 2
# Explanation: There are two distinct solutions to the 4-queens puzzle as shown
# below.
# [
# [".Q..",  // Solution 1
# "...Q",
# "Q...",
# "..Q."],
# 
# ["..Q.",  // Solution 2
# "Q...",
# "...Q",
# ".Q.."]
# ]
# 
# 
#

# @lc code=start
class Solution(object):
    def totalNQueens(self, n):
        """
        :type n: int
        :rtype: int
        """
    #     self.res = 0
    #     self.dfs([-1]*n, 0)
    #     return self.res
    
    # def dfs(self, nums, index):
    #     if index == len(nums):
    #         self.res += 1
    #         return 
    #     for i in range(len(nums)):
    #         nums[index] = i
    #         if self.valid(nums, index):
    #             self.dfs(nums, index+1)

    # def valid(self, nums, n):
    #     for i in range(n):
    #         if nums[i] == nums[n] or abs(nums[n]-nums[i]) == n-i:
    #             return False
    #     return True

        self.count = 0
        self.n = n
        self.dfs([], [], [])
        return self.count

    def dfs(self, queens, xy_dif, xy_sum):
        p = len(queens)
        if p == self.n:
            self.count += 1  
            return None
        for q in range(self.n):
            if q not in queens and p-q not in xy_dif and p+q not in xy_sum:
                self.dfs(queens+[q], xy_dif+[p-q], xy_sum+[p+q])
        
# @lc code=end

