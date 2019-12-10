#
# @lc app=leetcode id=179 lang=python
#
# [179] Largest Number
#
# https://leetcode.com/problems/largest-number/description/
#
# algorithms
# Medium (26.99%)
# Likes:    1338
# Dislikes: 167
# Total Accepted:    150.8K
# Total Submissions: 558.6K
# Testcase Example:  '[10,2]'
#
# Given a list of non negative integers, arrange them such that they form the
# largest number.
# 
# Example 1:
# 
# 
# Input: [10,2]
# Output: "210"
# 
# Example 2:
# 
# 
# Input: [3,30,34,5,9]
# Output: "9534330"
# 
# 
# Note: The result may be very large, so you need to return a string instead of
# an integer.
# 
#

# @lc code=start
class Solution(object):
    def largestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
    #     for i in range(len(nums), 0, -1):
    #         for j in range(i-1):
    #             if not self.compare(nums[j], nums[j+1]):
    #                 nums[j], nums[j+1] = nums[j+1], nums[j]
    #     return str(int("".join(map(str, nums))))
        
    # def compare(self, n1, n2):
    #     return str(n1) + str(n2) > str(n2) + str(n1)
 
        if not any(nums):
            return "0"
        return "".join(sorted(map(str, nums), cmp=lambda n1, n2: -1 if n1+n2>n2+n1 else (1 if n1+n2<n2+n1 else 0)))

# @lc code=end

