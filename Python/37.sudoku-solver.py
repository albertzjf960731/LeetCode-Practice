#
# @lc app=leetcode id=37 lang=python
#
# [37] Sudoku Solver
#
# https://leetcode.com/problems/sudoku-solver/description/
#
# algorithms
# Hard (39.37%)
# Likes:    1192
# Dislikes: 76
# Total Accepted:    151.5K
# Total Submissions: 383.4K
# Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
#
# Write a program to solve a Sudoku puzzle by filling the empty cells.
# 
# A sudoku solution must satisfy all of the following rules:
# 
# 
# Each of the digits 1-9 must occur exactly once in each row.
# Each of the digits 1-9 must occur exactly once in each column.
# Each of the the digits 1-9 must occur exactly once in each of the 9 3x3
# sub-boxes of the grid.
# 
# 
# Empty cells are indicated by the character '.'.
# 
# 
# A sudoku puzzle...
# 
# 
# ...and its solution numbers marked in red.
# 
# Note:
# 
# 
# The given board contain only digits 1-9 and the character '.'.
# You may assume that the given Sudoku puzzle will have a single unique
# solution.
# The given board size is always 9x9.
# 
# 
#

# @lc code=start
class Solution(object):
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """

        self.solver(board)

    def solver(self, board):
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    
                    num = 1
                    while num <= 9:
                        if (self.is_valid(i, j, board, str(num))):
                            
                            board[i][j] = str(num)
                            if self.solver(board):
                                return True
                            else:
                                board[i][j] = '.'
                                
                        num += 1
                    
                    return False  

        return True
        
    def is_valid(self, row, col, board, c):
        for i in range(9):
            if board[i][col] == c:
                return False
        for j in range(9):
            if board[row][j] == c:
                return False
        start_row = row // 3 * 3
        start_col = col // 3 * 3
        for i in range(3):
            for j in range(3):
                if board[start_row+i][start_col+j] == c:
                    return False
        return True
# @lc code=end

sol = Solution()
board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
sol.solveSudoku(board)
print(board)
