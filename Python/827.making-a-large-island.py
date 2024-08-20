#
# @lc app=leetcode id=827 lang=python3
#
# [827] Making A Large Island
#
# https://leetcode.com/problems/making-a-large-island/description/
#
# algorithms
# Hard (47.94%)
# Likes:    3899
# Dislikes: 76
# Total Accepted:    186.5K
# Total Submissions: 388.9K
# Testcase Example:  '[[1,0],[0,1]]'
#
# You are given an n x n binary matrix grid. You are allowed to change at most
# one 0 to be 1.
# 
# Return the size of the largest island in grid after applying this operation.
# 
# An island is a 4-directionally connected group of 1s.
# 
# 
# Example 1:
# 
# 
# Input: grid = [[1,0],[0,1]]
# Output: 3
# Explanation: Change one 0 to 1 and connect two 1s, then we get an island with
# area = 3.
# 
# 
# Example 2:
# 
# 
# Input: grid = [[1,1],[1,0]]
# Output: 4
# Explanation: Change the 0 to 1 and make the island bigger, only one island
# with area = 4.
# 
# Example 3:
# 
# 
# Input: grid = [[1,1],[1,1]]
# Output: 4
# Explanation: Can't change any 0 to 1, only one island with area = 4.
# 
# 
# 
# Constraints:
# 
# 
# n == grid.length
# n == grid[i].length
# 1 <= n <= 500
# grid[i][j] is either 0 or 1.
# 
# 
#

# @lc code=start
class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:
        color = 2
        color2size = {}
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    color2size[color] = self.dfs(grid, i, j, color)
                    color += 1

        ans = max(color2size.values() or [0])
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] != 0:
                    continue
                nei_colors = set()
                for x, y in [(i+1, j), (i-1, j), (i, j+1), (i, j-1)]:
                    if x < 0 or y < 0 or x >= len(grid) or y >= len(grid[0]):
                        continue
                    if grid[x][y] == 0:
                        continue
                    # if 0 <= x < len(grid) and 0 <= y < len(grid[0]) and grid[x][y] != 0:
                    nei_colors.add(grid[x][y])
                ans = max(ans, 1 + sum(color2size[color] for color in nei_colors))

        return ans
    
    def dfs(self, grid, i, j, color):
        if i < 0 or j < 0 or i >= len(grid) or j >= len(grid[0]):
            return 0
        if grid[i][j] != 1:
            return 0
        grid[i][j] = color
        return 1 + self.dfs(grid, i+1, j, color) + self.dfs(grid, i-1, j, color) + self.dfs(grid, i, j+1, color) + self.dfs(grid, i, j-1, color)
# @lc code=end

