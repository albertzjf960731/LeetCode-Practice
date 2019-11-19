#
# @lc app=leetcode id=463 lang=python
#
# [463] Island Perimeter
#
# https://leetcode.com/problems/island-perimeter/description/
#
# algorithms
# Easy (62.04%)
# Likes:    1285
# Dislikes: 93
# Total Accepted:    155.5K
# Total Submissions: 250.3K
# Testcase Example:  '[[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]'
#
# You are given a map in form of a two-dimensional integer grid where 1
# represents land and 0 represents water.
# 
# Grid cells are connected horizontally/vertically (not diagonally). The grid
# is completely surrounded by water, and there is exactly one island (i.e., one
# or more connected land cells).
# 
# The island doesn't have "lakes" (water inside that isn't connected to the
# water around the island). One cell is a square with side length 1. The grid
# is rectangular, width and height don't exceed 100. Determine the perimeter of
# the island.
# 
# 
# 
# Example:
# 
# 
# Input:
# [[0,1,0,0],
# ⁠[1,1,1,0],
# ⁠[0,1,0,0],
# ⁠[1,1,0,0]]
# 
# Output: 16
# 
# Explanation: The perimeter is the 16 yellow stripes in the image below:
# 
# 
# 
# 
#

# @lc code=start
class Solution(object):
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        num_island = 0
        num_connect = 0

        rows = len(grid)   
        cols = len(grid[0])

        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    num_island += 1
                    
                    # if i+1<rows and grid[i+1][j] == 1:
                    #     num_connect += 1
                    if i-1>=0 and grid[i-1][j] == 1:
                        num_connect += 1
                    if j+1<cols and grid[i][j+1] == 1:
                        num_connect += 1
                    # if j-1 >= 0 and grid[i][j-1] == 1:
                    #     num_connect += 1

        return num_island * 4 - num_connect * 2

# @lc code=end

sol = Solution()
grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
sol.islandPerimeter(grid)