#
# @lc app=leetcode id=172 lang=python
#
# [172] Factorial Trailing Zeroes
#
# https://leetcode.com/problems/factorial-trailing-zeroes/description/
#
# algorithms
# Easy (37.64%)
# Likes:    586
# Dislikes: 835
# Total Accepted:    177.9K
# Total Submissions: 472.6K
# Testcase Example:  '3'
#
# Given an integer n, return the number of trailing zeroes in n!.
# 
# Example 1:
# 
# 
# Input: 3
# Output: 0
# Explanation: 3! = 6, no trailing zero.
# 
# Example 2:
# 
# 
# Input: 5
# Output: 1
# Explanation: 5! = 120, one trailing zero.
# 
# Note: Your solution should be in logarithmic time complexity.
# 
#

# @lc code=start
class Solution(object):
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        ans = 0
        divisor = 5
        while n >= divisor:
            ans += n // divisor
            divisor *= 5
        return ans 

# @lc code=end

sol = Solution()
num = 5
print(sol.trailingZeroes(num))