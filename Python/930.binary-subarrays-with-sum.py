#
# @lc app=leetcode id=930 lang=python3
#
# [930] Binary Subarrays With Sum
#
# https://leetcode.com/problems/binary-subarrays-with-sum/description/
#
# algorithms
# Medium (62.34%)
# Likes:    3872
# Dislikes: 133
# Total Accepted:    252K
# Total Submissions: 399.1K
# Testcase Example:  '[1,0,1,0,1]\n2'
#
# Given a binary array nums and an integer goal, return the number of non-empty
# subarrays with a sum goal.
# 
# A subarray is a contiguous part of the array.
# 
# 
# Example 1:
# 
# 
# Input: nums = [1,0,1,0,1], goal = 2
# Output: 4
# Explanation: The 4 subarrays are bolded and underlined below:
# [1,0,1,0,1]
# [1,0,1,0,1]
# [1,0,1,0,1]
# [1,0,1,0,1]
# 
# 
# Example 2:
# 
# 
# Input: nums = [0,0,0,0,0], goal = 0
# Output: 15
# 
# 
# 
# Constraints:
# 
# 
# 1 <= nums.length <= 3 * 10^4
# nums[i] is either 0 or 1.
# 0 <= goal <= nums.length
# 
#

# @lc code=start
class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        sum_cnts = {0: 1}
        cur_sum = 0
        ans = 0 
        for num in nums:
            cur_sum += num
            ans += sum_cnts.get(cur_sum - goal, 0)
            sum_cnts[cur_sum] = sum_cnts.get(cur_sum, 0) + 1
        return ans
# @lc code=end

