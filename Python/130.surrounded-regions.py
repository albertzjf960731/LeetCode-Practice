#
# @lc app=leetcode id=130 lang=python
#
# [130] Surrounded Regions
#
# https://leetcode.com/problems/surrounded-regions/description/
#
# algorithms
# Medium (24.42%)
# Likes:    1010
# Dislikes: 511
# Total Accepted:    171.2K
# Total Submissions: 697.7K
# Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
#
# Given a 2D board containing 'X' and 'O' (the letter O), capture all regions
# surrounded by 'X'.
# 
# A region is captured by flipping all 'O's into 'X's in that surrounded
# region.
# 
# Example:
# 
# 
# X X X X
# X O O X
# X X O X
# X O X X
# 
# 
# After running your function, the board should be:
# 
# 
# X X X X
# X X X X
# X X X X
# X O X X
# 
# 
# Explanation:
# 
# Surrounded regions shouldn’t be on the border, which means that any 'O' on
# the border of the board are not flipped to 'X'. Any 'O' that is not on the
# border and it is not connected to an 'O' on the border will be flipped to
# 'X'. Two cells are connected if they are adjacent cells connected
# horizontally or vertically.
# 
#

# @lc code=start
class Solution(object):
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        
        if not board:
            return []

        n = len(board)
        m = len(board[0])

        for i in range(n):
            for j in [0, m-1]:
                if board[i][j] == 'O':
                    self.dfs(board, i, j)
        for j in range(m):
            for i in [0, n-1]:
                if board[i][j] == 'O':
                    self.dfs(board, i, j)
       
        for i in range(n):
            for j in range(m):
                if board[i][j] == 'O':
                    board[i][j] = 'X'
                elif board[i][j] == '#':
                    board[i][j] = 'O'


    def dfs(self, board, i, j):
        if i<0 or j<0 or i>=len(board) or j>=len(board[0]) or board[i][j] != 'O':
            return

        board[i][j] = '#'
        self.dfs(board, i-1, j)
        self.dfs(board, i+1, j)
        self.dfs(board, i, j-1)
        self.dfs(board, i, j+1)


# @lc code=end

