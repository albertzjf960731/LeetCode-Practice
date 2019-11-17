#
# @lc app=leetcode id=59 lang=python
#
# [59] Spiral Matrix II
#
# https://leetcode.com/problems/spiral-matrix-ii/description/
#
# algorithms
# Medium (49.46%)
# Likes:    637
# Dislikes: 90
# Total Accepted:    159.5K
# Total Submissions: 321.4K
# Testcase Example:  '3'
#
# Given a positive integer n, generate a square matrix filled with elements
# from 1 to n^2 in spiral order.
# 
# Example:
# 
# 
# Input: 3
# Output:
# [
# ⁠[ 1, 2, 3 ],
# ⁠[ 8, 9, 4 ],
# ⁠[ 7, 6, 5 ]
# ]
# 
# 
#

# @lc code=start
class Solution(object):
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        # matrix = [[0 for _ in range(n)] for _ in range(n)]
        # for i in range(n*n):
        #     matrix[i//3][i%3] = i

        # l = [i+1 for i in range(n)]

        matrix, lo = [], n*n+1
        while lo > 1:
            lo, hi = lo - len(matrix), lo
            matrix = [range(lo, hi)] + zip(*matrix[::-1])
        return matrix

        # matrix = [[0]*n for _ in range(n)]
        # i, j , di, dj = 0, 0, 0, 1
        # for k in range(n * n):
        #     matrix[i][j] = k + 1
        #     if matrix[(i+di)%n][(j+dj)%n]:
        #         di, dj = dj, -di
        #     i += di 
        #     j += dj 
        # return matrix
    # def spiralOrder(self, matrix):
    #     """
    #     :type matrix: List[List[int]]
    #     :rtype: List[int]
    #     """
    #     if not matrix:
    #         return []
    #     return list(matrix.pop(0)) + self.spiralOrder(zip(*matrix)[::-1])
# @lc code=end

sol = Solution()
n = 3
sol.generateMatrix(n)