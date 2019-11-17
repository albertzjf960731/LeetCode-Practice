#
# @lc app=leetcode id=239 lang=python
#
# [239] Sliding Window Maximum
#
# https://leetcode.com/problems/sliding-window-maximum/description/
#
# algorithms
# Hard (39.80%)
# Likes:    2276
# Dislikes: 134
# Total Accepted:    199.8K
# Total Submissions: 500.1K
# Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
#
# Given an array nums, there is a sliding window of size k which is moving from
# the very left of the array to the very right. You can only see the k numbers
# in the window. Each time the sliding window moves right by one position.
# Return the max sliding window.
# 
# Example:
# 
# 
# Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
# Output: [3,3,5,5,6,7] 
# Explanation: 
# 
# Window position                Max
# ---------------               -----
# [1  3  -1] -3  5  3  6  7       3
# ⁠1 [3  -1  -3] 5  3  6  7       3
# ⁠1  3 [-1  -3  5] 3  6  7       5
# ⁠1  3  -1 [-3  5  3] 6  7       5
# ⁠1  3  -1  -3 [5  3  6] 7       6
# ⁠1  3  -1  -3  5 [3  6  7]      7
# 
# 
# Note: 
# You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty
# array.
# 
# Follow up:
# Could you solve it in linear time?
#

# @lc code=start
class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        # if not nums:
        #     return []
            
        # l, r = 0, k 
        # res = []
        # while r <= len(nums):


        #     res.append(max(nums[l:r])) 
            
        #     l += 1
        #     r += 1

        # return res
        
        # 递减窗口队列递减
        queue = []
        res = []

        for i, num in enumerate(nums):
            while queue and nums[queue[-1]] < num:
                queue.pop()

            queue.append(i) 

            if queue[0] == i-k:
                queue.pop(0)

            if i >= k-1:
                res.append(nums[queue[0]])
        return res 



# @lc code=end

sol = Solution()
nums = [1,3,-1,-3,5,3,6,7]
k = 3
# nums = [1]
# k = 1
print(sol.maxSlidingWindow(nums, k))