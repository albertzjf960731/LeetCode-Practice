#
# @lc app=leetcode id=260 lang=python
#
# [260] Single Number III
#
# https://leetcode.com/problems/single-number-iii/description/
#
# algorithms
# Medium (58.57%)
# Likes:    1055
# Dislikes: 85
# Total Accepted:    119.4K
# Total Submissions: 203.4K
# Testcase Example:  '[1,2,1,3,2,5]'
#
# Given an array of numbers nums, in which exactly two elements appear only
# once and all the other elements appear exactly twice. Find the two elements
# that appear only once.
# 
# Example:
# 
# 
# Input:  [1,2,1,3,2,5]
# Output: [3,5]
# 
# Note:
# 
# 
# The order of the result is not important. So in the above example, [5, 3] is
# also correct.
# Your algorithm should run in linear runtime complexity. Could you implement
# it using only constant space complexity?
# 
#

# @lc code=start
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # hash_set = set()
        # for num in nums:
        #     if num not in hash_set:
        #         hash_set.add(num)
        #     else:
        #         hash_set.remove(num)
        
        # return list(hash_set)
        
        xor = 0
        for num in nums:
            xor ^= num 
        # xor = xor & (xor-1) ^ xor 
        xor &= -xor
        a = b = 0
        for num in nums:
            if xor & num:
                a ^= num
            else:
                b ^= num 
        return [a, b]

# @lc code=end

sol = Solution()
nums = [1,2,1,3,2,5]
print(sol.singleNumber(nums))