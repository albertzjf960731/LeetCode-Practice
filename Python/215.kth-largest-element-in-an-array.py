#
# @lc app=leetcode id=215 lang=python
#
# [215] Kth Largest Element in an Array
#
# https://leetcode.com/problems/kth-largest-element-in-an-array/description/
#
# algorithms
# Medium (50.59%)
# Likes:    2596
# Dislikes: 199
# Total Accepted:    471K
# Total Submissions: 926.1K
# Testcase Example:  '[3,2,1,5,6,4]\n2'
#
# Find the kth largest element in an unsorted array. Note that it is the kth
# largest element in the sorted order, not the kth distinct element.
# 
# Example 1:
# 
# 
# Input: [3,2,1,5,6,4] and k = 2
# Output: 5
# 
# 
# Example 2:
# 
# 
# Input: [3,2,3,1,2,4,5,5,6] and k = 4
# Output: 4
# 
# Note: 
# You may assume k is always valid, 1 ≤ k ≤ array's length.
# 
#

# @lc code=start
class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        # return sorted(nums)[-k]

        # from queue import PriorityQueue
        # queue = PriorityQueue()

        # for num in nums:
        #     queue.put(num)
        #     if queue.qsize() > k:
        #         queue.get() 
        # return queue.get()

        return self.findKthSmallest(nums, len(nums)-k+1)

    def findKthSmallest(self, nums, k):
        left, right = 0, len(nums) - 1
        while left <= right:
            idx = self.partition(nums, left, right)
            if idx == k-1:
                return nums[idx]
            elif idx > k-1:
                right = idx - 1
            else:
                left = idx + 1
        return -1
    
    def partition(self, nums, left, right):
        l, r = left + 1, right
        while l <= r:
            if nums[l] < nums[left] and nums[r] > nums[left]:
                nums[l], nums[r] = nums[r], nums[l]
                l += 1
                r -= 1
            if nums[l] >= nums[left]:
                l += 1
            if nums[r] <= nums[left]:
                r -= 1
        nums[left], nums[r] = nums[r], nums[left]
        return r


        


# @lc code=end

sol = Solution()
nums = [3,2,1,5,6,4]
k = 6
print(sol.findKthLargest(nums, k))