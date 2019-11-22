#
# @lc app=leetcode id=11 lang=python
#
# [11] Container With Most Water
#
# https://leetcode.com/problems/container-with-most-water/description/
#
# algorithms
# Medium (47.33%)
# Likes:    4169
# Dislikes: 484
# Total Accepted:    475.6K
# Total Submissions: 1M
# Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
#
# Given n non-negative integers a1, a2, ..., an , where each represents a point
# at coordinate (i, ai). n vertical lines are drawn such that the two endpoints
# of line i is at (i, ai) and (i, 0). Find two lines, which together with
# x-axis forms a container, such that the container contains the most water.
# 
# Note: You may not slant the container and n is at least 2.
# 
# 
# 
# 
# 
# The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In
# this case, the max area of water (blue section) the container can contain is
# 49. 
# 
# 
# 
# Example:
# 
# 
# Input: [1,8,6,2,5,4,8,3,7]
# Output: 49
#

# @lc code=start
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        # m = 0
        # for i in range(len(height) -1):
        #     for j in range(i, len(height)):
        #         m = max(m, min(height[i], height[j]) * (j-i))
        # return m


        # 前指针、后指针中间的区域为一个桶，桶的面积为高乘以宽，当i、j为两端时，桶宽最大，当i、j向中间滑动时，只有桶高增加，桶面积才有可能增大。若移动长板，桶高不可能增大，因此只能移动短板对应的指针。
        
        ans = 0
        l, r = 0, len(height)-1  
        while(l < r):
            ans = max(ans, min(height[l], height[r]) * (r - l))
            
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1

        return ans

# @lc code=end

