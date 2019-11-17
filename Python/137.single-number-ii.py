#
# @lc app=leetcode id=137 lang=python
#
# [137] Single Number II
#
# https://leetcode.com/problems/single-number-ii/description/
#
# algorithms
# Medium (47.55%)
# Likes:    1035
# Dislikes: 282
# Total Accepted:    185K
# Total Submissions: 388.9K
# Testcase Example:  '[2,2,3,2]'
#
# Given a non-empty array of integers, every element appears three times except
# for one, which appears exactly once. Find that single one.
# 
# Note:
# 
# Your algorithm should have a linear runtime complexity. Could you implement
# it without using extra memory?
# 
# Example 1:
# 
# 
# Input: [2,2,3,2]
# Output: 3
# 
# 
# Example 2:
# 
# 
# Input: [0,1,0,1,0,1,99]
# Output: 99
# 
#

# @lc code=start
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # hash_dict = dict()
        # for num in nums:
        #     if num not in hash_dict:
        #         hash_dict[num] = 1
        #     else:
        #         hash_dict[num] += 1

        # for v, k in hash_dict.items():
        #     if k == 1:
        #         return v
        
        # hash_set = set()
        # sum = 0
        # for num in nums:
        #     hash_set.add(num)
        #     sum += num
        # for num in hash_set:
        #     sum -= num*3
        # return sum / -2
        
        # x1, x2 = 0, 0
        # mask = 0
        # for num in nums:
        #     x2 = x2 ^ (x1 & num)
        #     x1 = x1 ^ num 

        #     mask = ~(x1 & x2)

        #     x2 = x2 & mask 
        #     x1 = x1 & mask
        # return x1

        one, two = 0, 0
        for num in nums:
            one = (one ^ num) & ~two
            two = (two ^ num) & ~one
        return one

# @lc code=end

sol = Solution()
nums = [1, 2, 6, 1, 1, 2, 2, 3, 3, 3]
print(sol.singleNumber(nums))