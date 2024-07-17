#
# @lc app=leetcode id=329 lang=python
#
# [329] Longest Increasing Path in a Matrix
#
# https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
#
# algorithms
# Hard (41.37%)
# Likes:    1325
# Dislikes: 22
# Total Accepted:    110.3K
# Total Submissions: 265.8K
# Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
#
# Given an integer matrix, find the length of the longest increasing path.
# 
# From each cell, you can either move to four directions: left, right, up or
# down. You may NOT move diagonally or move outside of the boundary (i.e.
# wrap-around is not allowed).
# 
# Example 1:
# 
# 
# Input: nums = 
# [
# ⁠ [9,9,4],
# ⁠ [6,6,8],
# ⁠ [2,1,1]
# ] 
# Output: 4 
# Explanation: The longest increasing path is [1, 2, 6, 9].
# 
# 
# Example 2:
# 
# 
# Input: nums = 
# [
# ⁠ [3,4,5],
# ⁠ [3,2,6],
# ⁠ [2,2,1]
# ] 
# Output: 4 
# Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally
# is not allowed.
# 
# 
#

# @lc code=start
class Solution(object):
    def longestIncreasingPath(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """

        dp = [[-1] * len(matrix[0]) for _ in range(len(matrix))]

        ans = 1
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                l = self.dfs(matrix, i, j, dp)
                ans = max(ans, l)
        return ans

    def dfs(self, matrix, i, j, dp):
        if dp[i][j] != -1:
            return dp[i][j]
        max_len = 1
        for d in [[0, 1], [0, -1], [1, 0], [-1, 0]]:
            x, y = i + d[0], j + d[1]
            if x < 0 or x >= len(matrix) or y < 0 or y >= len(matrix[0]):
                continue
            if matrix[x][y] <= matrix[i][j]:
                continue
            max_len = max(max_len, self.dfs(matrix, x, y, dp) + 1)
        dp[i][j] = max_len
        return dp[i][j]


# @lc code=end

sol = Solution()
matrix = [[9,9,4],[6,6,8],[2,1,1]]
print(sol.longestIncreasingPath(matrix))