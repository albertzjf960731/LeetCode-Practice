#
# @lc app=leetcode id=85 lang=python
#
# [85] Maximal Rectangle
#
# https://leetcode.com/problems/maximal-rectangle/description/
#
# algorithms
# Hard (34.99%)
# Likes:    1854
# Dislikes: 55
# Total Accepted:    141.4K
# Total Submissions: 403.4K
# Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
#
# Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
# containing only 1's and return its area.
# 
# Example:
# 
# 
# Input:
# [
# ⁠ ["1","0","1","0","0"],
# ⁠ ["1","0","1","1","1"],
# ⁠ ["1","1","1","1","1"],
# ⁠ ["1","0","0","1","0"]
# ]
# Output: 6
# 
# 
#

# @lc code=start
class Solution(object):
    def maximalRectangle(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """

        # 暴力
        # if not matrix:
        #     return 0 
        # width = [[0 for _ in range(len(matrix[0]))] for _ in range(len(matrix))]
        # max_area = 0 
        
        # for i in range(len(matrix)):
        #     for j in range(len(matrix[0])):
        #         if matrix[i][j] == '1':
        #             if j == 0:
        #                 width[i][j] = 1
        #             else:
        #                 width[i][j] = width[i][j-1] +1
        #         else:
        #             width[i][j] = 0

        #         min_width = width[i][j]
        #         for k in range(i, -1, -1):
        #             heigth = i - k + 1
        #             min_width = min(min_width, width[k][j])
        #             max_area = max(max_area, heigth * min_width)
        # return max_area

    #     if not matrix:
    #         return 0 
    #     max_area = 0
    #     heights = [0 for _ in range(len(matrix[0]))]
    #     for i in range(len(matrix)):
    #         for j in range(len(matrix[0])):
    #             if matrix[i][j] == '1':
    #                 heights[j] += 1
    #             else:
    #                 heights[j] = 0
    #         max_area = max(max_area, self.largestRectangleArea(heights))
    #     return max_area

    # def largestRectangleArea(self, heights):
    #     heights.append(0)   
    #     stack = [-1]    
    #     max_area = 0    
    #     for i in range(len(heights)):
    #         while heights[i] < heights[stack[-1]]:
    #             h = heights[stack.pop()]
    #             w = i - stack[-1] - 1
    #             max_area = max(max_area, h*w)
    #         stack.append(i)
    #     heights.pop()
    #     return max_area


        # if not matrix:
        #     return 0 
        # max_area = 0
        
        # heights = [0 for _ in range(len(matrix[0])+1)]
        # for i in range(len(matrix)):
        #     stack = [-1]

        #     for j in range(len(heights)):
        #         if j < len(matrix[0]):
        #             if matrix[i][j] == '1':
        #                 heights[j] += 1
        #             else:
        #                 heights[j] = 0
                
        #         while heights[j] < heights[stack[-1]]:
        #             h = heights[stack.pop()]
        #             w = j - stack[-1] - 1
        #             max_area = max(max_area, h*w)
        #         stack.append(j)

        # return max_area


        # 动态规划

# @lc code=end

sol = Solution()
matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
print(sol.maximalRectangle(matrix))