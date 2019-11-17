#
# @lc app=leetcode id=36 lang=python
#
# [36] Valid Sudoku
#
# https://leetcode.com/problems/valid-sudoku/description/
#
# algorithms
# Medium (45.34%)
# Likes:    1107
# Dislikes: 378
# Total Accepted:    283.9K
# Total Submissions: 624.7K
# Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
#
# Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be
# validated according to the following rules:
# 
# 
# Each row must contain the digits 1-9 without repetition.
# Each column must contain the digits 1-9 without repetition.
# Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without
# repetition.
# 
# 
# 
# A partially filled sudoku which is valid.
# 
# The Sudoku board could be partially filled, where empty cells are filled with
# the character '.'.
# 
# Example 1:
# 
# 
# Input:
# [
# ⁠ ["5","3",".",".","7",".",".",".","."],
# ⁠ ["6",".",".","1","9","5",".",".","."],
# ⁠ [".","9","8",".",".",".",".","6","."],
# ⁠ ["8",".",".",".","6",".",".",".","3"],
# ⁠ ["4",".",".","8",".","3",".",".","1"],
# ⁠ ["7",".",".",".","2",".",".",".","6"],
# ⁠ [".","6",".",".",".",".","2","8","."],
# ⁠ [".",".",".","4","1","9",".",".","5"],
# ⁠ [".",".",".",".","8",".",".","7","9"]
# ]
# Output: true
# 
# 
# Example 2:
# 
# 
# Input:
# [
# ["8","3",".",".","7",".",".",".","."],
# ["6",".",".","1","9","5",".",".","."],
# [".","9","8",".",".",".",".","6","."],
# ["8",".",".",".","6",".",".",".","3"],
# ["4",".",".","8",".","3",".",".","1"],
# ["7",".",".",".","2",".",".",".","6"],
# [".","6",".",".",".",".","2","8","."],
# [".",".",".","4","1","9",".",".","5"],
# [".",".",".",".","8",".",".","7","9"]
# ]
# Output: false
# Explanation: Same as Example 1, except with the 5 in the top left corner
# being 
# ⁠   modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is
# invalid.
# 
# 
# Note:
# 
# 
# A Sudoku board (partially filled) could be valid but is not necessarily
# solvable.
# Only the filled cells need to be validated according to the mentioned
# rules.
# The given board contain only digits 1-9 and the character '.'.
# The given board size is always 9x9.
# 
# 
#

# @lc code=start
class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        for i in range(9):
            if not self.check_line(board[i]):
                return False

        for j in range(9):
            if not self.check_line([board[i][j]for i in range(9)]):
                return False

        for i in range(3):
            for j in range(3):
                if not self.check_board([board[k][3*j:3*j+3] for k in range(3*i, 3*i+3)]):
                    return False
        return True 

    def check_line(self, line):
        line = ''.join(line).replace('.', '')
        if not len(set(line)) == len(line):
            return False
        else:
            return True
    
    def check_board(self, board):
        board = ''.join(c for line in board for c in line).replace('.', '')
        
        if not len(set(board)) == len(board):
            return False
        else:
            return True    
# @lc code=end

sol = Solution()
board =[[".",".","4",".",".",".","6","3","."],[".",".",".",".",".",".",".",".","."],["5",".",".",".",".",".",".","9","."],[".",".",".","5","6",".",".",".","."],["4",".","3",".",".",".",".",".","1"],[".",".",".","7",".",".",".",".","."],[".",".",".","5",".",".",".",".","."],[".",".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".",".","."]]


print(sol.isValidSudoku(board))