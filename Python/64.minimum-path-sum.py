#
# @lc app=leetcode id=64 lang=python
#
# [64] Minimum Path Sum
#
# https://leetcode.com/problems/minimum-path-sum/description/
#
# algorithms
# Medium (49.26%)
# Likes:    1754
# Dislikes: 45
# Total Accepted:    276K
# Total Submissions: 559.3K
# Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
#
# Given a m x n grid filled with non-negative numbers, find a path from top
# left to bottom right which minimizes the sum of all numbers along its path.
# 
# Note: You can only move either down or right at any point in time.
# 
# Example:
# 
# 
# Input:
# [
# [1,3,1],
# ⁠ [1,5,1],
# ⁠ [4,2,1]
# ]
# Output: 7
# Explanation: Because the path 1→3→1→1→1 minimizes the sum.
# 
# 
#

# @lc code=start
class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n = len(grid)
        m = len(grid[0])
        # min_path = [[float('inf')]*(m+1) for _ in range(n+1)]


        # for i in range(1, n+1):
        #     for j in range(1, m+1):
        #         if i == 1 and j == 1:
        #             min_path[i][j] = grid[i-1][j-1] 
        #         else:
        #             min_path[i][j] = grid[i-1][j-1] + min(min_path[i][j-1], min_path[i-1][j])
        # return min_path[n][m]

        
        for i in range(1, n):
            grid[i][0] = grid[i-1][0] + grid[i][0]
        for j in range(1, m): 
            grid[0][j] = grid[0][j - 1] + grid[0][j]
        for i in range(1, n):
            for j in range(1, m):
                grid[i][j] = grid[i][j] + min(grid[i][j-1], grid[i-1][j])

        return grid[-1][-1]
# @lc code=end

sol = Solution()
grid = [[1,3,1],[1,5,1],[4,2,1]]

print(sol.minPathSum(grid))