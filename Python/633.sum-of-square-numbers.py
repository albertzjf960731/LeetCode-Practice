#
# @lc app=leetcode id=633 lang=python
#
# [633] Sum of Square Numbers
#
# https://leetcode.com/problems/sum-of-square-numbers/description/
#
# algorithms
# Easy (32.56%)
# Likes:    391
# Dislikes: 261
# Total Accepted:    53.4K
# Total Submissions: 163.9K
# Testcase Example:  '5'
#
# Given a non-negative integer c, your task is to decide whether there're two
# integers a and b such that a^2 + b^2 = c.
# 
# Example 1:
# 
# 
# Input: 5
# Output: True
# Explanation: 1 * 1 + 2 * 2 = 5
# 
# 
# 
# 
# Example 2:
# 
# 
# Input: 3
# Output: False
# 
# 
# 
# 
#

# @lc code=start
class Solution(object):
    def judgeSquareSum(self, c):
        """
        :type c: int
        :rtype: bool
        """

        l, r = 0, int(c**0.5)
        while l<=r:
            s = l**2 + r**2
            if s == c:
                return True
            elif s < c:
                l += 1
            else:
                r -= 1
        return False
        
# @lc code=end

sol = Solution()
print(sol.judgeSquareSum(1))