#
# @lc app=leetcode id=2799 lang=python3
#
# [2799] Count Complete Subarrays in an Array
#
# https://leetcode.com/problems/count-complete-subarrays-in-an-array/description/
#
# algorithms
# Medium (65.10%)
# Likes:    556
# Dislikes: 13
# Total Accepted:    40.4K
# Total Submissions: 62K
# Testcase Example:  '[1,3,1,2,2]'
#
# You are given an array nums consisting of positive integers.
# 
# We call a subarray of an array complete if the following condition is
# satisfied:
# 
# 
# The number of distinct elements in the subarray is equal to the number of
# distinct elements in the whole array.
# 
# 
# Return the number of complete subarrays.
# 
# A subarray is a contiguous non-empty part of an array.
# 
# 
# Example 1:
# 
# 
# Input: nums = [1,3,1,2,2]
# Output: 4
# Explanation: The complete subarrays are the following: [1,3,1,2],
# [1,3,1,2,2], [3,1,2] and [3,1,2,2].
# 
# 
# Example 2:
# 
# 
# Input: nums = [5,5,5,5]
# Output: 10
# Explanation: The array consists only of the integer 5, so any subarray is
# complete. The number of subarrays that we can choose is 10.
# 
# 
# 
# Constraints:
# 
# 
# 1 <= nums.length <= 1000
# 1 <= nums[i] <= 2000
# 
# 
#

# @lc code=start
class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        cnt = len(set(nums))
        sub_cnts = {}
        ans = 0

        left, right = 0, 0
        while right < len(nums):
            sub_cnts[nums[right]] = sub_cnts.get(nums[right], 0) + 1

            while len(sub_cnts) == cnt:    
                # ans += len(nums) - right
                
                sub_cnts[nums[left]] -= 1
                if sub_cnts[nums[left]] == 0:
                    sub_cnts.pop(nums[left])
                left += 1
            # left is the first element that makes the subarray incomplete
            ans += left
            right += 1
        return ans

# @lc code=end

