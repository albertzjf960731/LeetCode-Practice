#
# @lc app=leetcode id=1508 lang=python3
#
# [1508] Range Sum of Sorted Subarray Sums
#
# https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/description/
#
# algorithms
# Medium (58.42%)
# Likes:    986
# Dislikes: 179
# Total Accepted:    51.1K
# Total Submissions: 84.6K
# Testcase Example:  '[1,2,3,4]\n4\n1\n5'
#
# You are given the array nums consisting of n positive integers. You computed
# the sum of all non-empty continuous subarrays from the array and then sorted
# them in non-decreasing order, creating a new array of n * (n + 1) / 2
# numbers.
# 
# Return the sum of the numbers from index left to index right (indexed from
# 1), inclusive, in the new array. Since the answer can be a huge number return
# it modulo 10^9 + 7.
# 
# 
# Example 1:
# 
# 
# Input: nums = [1,2,3,4], n = 4, left = 1, right = 5
# Output: 13 
# Explanation: All subarray sums are 1, 3, 6, 10, 2, 5, 9, 3, 7, 4. After
# sorting them in non-decreasing order we have the new array [1, 2, 3, 3, 4, 5,
# 6, 7, 9, 10]. The sum of the numbers from index le = 1 to ri = 5 is 1 + 2 + 3
# + 3 + 4 = 13. 
# 
# 
# Example 2:
# 
# 
# Input: nums = [1,2,3,4], n = 4, left = 3, right = 4
# Output: 6
# Explanation: The given array is the same as example 1. We have the new array
# [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index le = 3 to
# ri = 4 is 3 + 3 = 6.
# 
# 
# Example 3:
# 
# 
# Input: nums = [1,2,3,4], n = 4, left = 1, right = 10
# Output: 50
# 
# 
# 
# Constraints:
# 
# 
# n == nums.length
# 1 <= nums.length <= 1000
# 1 <= nums[i] <= 100
# 1 <= left <= right <= n * (n + 1) / 2
# 
# 
#

# @lc code=start
class Solution:
    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        pq = []
        for i, num in enumerate(nums):
            heapq.heappush(pq, (num, i))
        
        ans = 0
        mod = 1e9 + 7
        for i in range(1, right+1):
            num, idx = heapq.heappop(pq)
            print(num)

            if i >= left:
                ans = (ans + num) % mod
            
            if idx + 1 < n:
                heapq.heappush(pq, (num + nums[idx+1], idx+1))
        return int(ans)
# @lc code=end

