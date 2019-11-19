#
# @lc app=leetcode id=220 lang=python
#
# [220] Contains Duplicate III
#
# https://leetcode.com/problems/contains-duplicate-iii/description/
#
# algorithms
# Medium (20.23%)
# Likes:    815
# Dislikes: 826
# Total Accepted:    105.3K
# Total Submissions: 519.2K
# Testcase Example:  '[1,2,3,1]\n3\n0'
#
# Given an array of integers, find out whether there are two distinct indices i
# and j in the array such that the absolute difference between nums[i] and
# nums[j] is at most t and the absolute difference between i and j is at most
# k.
# 
# 
# Example 1:
# 
# 
# Input: nums = [1,2,3,1], k = 3, t = 0
# Output: true
# 
# 
# 
# Example 2:
# 
# 
# Input: nums = [1,0,1,1], k = 1, t = 2
# Output: true
# 
# 
# 
# Example 3:
# 
# 
# Input: nums = [1,5,9,1,5,9], k = 2, t = 3
# Output: false
# 
# 
# 
# 
#

# @lc code=start
class Solution(object):
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        """
        :type nums: List[int]
        :type k: int
        :type t: int
        :rtype: bool
        """

        # hash_dict = {}
        # for index, val in enumerate(nums):
        #     for v in range(val-t, val+t+1):
        #         if v in hash_dict:
        #             if index - hash_dict[v] <= k:
        #                 return True
        #     hash_dict[val] = index
        # return False

        # 桶排序
        if t < 0:
            return False 
            
        buckets = {}
        width = t + 1
        for index, num in enumerate(nums):
            bucket_index = num // width

            if bucket_index in buckets:
                return True
            if bucket_index-1 in buckets and abs(num - buckets[bucket_index-1])<width:
                return True
            if bucket_index+1 in buckets and (abs(num - buckets[bucket_index+1])<width):
                return True

            buckets[bucket_index] = num

            if index >= k: 
                del buckets[nums[index-k]//width]

        return False

# @lc code=end

sol = Solution()
nums = [1,5,9,1,5,9]
k = 2
t = 3
sol.containsNearbyAlmostDuplicate(nums, k, t)