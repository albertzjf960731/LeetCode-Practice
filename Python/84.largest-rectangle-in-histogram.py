#
# @lc app=leetcode id=84 lang=python
#
# [84] Largest Rectangle in Histogram
#
# https://leetcode.com/problems/largest-rectangle-in-histogram/description/
#
# algorithms
# Hard (32.60%)
# Likes:    2469
# Dislikes: 63
# Total Accepted:    205K
# Total Submissions: 627.8K
# Testcase Example:  '[2,1,5,6,2,3]'
#
# Given n non-negative integers representing the histogram's bar height where
# the width of each bar is 1, find the area of largest rectangle in the
# histogram.
# 
# 
# 
# 
# Above is a histogram where width of each bar is 1, given height =
# [2,1,5,6,2,3].
# 
# 
# 
# 
# The largest rectangle is shown in the shaded area, which has area = 10
# unit.
# 
# 
# 
# Example:
# 
# 
# Input: [2,1,5,6,2,3]
# Output: 10
# 
# 
#

# @lc code=start
class Solution(object):
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        # 暴力
        # height_set = set(heights)  
        # max_area = 0 

        # for h in height_set:
        #     width = 0
        #     max_width = 1   
        #     for i in range(len(heights)):
        #         if heights[i] >= h:
        #             width += 1  
        #         else:
        #             max_width = max(width, max_width)
        #             width = 0

        #     max_width = max(width, max_width)
        #     max_area = max(max_area, h* max_width)

  
        # return max_area

        
        # if len(heights) == 0:
        #     return 0
        # left_less = [-1 for _ in range(len(heights))]
        # # left_less[0] = -1
        # for i in range(1, len(heights)):
        #     l = i-1
        #     while l>=0 and heights[l]>=heights[i]:
        #         l = left_less[l]
        #         # l -= 1
        #     left_less[i] = l
        
        # right_less = [len(heights) for _ in range(len(heights))]
        # # right_less[len(heights)-1] = len(heights)
        # for i in range(len(heights)-2, -1, -1):
        #     r = i+1
        #     while r < len(heights) and heights[r] >= heights[i]:
        #         r = right_less[r]
        #     right_less[i] = r
        
        # max_area = 0
        # for i in range(len(heights)):
        #     area = (right_less[i]-left_less[i]-1) * heights[i]
        #     max_area = max(area, max_area)  
        # return max_area

        # 栈
        # 只需要遍历所有直方柱，寻找以这个直方柱为高，可向左右扩展出的最大长方形面积，那么我们只需要找到对于每个 i ，其左/右边第一个比他矮的直方柱的下标，相当于就找到了以第 i 个直方柱为高，可向左右扩展的最远距离。

        # 如果当前栈空，或者当前柱子大于栈顶柱子的高度，就将当前柱子的下标入栈
        # 当前柱子的高度小于栈顶柱子的高度。那么就把栈顶柱子出栈，当做解法四中的当前要求面积的柱子。而右边第一个小于当前柱子的下标就是当前在遍历的柱子，左边第一个小于当前柱子的下标就是当前新的栈顶。

        heights.append(0)   
        stack = [-1]    
        ans = 0    
        for i in range(len(heights)):
            while heights[i] < heights[stack[-1]]:
                h = heights[stack.pop()]
                w = i - stack[-1] - 1
                ans = max(ans, h*w)
            stack.append(i)
        # heights.pop()
        return ans

# @lc code=end

sol = Solution()
heights = [2,1,5,6,2,3]
print(sol.largestRectangleArea(heights))