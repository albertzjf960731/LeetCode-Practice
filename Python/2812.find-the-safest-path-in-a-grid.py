#
# @lc app=leetcode id=2812 lang=python3
#
# [2812] Find the Safest Path in a Grid
#
# https://leetcode.com/problems/find-the-safest-path-in-a-grid/description/
#
# algorithms
# Medium (49.08%)
# Likes:    1567
# Dislikes: 292
# Total Accepted:    93.2K
# Total Submissions: 190K
# Testcase Example:  '[[1,0,0],[0,0,0],[0,0,1]]'
#
# You are given a 0-indexed 2D matrix grid of size n x n, where (r, c)
# represents:
# 
# 
# A cell containing a thief if grid[r][c] = 1
# An empty cell if grid[r][c] = 0
# 
# 
# You are initially positioned at cell (0, 0). In one move, you can move to any
# adjacent cell in the grid, including cells containing thieves.
# 
# The safeness factor of a path on the grid is defined as the minimum manhattan
# distance from any cell in the path to any thief in the grid.
# 
# Return the maximum safeness factor of all paths leading to cell (n - 1, n -
# 1).
# 
# An adjacent cell of cell (r, c), is one of the cells (r, c + 1), (r, c - 1),
# (r + 1, c) and (r - 1, c) if it exists.
# 
# The Manhattan distance between two cells (a, b) and (x, y) is equal to |a -
# x| + |b - y|, where |val| denotes the absolute value of val.
# 
# 
# Example 1:
# 
# 
# Input: grid = [[1,0,0],[0,0,0],[0,0,1]]
# Output: 0
# Explanation: All paths from (0, 0) to (n - 1, n - 1) go through the thieves
# in cells (0, 0) and (n - 1, n - 1).
# 
# 
# Example 2:
# 
# 
# Input: grid = [[0,0,1],[0,0,0],[0,0,0]]
# Output: 2
# Explanation: The path depicted in the picture above has a safeness factor of
# 2 since:
# - The closest cell of the path to the thief at cell (0, 2) is cell (0, 0).
# The distance between them is | 0 - 0 | + | 0 - 2 | = 2.
# It can be shown that there are no other paths with a higher safeness
# factor.
# 
# 
# Example 3:
# 
# 
# Input: grid = [[0,0,0,1],[0,0,0,0],[0,0,0,0],[1,0,0,0]]
# Output: 2
# Explanation: The path depicted in the picture above has a safeness factor of
# 2 since:
# - The closest cell of the path to the thief at cell (0, 3) is cell (1, 2).
# The distance between them is | 0 - 1 | + | 3 - 2 | = 2.
# - The closest cell of the path to the thief at cell (3, 0) is cell (3, 2).
# The distance between them is | 3 - 3 | + | 0 - 2 | = 2.
# It can be shown that there are no other paths with a higher safeness
# factor.
# 
# 
# 
# Constraints:
# 
# 
# 1 <= grid.length == n <= 400
# grid[i].length == n
# grid[i][j] is either 0 or 1.
# There is at least one thief in the grid.
# 
# 
#

# @lc code=start
class Solution:
    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        self.updateGrid(grid)

        n = len(grid)
        pq = [(-grid[0][0], 0, 0)]
        visited = set((0, 0))

        ans = float('inf')
        while pq:
            d, i, j = heapq.heappop(pq)
            ans = min(ans, -d)
            if i == n - 1 and j == n - 1:
                break
            for d in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
                x, y = i + d[0], j + d[1]
                if x < 0 or x >= n or y < 0 or y >= n:
                    continue
                if (x, y) in visited:
                    continue
                heapq.heappush(pq, (-grid[x][y], x, y))
                visited.add((x, y))
        return ans

    def updateGrid(self, grid):
        n = len(grid)

        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    grid[i][j] = 0
                else:
                    if i == 0 and j == 0:
                        grid[i][j] = float('inf')
                    elif i == 0:
                        grid[i][j] = grid[i][j-1] + 1
                    elif j == 0:
                        grid[i][j] = grid[i-1][j] + 1
                    else:
                        grid[i][j] = min(grid[i-1][j], grid[i][j-1]) + 1
        for i in range(n-1, -1, -1):
            for j in range(n-1, -1, -1):
                if grid[i][j] == 0:
                    continue
                else:
                    if i == n - 1 and j == n -1:
                        continue
                    elif i == n - 1:
                        grid[i][j] = min(grid[i][j], grid[i][j+1] + 1)
                    elif j == n - 1:
                        grid[i][j] = min(grid[i][j], grid[i+1][j] + 1)
                    else:
                        grid[i][j] = min(grid[i][j], min(grid[i+1][j], grid[i][j+1]) + 1)        
# @lc code=end

