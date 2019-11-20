#
# @lc app=leetcode id=417 lang=python
#
# [417] Pacific Atlantic Water Flow
#
# https://leetcode.com/problems/pacific-atlantic-water-flow/description/
#
# algorithms
# Medium (38.55%)
# Likes:    827
# Dislikes: 152
# Total Accepted:    54.7K
# Total Submissions: 141.5K
# Testcase Example:  '[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]'
#
# Given an m x n matrix of non-negative integers representing the height of
# each unit cell in a continent, the "Pacific ocean" touches the left and top
# edges of the matrix and the "Atlantic ocean" touches the right and bottom
# edges.
# 
# Water can only flow in four directions (up, down, left, or right) from a cell
# to another one with height equal or lower.
# 
# Find the list of grid coordinates where water can flow to both the Pacific
# and Atlantic ocean.
# 
# Note:
# 
# 
# The order of returned grid coordinates does not matter.
# Both m and n are less than 150.
# 
# 
# 
# 
# Example:
# 
# 
# Given the following 5x5 matrix:
# 
# ⁠ Pacific ~   ~   ~   ~   ~ 
# ⁠      ~  1   2   2   3  (5) *
# ⁠      ~  3   2   3  (4) (4) *
# ⁠      ~  2   4  (5)  3   1  *
# ⁠      ~ (6) (7)  1   4   5  *
# ⁠      ~ (5)  1   1   2   4  *
# ⁠         *   *   *   *   * Atlantic
# 
# Return:
# 
# [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with
# parentheses in above matrix).
# 
# 
# 
# 
#

# @lc code=start
class Solution(object):
    def pacificAtlantic(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[List[int]]
        """

        if not matrix: 
            return []

        self.directions = [(1,0),(-1,0),(0,1),(0,-1)]

        n = len(matrix)
        m = len(matrix[0])
        
        p_visited = [[False for _ in range(m)] for _ in range(n)]
        a_visited = [[False for _ in range(m)] for _ in range(n)]

        res = []
        
        for i in range(n):
            # p_visited[i][0] = True
            # a_visited[i][n-1] = True
            self.dfs(matrix, i, 0, p_visited)
            self.dfs(matrix, i, m-1, a_visited)

        for j in range(m):
            # p_visited[0][j] = True
            # a_visited[m-1][j] = True
            self.dfs(matrix, 0, j, p_visited)
            self.dfs(matrix, n-1, j, a_visited)
            
        for i in range(n):
            for j in range(m):
                if p_visited[i][j] and a_visited[i][j]:
                    res.append([i,j])
        return res
                
                
    def dfs(self, matrix, i, j, visited):
        # when dfs called, meaning its caller already verified this point 

        n = len(matrix)
        m = len(matrix[0])

        visited[i][j] = True

        for d in self.directions:
            x, y = i + d[0], j + d[1]

            if x < 0 or x >= n or y < 0 or y >= m or visited[x][y] or matrix[x][y] < matrix[i][j]:
                continue
            self.dfs(matrix, x, y, visited)

# @lc code=end

sol = Solution()
matrix = [[3,3,3,3,3,3],[3,0,3,3,0,3],[3,3,3,3,3,3]]
print(sol.pacificAtlantic(matrix))