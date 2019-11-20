#
# @lc app=leetcode id=540 lang=python
#
# [540] Single Element in a Sorted Array
#
# https://leetcode.com/problems/single-element-in-a-sorted-array/description/
#
# algorithms
# Medium (57.50%)
# Likes:    935
# Dislikes: 66
# Total Accepted:    69.8K
# Total Submissions: 121.3K
# Testcase Example:  '[1,1,2,3,3,4,4,8,8]'
#
# You are given a sorted array consisting of only integers where every element
# appears exactly twice, except for one element which appears exactly once.
# Find this single element that appears only once.
# 
# 
# 
# Example 1:
# 
# 
# Input: [1,1,2,3,3,4,4,8,8]
# Output: 2
# 
# 
# Example 2:
# 
# 
# Input: [3,3,7,7,10,11,11]
# Output: 10
# 
# 
# 
# 
# Note: Your solution should run in O(log n) time and O(1) space.
# 
#

# @lc code=start
class Solution(object):
    def singleNonDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # ans = 0
        # for num in nums:
        #     ans ^= num
        # return ans

        l, r = 0, len(nums)-1

        while l<r:
            m = (l+r) // 2
            if m%2 == 1:
                m -= 1
            if nums[m] == nums[m+1]:
                l = m+2 
            else:
                r = m
        return nums[l]
        
# @lc code=end

sol = Solution()
nums = [1,1,2,3,3,4,4,8,8]
print(sol.singleNonDuplicate(nums))