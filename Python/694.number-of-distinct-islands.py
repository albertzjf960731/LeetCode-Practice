#
# @lc app=leetcode id=694 lang=python3
#
# [694] Number of Distinct Islands
#
# https://leetcode.com/problems/number-of-distinct-islands/description/
#
# algorithms
# Medium (61.45%)
# Likes:    2226
# Dislikes: 142
# Total Accepted:    170.1K
# Total Submissions: 276.9K
# Testcase Example:  '[[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]'
#
# You are given an m x n binary matrix grid. An island is a group of 1's
# (representing land) connected 4-directionally (horizontal or vertical.) You
# may assume all four edges of the grid are surrounded by water.
# 
# An island is considered to be the same as another if and only if one island
# can be translated (and not rotated or reflected) to equal the other.
# 
# Return the number of distinct islands.
# 
# 
# Example 1:
# 
# 
# Input: grid = [[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]
# Output: 1
# 
# 
# Example 2:
# 
# 
# Input: grid = [[1,1,0,1,1],[1,0,0,0,0],[0,0,0,0,1],[1,1,0,1,1]]
# Output: 3
# 
# 
# 
# Constraints:
# 
# 
# m == grid.length
# n == grid[i].length
# 1 <= m, n <= 50
# grid[i][j] is either 0 or 1.
# 
# 
#

# @lc code=start
class Solution:
    def numDistinctIslands(self, grid: List[List[int]]) -> int:
        visited = set()
        island_set = set()
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 0 or (i, j) in visited:
                    continue
                cur_island = set()
                self.dfs(grid, i, j, visited, i, j, cur_island)
                island_set.add(tuple(cur_island))
        return len(island_set)
    
    def dfs(self, grid, i, j, visited, ori_row, ori_col, cur_island):
        if i < 0 or i >= len(grid) or j < 0 or j >= len(grid[0]):
            return
        if grid[i][j] == 0 or (i, j) in visited:
            return
        
        visited.add((i, j))
        cur_island.add((i - ori_row, j - ori_col))
        self.dfs(grid, i + 1, j, visited, ori_row, ori_col, cur_island)
        self.dfs(grid, i - 1, j, visited, ori_row, ori_col, cur_island)
        self.dfs(grid, i, j + 1, visited, ori_row, ori_col, cur_island)
        self.dfs(grid, i, j - 1, visited, ori_row, ori_col, cur_island)

# @lc code=end

