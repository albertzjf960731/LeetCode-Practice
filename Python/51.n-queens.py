#
# @lc app=leetcode id=51 lang=python
#
# [51] N-Queens
#
# https://leetcode.com/problems/n-queens/description/
#
# algorithms
# Hard (42.11%)
# Likes:    1235
# Dislikes: 57
# Total Accepted:    164.7K
# Total Submissions: 391.2K
# Testcase Example:  '4'
#
# The n-queens puzzle is the problem of placing n queens on an n×n chessboard
# such that no two queens attack each other.
# 
# 
# 
# Given an integer n, return all distinct solutions to the n-queens puzzle.
# 
# Each solution contains a distinct board configuration of the n-queens'
# placement, where 'Q' and '.' both indicate a queen and an empty space
# respectively.
# 
# Example:
# 
# 
# Input: 4
# Output: [
# ⁠[".Q..",  // Solution 1
# ⁠ "...Q",
# ⁠ "Q...",
# ⁠ "..Q."],
# 
# ⁠["..Q.",  // Solution 2
# ⁠ "Q...",
# ⁠ "...Q",
# ⁠ ".Q.."]
# ]
# Explanation: There exist two distinct solutions to the 4-queens puzzle as
# shown above.
# 
# 
#

# @lc code=start
class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """

        # def DFS(queens, xy_dif, xy_sum):
        #     p = len(queens)
        #     if p==n:
        #         result.append(queens)
        #         return None
        #     for q in range(n):
        #         if q not in queens and p-q not in xy_dif and p+q not in xy_sum: 
        #             DFS(queens+[q], xy_dif+[p-q], xy_sum+[p+q])  
        # result = []
        # DFS([],[],[])
        # return [ ["."*i + "Q" + "."*(n-i-1) for i in sol] for sol in result]

        self.result = []
        self.n = n
        self.dfs([], [], [])
        return [ ["."*i + "Q" + "."*(n-i-1) for i in sol] for sol in self.result]

    def dfs(self, queens, xy_dif, xy_sum):
        p = len(queens)
        if p == self.n:
            self.result.append(queens)   
            return None
        for q in range(self.n):
            if q not in queens and p-q not in xy_dif and p+q not in xy_sum:
                self.dfs(queens+[q], xy_dif+[p-q], xy_sum+[p+q])
                # queens = queens+[q]
                # self.dfs(queens, ...)
                # queens.pop()

# @lc code=end

sol = Solution()
sol.solveNQueens(4)