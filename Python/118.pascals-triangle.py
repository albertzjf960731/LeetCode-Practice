#
# @lc app=leetcode id=118 lang=python
#
# [118] Pascal's Triangle
#
# https://leetcode.com/problems/pascals-triangle/description/
#
# algorithms
# Easy (48.55%)
# Likes:    909
# Dislikes: 84
# Total Accepted:    302.4K
# Total Submissions: 621.7K
# Testcase Example:  '5'
#
# Given a non-negative integer numRows, generate the first numRows of Pascal's
# triangle.
# 
# 
# In Pascal's triangle, each number is the sum of the two numbers directly
# above it.
# 
# Example:
# 
# 
# Input: 5
# Output:
# [
# ⁠    [1],
# ⁠   [1,1],
# ⁠  [1,2,1],
# ⁠ [1,3,3,1],
# ⁠[1,4,6,4,1]
# ]
# 
# 
#

# @lc code=start
class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        # if numRows == 1:
        #     return [[1]]
        # if numRows == 2:
        #     return [[1], [1, 1]]

        triangle = [[1] * (i+1) for i in range(numRows)]
        for i in range(2, numRows):
            for j in range(1, i):
                triangle[i][j] = triangle[i-1][j-1]+triangle[i-1][j]
            
        return triangle
# @lc code=end

sol = Solution()
sol.generate(3)