#
# @lc app=leetcode id=325 lang=python3
#
# [325] Maximum Size Subarray Sum Equals k
#
# https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/description/
#
# algorithms
# Medium (49.50%)
# Likes:    2038
# Dislikes: 64
# Total Accepted:    186.6K
# Total Submissions: 376.5K
# Testcase Example:  '[1,-1,5,-2,3]\n3'
#
# Given an integer array nums and an integer k, return the maximum length of a
# subarray that sums to k. If there is not one, return 0 instead.
# 
# 
# Example 1:
# 
# 
# Input: nums = [1,-1,5,-2,3], k = 3
# Output: 4
# Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.
# 
# 
# Example 2:
# 
# 
# Input: nums = [-2,-1,2,1], k = 1
# Output: 2
# Explanation: The subarray [-1, 2] sums to 1 and is the longest.
# 
# 
# 
# Constraints:
# 
# 
# 1 <= nums.length <= 2 * 10^5
# -10^4 <= nums[i] <= 10^4
# -10^9 <= k <= 10^9
# 
# 
#

# @lc code=start
class Solution:
    def maxSubArrayLen(self, nums: List[int], k: int) -> int:
        sum2idx = {0: -1}
        max_len = 0
        cur_sum = 0
        for i, num in enumerate(nums):
            cur_sum += num
            if cur_sum - k in sum2idx:
                max_len = max(max_len, i - sum2idx[cur_sum - k])
            if cur_sum not in sum2idx:
                sum2idx[cur_sum] = i
        return max_len
# @lc code=end

