#
# @lc app=leetcode id=35 lang=python
#
# [35] Search Insert Position
#
# https://leetcode.com/problems/search-insert-position/description/
#
# algorithms
# Easy (41.25%)
# Likes:    1599
# Dislikes: 207
# Total Accepted:    472.6K
# Total Submissions: 1.1M
# Testcase Example:  '[1,3,5,6]\n5'
#
# Given a sorted array and a target value, return the index if the target is
# found. If not, return the index where it would be if it were inserted in
# order.
# 
# You may assume no duplicates in the array.
# 
# Example 1:
# 
# 
# Input: [1,3,5,6], 5
# Output: 2
# 
# 
# Example 2:
# 
# 
# Input: [1,3,5,6], 2
# Output: 1
# 
# 
# Example 3:
# 
# 
# Input: [1,3,5,6], 7
# Output: 4
# 
# 
# Example 4:
# 
# 
# Input: [1,3,5,6], 0
# Output: 0
# 
# 
#

# @lc code=start
class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        left, right = 0, len(nums) - 1  
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        
        # if nums[mid] < target:
        #     return mid + 1
        # else:
        #     return mid
        
        return left
# @lc code=end

sol = Solution()
nums = [1,3, 5, 6]
target = 2
print(sol.searchInsert(nums, target))