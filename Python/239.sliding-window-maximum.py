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
        ans = []
        pq = []
        for i in range(k):
            heapq.heappush(pq, (-nums[i], i))
        ans.append(-pq[0][0])

        for i in range(k, len(nums)):
            heapq.heappush(pq, (-nums[i], i))

            while pq[0][1] <= i - k:
                heapq.heappop(pq)
            ans.append(-pq[0][0])
        return ans
        

        # monoqueue
        monoqueue = deque()
        ans = []

        for i, num in enumerate(nums):
            while monoqueue and nums[monoqueue[-1]] < num:
                monoqueue.pop()
            monoqueue.append(i)

            if monoqueue[0] == i - k:
                monoqueue.popleft()
            if i >= k-1:
                ans.append(nums[monoqueue[0]])
        return ans


# @lc code=end

sol = Solution()
nums = [1,3,-1,-3,5,3,6,7]
k = 3
# nums = [1]
# k = 1
print(sol.maxSlidingWindow(nums, k))