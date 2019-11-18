#
# @lc app=leetcode id=169 lang=python
#
# [169] Majority Element
#
# https://leetcode.com/problems/majority-element/description/
#
# algorithms
# Easy (54.65%)
# Likes:    2129
# Dislikes: 184
# Total Accepted:    461.8K
# Total Submissions: 842.4K
# Testcase Example:  '[3,2,3]'
#
# Given an array of size n, find the majority element. The majority element is
# the element that appears more than ⌊ n/2 ⌋ times.
# 
# You may assume that the array is non-empty and the majority element always
# exist in the array.
# 
# Example 1:
# 
# 
# Input: [3,2,3]
# Output: 3
# 
# Example 2:
# 
# 
# Input: [2,2,1,1,1,2,2]
# Output: 2
# 
# 
#

# @lc code=start
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # return sorted(nums)[len(nums)//2]

        # hash_map = dict()
        # for num in nums:
        #     if num not in hash_map:
        #         hash_map[num] = 0
        #     hash_map[num] += 1
        #     if hash_map[num] > len(nums)//2:
        #         return num

        count = 0
        candidate = None

        for num in nums:
            if count == 0:
                candidate = num
            count += (1 if num == candidate else -1)

        return candidate
        
# @lc code=end

