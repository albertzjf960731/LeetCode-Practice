#
# @lc app=leetcode id=240 lang=python
#
# [240] Search a 2D Matrix II
#
# https://leetcode.com/problems/search-a-2d-matrix-ii/description/
#
# algorithms
# Medium (41.74%)
# Likes:    2070
# Dislikes: 60
# Total Accepted:    230.6K
# Total Submissions: 550.8K
# Testcase Example:  '[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n' +
#   '5'
#
# Write an efficient algorithm that searches for a value in an m x n matrix.
# This matrix has the following properties:
# 
# 
# Integers in each row are sorted in ascending from left to right.
# Integers in each column are sorted in ascending from top to bottom.
# 
# 
# Example:
# 
# Consider the following matrix:
# 
# 
# [
# ⁠ [1,   4,  7, 11, 15],
# ⁠ [2,   5,  8, 12, 19],
# ⁠ [3,   6,  9, 16, 22],
# ⁠ [10, 13, 14, 17, 24],
# ⁠ [18, 21, 23, 26, 30]
# ]
# 
# 
# Given target = 5, return true.
# 
# Given target = 20, return false.
# 
#

# @lc code=start
class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """

        if not matrix:
            return False

        # rows, columns = len(matrix), len(matrix[0])

        # up_left = [0, 0]
        # down_right = [rows-1, columns-1]

        # while up_left != down_right:
        #     mid = [(up_left[0] + down_right[0])//2, (up_left[1]+down_right[1])//2]

        #     num = matrix[mid[0]][mid[1]]

        #     if target == num:
        #         return True

        #     elif target < num:
        #         down_right = mid
        #     else:
        #         up_left = mid
        # return False
        
        # 斜对角
        # col = len(matrix[0])-1

        # for row in matrix:
        #     while col >= 0 and row[col]>target:
        #         col -= 1
        #     if col >= 0 and row[col] == target:
        #         return True
        # return False

        rows, columns = len(matrix), len(matrix[0])
        i, j = 0, columns-1
        while i<rows and j>-1:
            if target == matrix[i][j]:
                return True
            elif target > matrix[i][j]:
                i += 1
            else:
                j -= 1
        return False

# @lc code=end

sol = Solution()
matrix = [[]]
# [
#   [1,   4,  7, 11, 15],
#   [2,   5,  8, 12, 19],
#   [3,   6,  9, 16, 22],
#   [10, 13, 14, 17, 24],
#   [18, 21, 23, 26, 30]
# ]
print(sol.searchMatrix(matrix, 0))