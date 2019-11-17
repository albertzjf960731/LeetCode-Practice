#
# @lc app=leetcode id=60 lang=python
#
# [60] Permutation Sequence
#
# https://leetcode.com/problems/permutation-sequence/description/
#
# algorithms
# Medium (34.46%)
# Likes:    1046
# Dislikes: 269
# Total Accepted:    155.2K
# Total Submissions: 449.8K
# Testcase Example:  '3\n3'
#
# The set [1,2,3,...,n] contains a total of n! unique permutations.
# 
# By listing and labeling all of the permutations in order, we get the
# following sequence for n = 3:
# 
# 
# "123"
# "132"
# "213"
# "231"
# "312"
# "321"
# 
# 
# Given n and k, return the k^th permutation sequence.
# 
# Note:
# 
# 
# Given n will be between 1 and 9 inclusive.
# Given k will be between 1 and n! inclusive.
# 
# 
# Example 1:
# 
# 
# Input: n = 3, k = 3
# Output: "213"
# 
# 
# Example 2:
# 
# 
# Input: n = 4, k = 9
# Output: "2314"
# 
# 
#

# @lc code=start
class Solution(object):
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
    #     nums = [i+1 for i in range(n)]
    #     for _ in range(k-1):
    #         self.nextPermutation(nums)
    #     return ''.join(str(c) for c in nums)
    
    # def nextPermutation(self, nums):
    #     """
    #     :type nums: List[int]
    #     :rtype: None Do not return anything, modify nums in-place instead.
    #     """
    #     i = len(nums) -2 
    #     while i>=0 and nums[i+1] <= nums[i]:
    #         i -= 1
    #     if i <0:
    #         self.reverse(nums, 0)
    #         return 
    #     j = len(nums) -1 
    #     while j>=0 and nums[j] <= nums[i]:
    #         j -= 1
        
    #     self.swap(nums, i, j)

    #     self.reverse(nums, i+1)
    
    # def swap(self, nums, i, j):
    #     # temp = nums[i]
    #     # nums[i] = nums[j]
    #     # nums[j] = temp   
    #     nums[i], nums[j] = nums[j], nums[i]  

    # def reverse(self, nums, start):
    #     i = start
    #     j = len(nums)-1
    #     while i<j:
    #         self.swap(nums, i, j)
    #         i+=1
    #         j-=1

        nums = [i+1 for i in range(n)]
        factorial = 1
        for i in range(1, n+1):
            factorial *= (i)
        
        res = []
        k -= 1
        for i in range(n, 0, -1):
            factorial = factorial // i 
            num_group = k // factorial
            k = k % factorial
            
            num = nums[num_group]
            res.append(num)
            nums.remove(num)
            
        return ''.join(str(c) for c in res)

        



# @lc code=end

sol = Solution()
print(sol.getPermutation(4, 9))