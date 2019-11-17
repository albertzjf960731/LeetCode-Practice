#
# @lc app=leetcode id=31 lang=python
#
# [31] Next Permutation
#
# https://leetcode.com/problems/next-permutation/description/
#
# algorithms
# Medium (31.27%)
# Likes:    2362
# Dislikes: 785
# Total Accepted:    289K
# Total Submissions: 922.4K
# Testcase Example:  '[1,2,3]'
#
# Implement next permutation, which rearranges numbers into the
# lexicographically next greater permutation of numbers.
# 
# If such arrangement is not possible, it must rearrange it as the lowest
# possible order (ie, sorted in ascending order).
# 
# The replacement must be in-place and use only constant extra memory.
# 
# Here are some examples. Inputs are in the left-hand column and its
# corresponding outputs are in the right-hand column.
# 
# 1,2,3 → 1,3,2
# 3,2,1 → 1,2,3
# 1,1,5 → 1,5,1
# 
#

# @lc code=start
class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        i = len(nums) -2 
        while i>=0 and nums[i] >= nums[i+1]:
            i -= 1
        if i <0:
            self.reverse(nums, 0)
            return 

        j = len(nums) -1 
        while j>=0 and nums[j] <= nums[i]:
            j -= 1
        
        self.swap(nums, i, j)

        self.reverse(nums, i+1)
    
    def swap(self, nums, i, j):
        # temp = nums[i]
        # nums[i] = nums[j]
        # nums[j] = temp   
        nums[i], nums[j] = nums[j], nums[i]  

    def reverse(self, nums, start):
        i = start
        j = len(nums)-1
        while i<j:
            self.swap(nums, i, j)
            i+=1
            j-=1   
# @lc code=end

sol = Solution()
nums = [1,3,2]
sol.nextPermutation(nums)
print(nums)
