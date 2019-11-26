#
# @lc app=leetcode id=1020 lang=python
#
# [1020] Number of Enclaves
#
# https://leetcode.com/problems/number-of-enclaves/description/
#
# algorithms
# Medium (54.88%)
# Likes:    140
# Dislikes: 16
# Total Accepted:    10.9K
# Total Submissions: 19.7K
# Testcase Example:  '[[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]'
#
# Given a 2D array A, each cell is 0 (representing sea) or 1 (representing
# land)
# 
# A move consists of walking from one land square 4-directionally to another
# land square, or off the boundary of the grid.
# 
# Return the number of land squares in the grid for which we cannot walk off
# the boundary of the grid in any number of moves.
# 
# 
# 
# Example 1:
# 
# 
# Input: [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
# Output: 3
# Explanation: 
# There are three 1s that are enclosed by 0s, and one 1 that isn't enclosed
# because its on the boundary.
# 
# Example 2:
# 
# 
# Input: [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
# Output: 0
# Explanation: 
# All 1s are either on the boundary or can reach the boundary.
# 
# 
# 
# 
# Note:
# 
# 
# 1 <= A.length <= 500
# 1 <= A[i].length <= 500
# 0 <= A[i][j] <= 1
# All rows have the same size.
# 
#

# @lc code=start
class Solution(object):
    def numEnclaves(self, matrix):
        """
        :type A: List[List[int]]
        :rtype: int
        """
        if not matrix:
            return 0
        
        r = len(matrix)
        c = len(matrix[0])
        
        for i in range(r):
            for j in [0, c-1]:
                if matrix[i][j] == 1:
                    self.dfs(matrix, i, j)
        for j in range(c):
            for i in [0, r-1]:
                if matrix[i][j] == 1:
                    self.dfs(matrix, i, j)
        ans = 0
        for row in matrix:
            ans += sum(row)
        return ans 

    def dfs(self, board, i, j):
        if i<0 or j<0 or i>=len(board) or j>=len(board[0]) or board[i][j] == 0:
            return 
        board[i][j] = 0
        self.dfs(board, i-1, j)
        self.dfs(board, i+1, j)
        self.dfs(board, i, j-1)
        self.dfs(board, i, j+1)
# @lc code=end

sol = Solution()
matrix = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
print(sol.numEnclaves(matrix))
