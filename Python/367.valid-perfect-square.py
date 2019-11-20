#
# @lc app=leetcode id=367 lang=python
#
# [367] Valid Perfect Square
#
# https://leetcode.com/problems/valid-perfect-square/description/
#
# algorithms
# Easy (40.51%)
# Likes:    550
# Dislikes: 125
# Total Accepted:    132.6K
# Total Submissions: 326.8K
# Testcase Example:  '16'
#
# Given a positive integer num, write a function which returns True if num is a
# perfect square else False.
# 
# Note: Do not use any built-in library function such as sqrt.
# 
# Example 1:
# 
# 
# 
# Input: 16
# Output: true
# 
# 
# 
# Example 2:
# 
# 
# Input: 14
# Output: false
# 
# 
# 
#

# @lc code=start
class Solution(object):
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        # 会产生一个list

        # for i in range(1, num+1):
        # i = 1
        # while True:
        #     if i*i == num:
        #         return True
        #     elif i*i > num:
        #         return False
        #     i += 1

        # l, r = 0, num
        # while l<=r:
        #     m = (l+r) // 2
        #     if m ** 2 == num:
        #         return True
        #     elif m** 2 > num:
        #         r = m-1
        #     else:
        #         l = m+1
        # return False

        sub = 1
        while num > 0:
            num -= sub
            sub += 2
        return num == 0
# @lc code=end
sol = Solution()
print(sol.isPerfectSquare(5))
