#
# @lc app=leetcode id=224 lang=python
#
# [224] Basic Calculator
#
# https://leetcode.com/problems/basic-calculator/description/
#
# algorithms
# Hard (34.48%)
# Likes:    994
# Dislikes: 106
# Total Accepted:    130.1K
# Total Submissions: 375.9K
# Testcase Example:  '"1 + 1"'
#
# Implement a basic calculator to evaluate a simple expression string.
# 
# The expression string may contain open ( and closing parentheses ), the plus
# + or minus sign -, non-negative integers and empty spaces  .
# 
# Example 1:
# 
# 
# Input: "1 + 1"
# Output: 2
# 
# 
# Example 2:
# 
# 
# Input: " 2-1 + 2 "
# Output: 3
# 
# Example 3:
# 
# 
# Input: "(1+(4+5+2)-3)+(6+8)"
# Output: 23
# Note:
# 
# 
# You may assume that the given expression is always valid.
# Do not use the eval built-in library function.
# 
# 
#

# @lc code=start
class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        stack = []
        num = 0

        cur = 0
        sign = 1
        for c in s:
            if c.isdigit():
                num = num * 10 + int(c)
            if c == "+":
                cur += sign * num
                num = 0
                sign = 1
            if c == '-':
                cur += sign * num
                num = 0
                sign = -1
            if c == '(':
                stack.append(cur)
                stack.append(sign)

                cur = 0
                sign = 1
            if c == ')':
                cur += sign * num
                cur = stack.pop() * cur + stack.pop() 

                num = 0
                sign = 1
        if num:
            cur += sign * num
        return cur

# @lc code=end

sol = Solution()
s = '3-(2+(9-4))'
print(sol.calculate(s))