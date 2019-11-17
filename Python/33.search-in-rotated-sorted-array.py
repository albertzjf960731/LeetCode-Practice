#
# @lc app=leetcode id=33 lang=python
#
# [33] Search in Rotated Sorted Array
#
# https://leetcode.com/problems/search-in-rotated-sorted-array/description/
#
# algorithms
# Medium (33.31%)
# Likes:    3159
# Dislikes: 371
# Total Accepted:    506.9K
# Total Submissions: 1.5M
# Testcase Example:  '[4,5,6,7,0,1,2]\n0'
#
# Suppose an array sorted in ascending order is rotated at some pivot unknown
# to you beforehand.
# 
# (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
# 
# You are given a target value to search. If found in the array return its
# index, otherwise return -1.
# 
# You may assume no duplicate exists in the array.
# 
# Your algorithm's runtime complexity must be in the order of O(log n).
# 
# Example 1:
# 
# 
# Input: nums = [4,5,6,7,0,1,2], target = 0
# Output: 4
# 
# 
# Example 2:
# 
# 
# Input: nums = [4,5,6,7,0,1,2], target = 3
# Output: -1
# 
#

# @lc code=start
class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        # if not nums:
        #     return -1
        # middle = len(nums) // 2
        # if target == nums[middle]:
        #     return middle
        # elif target < nums[middle]:
        #     return self.search(nums[:middle], target)
        # else:
        #     return self.search(nums[middle+1:], target) + middle+1
        # return self.bi_search(nums, 0, len(nums)-1, target)

    # def bi_search(self, nums, start, end, target):
    #     middle = (end-start) // 2 + start

    #     if nums[middle] == target:
    #         return middle
    #     elif start == end:
    #         return -1
    #     elif target < nums[middle]:
    #         return self.bi_search(nums, start, middle-1, target)
    #     else:
    #         return self.bi_search(nums, middle+1, end, target)

        # left, right = 0, len(nums)-1    
        # while left <= right:
        #     mid = left + (right-left) // 2   
        #     num = nums[mid]
        #     if (nums[mid] < nums[0]) == (target < nums[0]):
        #         num = nums[mid]
        #     else:
        #         num = float('-inf') if target < nums[0] else float('inf')

        #     if target == num:
        #         return mid
        #     elif target > num:
        #         left = mid + 1
        #     elif target < num:
        #         right = mid - 1

        # return -1
        
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = (left + right) // 2
            if target == nums[mid]:
                return mid
            
            # 左半段是有序的
            if nums[left] <= nums[mid]:
                if nums[left] <= target and target <=nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
            
            # 右半段是有序的
            else:
                if nums[mid] <= target and target <= nums[right]:
                    left = mid + 1  
                else:
                    right = mid - 1
        return -1

# @lc code=end

sol = Solution()
# nums =[4,5,6,7,0,1,2]
nums = [4,5,6,7,0,1,2]
target = 1
print(sol.search(nums, target))