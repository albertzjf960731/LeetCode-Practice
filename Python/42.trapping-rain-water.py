#
# @lc app=leetcode id=42 lang=python
#
# [42] Trapping Rain Water
#
# https://leetcode.com/problems/trapping-rain-water/description/
#
# algorithms
# Hard (45.43%)
# Likes:    4777
# Dislikes: 83
# Total Accepted:    372.8K
# Total Submissions: 820.6K
# Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
#
# Given n non-negative integers representing an elevation map where the width
# of each bar is 1, compute how much water it is able to trap after raining.
# 
# 
# The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In
# this case, 6 units of rain water (blue section) are being trapped. Thanks
# Marcos for contributing this image!
# 
# Example:
# 
# 
# Input: [0,1,0,2,1,0,1,3,2,1,2,1]
# Output: 6
# 
#

# @lc code=start
class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        # 按行求
        # if not height:
        #     return 0
        # res = 0 
        # for i in range(max(height)):
        #     temp = 0
        #     start = 0
        #     for j in range(len(height)):
        #         if start and height[j] <= i:
        #             temp += 1
        #         if height[j] > i:
        #             res += temp 
        #             temp = 0
        #             start = True
        # return res

        # # 按列求
        # res = 0
        # for i in range(1, len(height)-1):
            
        #     max_left = max(height[:i])
        #     max_right = max(height[i+1:])

        #     if min(max_left, max_right) > height[i]:
        #         res += (min(max_left, max_right)) - height[i]
        # return res

        res = 0
        max_left = [0 for _ in range(len(height))]
        max_right = [0 for _ in range(len(height))]
        for i in range(1, len(height)-1):
            max_left[i] = max(max_left[i-1], height[i-1])
        for i in range(len(height)-2, -1, -1):
            max_right[i] = max(max_right[i+1], height[i+1])
        for i in range(1, len(height)-1):
            h = min(max_left[i], max_right[i])
            if h > height[i]:
                res += h - height[i]
        return res

        # # 双指针
        # res = 0
        # left = 1
        # right = len(height) - 2
        # max_left, max_right = 0, 0
        # for i in range(1, len(height)-1):
        #     if height[left-1] < height[right+1] :
        #         max_left = max(max_left, height[left-1])
        #         if max_left > height[left]:
        #             res += (max_left - height[left])
        #         left += 1
        #     else:
        #         max_right = max(max_right, height[right+1])
        #         if max_right > height[right]:
        #             res += max_right - height[right]
        #         right -= 1
        # return res

        # # 栈
        ans = 0
        monostack = []
        for i in range(len(height)):
            while monostack and height[i] > height[monostack[-1]]:
                h = height[monostack.pop()]
                if not monostack:
                    break
                w = i - monostack[-1] - 1
                ans += w * (min(height[i], height[monostack[-1]]) - h)
            monostack.append(i)
        return ans

# @lc code=end

sol = Solution()
height = [0,1,0,2,1,0,1,3,2,1,2,1]
print(sol.trap(height))