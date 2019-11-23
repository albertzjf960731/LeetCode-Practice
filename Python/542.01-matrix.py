#
# @lc app=leetcode id=542 lang=python
#
# [542] 01 Matrix
#
# https://leetcode.com/problems/01-matrix/description/
#
# algorithms
# Medium (37.35%)
# Likes:    913
# Dislikes: 92
# Total Accepted:    60K
# Total Submissions: 159.8K
# Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
#
# Given a matrix consists of 0 and 1, find the distance of the nearest 0 for
# each cell.
# 
# The distance between two adjacent cells is 1.
# 
# 
# 
# Example 1: 
# 
# 
# Input:
# [[0,0,0],
# ⁠[0,1,0],
# ⁠[0,0,0]]
# 
# Output:
# [[0,0,0],
# [0,1,0],
# [0,0,0]]
# 
# 
# Example 2: 
# 
# 
# Input:
# [[0,0,0],
# ⁠[0,1,0],
# ⁠[1,1,1]]
# 
# Output:
# [[0,0,0],
# ⁠[0,1,0],
# ⁠[1,2,1]]
# 
# 
# 
# 
# Note:
# 
# 
# The number of elements of the given matrix will not exceed 10,000.
# There are at least one 0 in the given matrix.
# The cells are adjacent in only four directions: up, down, left and right.
# 
# 
#

# @lc code=start
class Solution(object):
    def updateMatrix(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[List[int]]
        """
        
        n = len(matrix)
        m = len(matrix[0])
        
        dp = [[max(n, m) for _ in range(m+2)] for _ in range(n+2)]

        
        for i in range(1, n+1):
            for j in range(1, m+1):
                if matrix[i-1][j-1] == 0:
                    dp[i][j] = 0
                else:
                    dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1, dp[i][j])

                    
        for i in range(n, 0, -1):
            for j in range(m, 0, -1):
                if matrix[i-1][j-1] == 0:
                    dp[i][j] = 0
                else:
                    dp[i][j] = min(dp[i+1][j]+1, dp[i][j+1]+1, dp[i][j])
                        
        dp = [dp[i][1:m + 1] for i in range(1, n + 1)]
        return dp

# @lc code=end

sol = Solution()
matrix = [[0,0,0],
 [0,1,0],
 [0,0,0]]
print(sol.updateMatrix(matrix))
