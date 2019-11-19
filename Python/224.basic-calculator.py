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
        # ans = 0
        # stack = []

        # for c in s:
        #     if c.isdigit():
        #         ans = ord(c)-ord('0')
        #         while stack and stack[-1]!='(':
        #             op = stack.pop()
        #             num1 = stack.pop()
        #             if op == '+':
        #                 ans = num1 + ans
        #             elif op == '-':
        #                 ans = num1 - ans
        #         stack.append(ans)

        #     elif c in ('+-('):
        #         stack.append(c)

        #     elif c == ')':
        #         ans = stack.pop()
        #         stack.pop()
        #         while stack and stack[-1]!='(':
        #             op = stack.pop()
        #             num1 = stack.pop()
        #             if op == '+':
        #                 ans = num1 + ans
        #             elif op == '-':
        #                 ans = num1 - ans
        #         stack.append(ans)

        #     elif c == ' ':
        #         continue

        # return stack[-1]

        # i = 0
        # ans = 0
        # signs = [1, 1]
        # while i < len(s):
        #     c = s[i]

        #     if c.isdigit():
        #         start = i
        #         while i < len(s) and s[i].isdigit():
        #             i+=1
        #         ans += signs.pop() * int(s[start:i])
        #         continue
        #     if c in '+-(':
        #         signs.append(signs[-1] * (1, -1)[c=='-'])
        #     if c == ')':
        #         signs.pop()
        #     i += 1
        # return ans

        res = 0
        stack = []

        num = 0
        sign = 1
        for c in s:
            if c.isdigit():
                num = num * 10 + ord(c) - ord('0')
            elif c == "+":
                res += sign * num
                num = 0
                sign = 1
            elif c == '-':
                res += sign * num
                num = 0
                sign = -1
            elif c == '(':
                stack.append(res)
                stack.append(sign)
                sign = 1
                res = 0
            elif c == ')':
                res += sign * num 
                num = 0
                sign = stack.pop()
                res = res * sign + stack.pop()
                sign = 1
            else:
                continue
        if num:
            res += sign * num
        return res 


# @lc code=end

sol = Solution()
s = '3-(2+(9-4))'
print(sol.calculate(s))