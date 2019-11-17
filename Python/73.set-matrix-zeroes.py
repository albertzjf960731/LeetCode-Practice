#
# @lc app=leetcode id=73 lang=python
#
# [73] Set Matrix Zeroes
#
# https://leetcode.com/problems/set-matrix-zeroes/description/
#
# algorithms
# Medium (41.21%)
# Likes:    1377
# Dislikes: 236
# Total Accepted:    249.3K
# Total Submissions: 604.1K
# Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
#
# Given a m x n matrix, if an element is 0, set its entire row and column to 0.
# Do it in-place.
# 
# Example 1:
# 
# 
# Input: 
# [
# [1,1,1],
# [1,0,1],
# [1,1,1]
# ]
# Output: 
# [
# [1,0,1],
# [0,0,0],
# [1,0,1]
# ]
# 
# 
# Example 2:
# 
# 
# Input: 
# [
# [0,1,2,0],
# [3,4,5,2],
# [1,3,1,5]
# ]
# Output: 
# [
# [0,0,0,0],
# [0,4,5,0],
# [0,3,1,0]
# ]
# 
# 
# Follow up:
# 
# 
# A straight forward solution using O(mn) space is probably a bad idea.
# A simple improvement uses O(m + n) space, but still not the best
# solution.
# Could you devise a constant space solution?
# 
# 
#

# @lc code=start
class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        # flag = [[0 for _ in range(len(matrix[0]))] for _ in range(len(matrix))]

        # for i in range(len(matrix)):
        #     for j in range(len(matrix[0])):
        #         if matrix[i][j] == 0 and flag[i][j] == 0:
        #             for k in range(len(matrix)):
        #                 if matrix[k][j] != 0:
        #                     matrix[k][j] = 0
        #                     flag[k][j] = 1
        #             for k in range(len(matrix[0])):
        #                 if matrix[i][k] != 0:
        #                     matrix[i][k] = 0    
        #                     flag[i][k] = 1
                        
        row = [0 for _ in range(len(matrix))]
        col = [0 for _ in range(len(matrix[0]))]

        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == 0:
                    row[i] = 1
                    col[j] = 1
        for i in range(len(row)):
            if row[i] == 1:
                for j in range(len(matrix[0])):
                    matrix[i][j] = 0
        for j in range(len(col)):
            if col[j] == 1:
                for i in range(len(matrix)):
                    matrix[i][j] = 0
# @lc code=end

sol = Solution()
matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]

sol.setZeroes(matrix)
print(matrix)