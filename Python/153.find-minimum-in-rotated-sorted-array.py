#
# @lc app=leetcode id=153 lang=python
#
# [153] Find Minimum in Rotated Sorted Array
#
# https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
#
# algorithms
# Medium (43.80%)
# Likes:    1328
# Dislikes: 187
# Total Accepted:    338.8K
# Total Submissions: 773.3K
# Testcase Example:  '[3,4,5,1,2]'
#
# Suppose an array sorted in ascending order is rotated at some pivot unknown
# to you beforehand.
# 
# (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
# 
# Find the minimum element.
# 
# You may assume no duplicate exists in the array.
# 
# Example 1:
# 
# 
# Input: [3,4,5,1,2] 
# Output: 1
# 
# 
# Example 2:
# 
# 
# Input: [4,5,6,7,0,1,2]
# Output: 0
# 
# 
#

# @lc code=start
class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # res = float('inf')
        # left, right = 0, len(nums) - 1
        # while left <= right:
        #     mid = (left + right) // 2
        #     res = min(nums[mid], res)

        #     if nums[mid] < nums[right]:
        #         right = mid - 1 
        #     else:
        #         left = mid + 1

        # return res        

        left, right = 0, len(nums) - 1
        while left < right:
            mid = (left + right) // 2
            # res = min(nums[mid], res)

            if nums[mid] < nums[right]:
                right = mid
            else:
                left = mid + 1

        return nums[left]       
# @lc code=end

sol = Solution()
nums = [4,5,6,7,0,1,2]
print(sol.findMin(nums))