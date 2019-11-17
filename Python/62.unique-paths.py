#
# @lc app=leetcode id=62 lang=python
#
# [62] Unique Paths
#
# https://leetcode.com/problems/unique-paths/description/
#
# algorithms
# Medium (49.85%)
# Likes:    2057
# Dislikes: 152
# Total Accepted:    352.7K
# Total Submissions: 706.3K
# Testcase Example:  '3\n2'
#
# A robot is located at the top-left corner of a m x n grid (marked 'Start' in
# the diagram below).
# 
# The robot can only move either down or right at any point in time. The robot
# is trying to reach the bottom-right corner of the grid (marked 'Finish' in
# the diagram below).
# 
# How many possible unique paths are there?
# 
# 
# Above is a 7 x 3 grid. How many possible unique paths are there?
# 
# Note: m and n will be at most 100.
# 
# Example 1:
# 
# 
# Input: m = 3, n = 2
# Output: 3
# Explanation:
# From the top-left corner, there are a total of 3 ways to reach the
# bottom-right corner:
# 1. Right -> Right -> Down
# 2. Right -> Down -> Right
# 3. Down -> Right -> Right
# 
# 
# Example 2:
# 
# 
# Input: m = 7, n = 3
# Output: 28
# 
#

# @lc code=start
class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        # matrix = [[1]*n for _ in range(m)]

        # for i in range(m):
        #     matrix[i][0] = i 
        # for j in range(n):
        #     matrix[0][j] = j

        # for i in range(1, m):
        #     for j in range(1, n):
        #         matrix[i][j] = matrix[i-1][j] + matrix[i][j-1]
        # return matrix[m-1][n-1]


        dp = [1 for _ in range(n)]
        for i in range(1, m):
            for j in range(1, n):
                dp[j] = dp[j] + dp[j-1]
        return dp[-1]

# @lc code=end

sol = Solution()
sol.uniquePaths(3, 2)