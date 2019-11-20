#
# @lc app=leetcode id=238 lang=python
#
# [238] Product of Array Except Self
#
# https://leetcode.com/problems/product-of-array-except-self/description/
#
# algorithms
# Medium (57.25%)
# Likes:    3072
# Dislikes: 266
# Total Accepted:    339.6K
# Total Submissions: 590.9K
# Testcase Example:  '[1,2,3,4]'
#
# Given an array nums of n integers where n > 1,  return an array output such
# that output[i] is equal to the product of all the elements of nums except
# nums[i].
# 
# Example:
# 
# 
# Input:  [1,2,3,4]
# Output: [24,12,8,6]
# 
# 
# Note: Please solve it without division and in O(n).
# 
# Follow up:
# Could you solve it with constant space complexity? (The output array does not
# count as extra space for the purpose of space complexity analysis.)
# 
#

# @lc code=start
class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """

        res = []
        product = 1
        for i in range(len(nums)):
            res.append(product)
            product *= nums[i]

        product = 1
        for i in range(len(nums)-1,-1,-1):
            res[i] = res[i] * product
            product *= nums[i]
        return res

# @lc code=end

sol = Solution()
nums = [1,2,3,4]
print(sol.productExceptSelf(nums))