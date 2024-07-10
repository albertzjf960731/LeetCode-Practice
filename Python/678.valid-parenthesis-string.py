#
# @lc app=leetcode id=678 lang=python3
#
# [678] Valid Parenthesis String
#
# https://leetcode.com/problems/valid-parenthesis-string/description/
#
# algorithms
# Medium (37.97%)
# Likes:    6115
# Dislikes: 186
# Total Accepted:    381.7K
# Total Submissions: 1M
# Testcase Example:  '"()"'
#
# Given a string s containing only three types of characters: '(', ')' and '*',
# return true if s is valid.
# 
# The following rules define a valid string:
# 
# 
# Any left parenthesis '(' must have a corresponding right parenthesis ')'.
# Any right parenthesis ')' must have a corresponding left parenthesis '('.
# Left parenthesis '(' must go before the corresponding right parenthesis
# ')'.
# '*' could be treated as a single right parenthesis ')' or a single left
# parenthesis '(' or an empty string "".
# 
# 
# 
# Example 1:
# Input: s = "()"
# Output: true
# Example 2:
# Input: s = "(*)"
# Output: true
# Example 3:
# Input: s = "(*))"
# Output: true
# 
# 
# Constraints:
# 
# 
# 1 <= s.length <= 100
# s[i] is '(', ')' or '*'.
# 
# 
#

# @lc code=start
class Solution:
    def checkValidString(self, s: str) -> bool:
        left, star = [], []
        for i in range(len(s)):
            if s[i] == '*':
                star.append(i)
            elif s[i] == '(':
                left.append(i)
            else:
                if left:
                    left.pop()
                elif star:
                    star.pop()
                else:
                    return False
        
        while left and star:
            if left.pop() > star.pop():
                return False
        return not left
# @lc code=end

