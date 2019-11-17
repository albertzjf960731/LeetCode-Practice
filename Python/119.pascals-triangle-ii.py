#
# @lc app=leetcode id=119 lang=python
#
# [119] Pascal's Triangle II
#
# https://leetcode.com/problems/pascals-triangle-ii/description/
#
# algorithms
# Easy (45.72%)
# Likes:    573
# Dislikes: 182
# Total Accepted:    233.7K
# Total Submissions: 510.2K
# Testcase Example:  '3'
#
# Given a non-negative index k where k ≤ 33, return the k^th index row of the
# Pascal's triangle.
# 
# Note that the row index starts from 0.
# 
# 
# In Pascal's triangle, each number is the sum of the two numbers directly
# above it.
# 
# Example:
# 
# 
# Input: 3
# Output: [1,3,3,1]
# 
# 
# Follow up:
# 
# Could you optimize your algorithm to use only O(k) extra space?
# 
#

# @lc code=start
class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        
        # triangle = [[1] * (i+1) for i in range(rowIndex+1)]
        # for i in range(2, rowIndex+1):
        #     for j in range(1, i):
        #         triangle[i][j] = triangle[i-1][j-1]+triangle[i-1][j]
            
        # return triangle[-1]


        pascal = [1] * (rowIndex + 1)
        for i in range(1, rowIndex):
            for j in range(i, 0, -1):
                pascal[j] += pascal[j-1]
        return pascal

# @lc code=end

sol = Solution()
print(sol.getRow(4))