#
# @lc app=leetcode id=41 lang=python
#
# [41] First Missing Positive
#
# https://leetcode.com/problems/first-missing-positive/description/
#
# algorithms
# Hard (30.08%)
# Likes:    2266
# Dislikes: 666
# Total Accepted:    256.9K
# Total Submissions: 853.1K
# Testcase Example:  '[1,2,0]'
#
# Given an unsorted integer array, find the smallest missing positive integer.
# 
# Example 1:
# 
# 
# Input: [1,2,0]
# Output: 3
# 
# 
# Example 2:
# 
# 
# Input: [3,4,-1,1]
# Output: 2
# 
# 
# Example 3:
# 
# 
# Input: [7,8,9,11,12]
# Output: 1
# 
# 
# Note:
# 
# Your algorithm should run in O(n) time and uses constant extra space.
# 
#

# @lc code=start
class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums or min(nums)>1 or max(nums)<1:
            return 1
        
        i = 1
        while i < max(nums)+2:
            if i not in nums:
                return i
            i += 1

# @lc code=end


sol = Solution()
nums = 