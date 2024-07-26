#
# @lc app=leetcode id=221 lang=python
#
# [221] Maximal Square
#
# https://leetcode.com/problems/maximal-square/description/
#
# algorithms
# Medium (34.74%)
# Likes:    1876
# Dislikes: 46
# Total Accepted:    168.3K
# Total Submissions: 484.5K
# Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
#
# Given a 2D binary matrix filled with 0's and 1's, find the largest square
# containing only 1's and return its area.
# 
# Example:
# 
# 
# Input: 
# 
# 1 0 1 0 0
# 1 0 1 1 1
# 1 1 1 1 1
# 1 0 0 1 0
# 
# Output: 4
# 
#

# @lc code=start
class Solution(object):
    def maximalSquare(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        if not matrix:
            return 0

        dp = [[0 for _ in range(len(matrix[0])+1)] for _ in range(len(matrix)+1)]

        ans = 0
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == '1':
                    # max length of square ending at (i, j)
                    dp[i+1][j+1] = min(dp[i][j], dp[i][j+1], dp[i+1][j])+1
                    ans = max(ans, dp[i+1][j+1])
        return ans*ans
# @lc code=end

sol = Solution()
matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
print(sol.maximalSquare(matrix))
