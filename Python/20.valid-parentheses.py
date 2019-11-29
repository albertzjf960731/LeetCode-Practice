#
# @lc app=leetcode id=20 lang=python
#
# [20] Valid Parentheses
#
# https://leetcode.com/problems/valid-parentheses/description/
#
# algorithms
# Easy (37.45%)
# Likes:    3515
# Dislikes: 172
# Total Accepted:    736K
# Total Submissions: 2M
# Testcase Example:  '"()"'
#
# Given a string containing just the characters '(', ')', '{', '}', '[' and
# ']', determine if the input string is valid.
# 
# An input string is valid if:
# 
# 
# Open brackets must be closed by the same type of brackets.
# Open brackets must be closed in the correct order.
# 
# 
# Note that an empty string is also considered valid.
# 
# Example 1:
# 
# 
# Input: "()"
# Output: true
# 
# 
# Example 2:
# 
# 
# Input: "()[]{}"
# Output: true
# 
# 
# Example 3:
# 
# 
# Input: "(]"
# Output: false
# 
# 
# Example 4:
# 
# 
# Input: "([)]"
# Output: false
# 
# 
# Example 5:
# 
# 
# Input: "{[]}"
# Output: true
# 
# 
#

# @lc code=start
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        # stack = []

        # mapping = {')': '(',
        #            ']': '[',
        #            '}': '{'}

        # for char in s:
        #     if char in mapping:
        #         top = stack.pop() if stack else '#'
        #         if mapping[char] != top:
        #             return False
        #     else:
        #         stack.append(char)
        
        # return not stack
        hash_map = {"(": ")", "[": "]",  "{": "}"}
        # open_par = set(["(", "[", "{"])
        
        stack = []
        for ch in s:
            if ch in ["(", "[", "{"]:
                stack.append(ch)
            elif stack and ch == hash_map[stack[-1]]:
                    stack.pop()
            else:
                return False
        return stack == []

# @lc code=end

sol = Solution()

s = "]"
sol.isValid(s)