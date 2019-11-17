#
# @lc app=leetcode id=63 lang=python
#
# [63] Unique Paths II
#
# https://leetcode.com/problems/unique-paths-ii/description/
#
# algorithms
# Medium (33.75%)
# Likes:    1095
# Dislikes: 182
# Total Accepted:    235.9K
# Total Submissions: 698.9K
# Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
#
# A robot is located at the top-left corner of a m x n grid (marked 'Start' in
# the diagram below).
# 
# The robot can only move either down or right at any point in time. The robot
# is trying to reach the bottom-right corner of the grid (marked 'Finish' in
# the diagram below).
# 
# Now consider if some obstacles are added to the grids. How many unique paths
# would there be?
# 
# 
# 
# An obstacle and empty space is marked as 1 and 0 respectively in the grid.
# 
# Note: m and n will be at most 100.
# 
# Example 1:
# 
# 
# Input:
# [
# [0,0,0],
# [0,1,0],
# [0,0,0]
# ]
# Output: 2
# Explanation:
# There is one obstacle in the middle of the 3x3 grid above.
# There are two ways to reach the bottom-right corner:
# 1. Right -> Right -> Down -> Down
# 2. Down -> Down -> Right -> Right
# 
# 
#

# @lc code=start
class Solution(object):
    def uniquePathsWithObstacles(self, matrix):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        # m = len(obstacleGrid)
        # n = len(obstacleGrid[0])

        # matrix = [[0]*(n+1) for _ in range(m+1)]

        # for i in range(1, m+1):
        #     for j in range(1, n+1):
        #         if obstacleGrid[i-1][j-1]:
        #             continue
        #         if i == 1 and j == 1:
        #             matrix[i][j] = 1
        #         else:
        #             matrix[i][j] = matrix[i-1][j] + matrix[i][j-1]
        # return matrix[m][n]  

        m = len(matrix)
        n = len(matrix[0])

        for i in range(m):
            for j in range(n):
                if 1 - matrix[i][j] == 0:
                    matrix[i][j] = 0
                    continue
                if i == 0 and j == 0:
                    matrix[i][j] = 1
                else:
                    if i-1<0:
                        matrix[i][j] = matrix[i][j-1]
                    elif j-1<0:
                        matrix[i][j] = matrix[i-1][j]
                    else:
                        matrix[i][j] = matrix[i-1][j] + matrix[i][j-1]
        return matrix[m-1][n-1]



# @lc code=end

sol = Solution()
obstacleGrid = [[0,0,0,0,0],[0,0,0,0,1],[0,0,0,1,0],[0,0,0,0,0]]


print(sol.uniquePathsWithObstacles(obstacleGrid))