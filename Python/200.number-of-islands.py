#
# @lc app=leetcode id=200 lang=python
#
# [200] Number of Islands
#
# https://leetcode.com/problems/number-of-islands/description/
#
# algorithms
# Medium (43.43%)
# Likes:    3496
# Dislikes: 128
# Total Accepted:    472.3K
# Total Submissions: 1.1M
# Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
#
# Given a 2d grid map of '1's (land) and '0's (water), count the number of
# islands. An island is surrounded by water and is formed by connecting
# adjacent lands horizontally or vertically. You may assume all four edges of
# the grid are all surrounded by water.
# 
# Example 1:
# 
# 
# Input:
# 11110
# 11010
# 11000
# 00000
# 
# Output: 1
# 
# 
# Example 2:
# 
# 
# Input:
# 11000
# 11000
# 00100
# 00011
# 
# Output: 3
# 
#

# @lc code=start
class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
    #     ans = 0
    #     for i in range(len(grid)):
    #         for j in range(len(grid[0])):
    #             if grid[i][j] == '1':
    #                 self.helper(grid, i, j)
    #                 ans += 1
    #     return ans 

    # def helper(self, grid, i, j):
    #     if i<0 or j<0 or i>=len(grid) or j>=len(grid[0]) or grid[i][j] != '1':
    #         return
    #     grid[i][j] = '#'
    #     self.helper(grid, i-1, j)
    #     self.helper(grid, i+1, j)
    #     self.helper(grid, i, j-1)
    #     self.helper(grid, i, j+1)
        

# @lc code=end

sol = Solution()
grid = [["1"],["1"]]    
sol.numIslands(grid)