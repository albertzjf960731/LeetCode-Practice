#
# @lc app=leetcode id=48 lang=python
#
# [48] Rotate Image
#
# https://leetcode.com/problems/rotate-image/description/
#
# algorithms
# Medium (51.41%)
# Likes:    2029
# Dislikes: 179
# Total Accepted:    305.9K
# Total Submissions: 594.1K
# Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
#
# You are given an n x n 2D matrix representing an image.
# 
# Rotate the image by 90 degrees (clockwise).
# 
# Note:
# 
# You have to rotate the image in-place, which means you have to modify the
# input 2D matrix directly. DO NOT allocate another 2D matrix and do the
# rotation.
# 
# Example 1:
# 
# 
# Given input matrix = 
# [
# ⁠ [1,2,3],
# ⁠ [4,5,6],
# ⁠ [7,8,9]
# ],
# 
# rotate the input matrix in-place such that it becomes:
# [
# ⁠ [7,4,1],
# ⁠ [8,5,2],
# ⁠ [9,6,3]
# ]
# 
# 
# Example 2:
# 
# 
# Given input matrix =
# [
# ⁠ [ 5, 1, 9,11],
# ⁠ [ 2, 4, 8,10],
# ⁠ [13, 3, 6, 7],
# ⁠ [15,14,12,16]
# ], 
# 
# rotate the input matrix in-place such that it becomes:
# [
# ⁠ [15,13, 2, 5],
# ⁠ [14, 3, 4, 1],
# ⁠ [12, 6, 8, 9],
# ⁠ [16, 7,10,11]
# ]
# 
# 
#

# @lc code=start
class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        # 0,0 -> 0,2
        # 0,1 -> 1,2
        # 0,2 -> 2,2

        # 1,0 -> 0,1
        # 1,1 -> 1,1
        # 1,2 -> 2,1
        
        # 2,0 -> 0,0
        # 2,1 -> 1,0
        # 2,2 -> 2,0

        # matrix2 = [[0 for _ in range(len(matrix))] for _ in range(len(matrix))]

        # for i in range(len(matrix)):

        #     j2 = len(matrix) - i - 1
        #     for j in range(len(matrix)):
        #         i2 = j 

        #         matrix2[i2][j2] = matrix[i][j]
        # return matrix2

        # for i in range(len(matrix)):
        #     for j in range(i):
        #         if i == j:
        #             continue
        #         temp = matrix[i][j]
        #         matrix[i][j] = matrix[j][i]
        #         matrix[j][i] = temp 
        
        # for i in range(len(matrix)):
        #     for j in range(len(matrix)//2):
        #         temp = matrix[i][j]
        #         matrix[i][j] = matrix[i][len(matrix)-j-1]
        #         matrix[i][len(matrix)-j-1] = temp


        n = len(matrix)
        for i in range(n//2):
            for j in range(i, n-i-1):
                temp = matrix[i][j]
                matrix[i][j] = matrix[n-j-1][i]
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1]
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1]
                matrix[j][n-i-1] = temp

        matrix[:] = zip(*matrix[::-1])

# @lc code=end

sol = Solution()
matrix = [
  [1,2,3],
  [4,5,6],
  [7,8,9]
]
sol.rotate(matrix)
print(matrix)