#
# @lc app=leetcode id=856 lang=python3
#
# [856] Score of Parentheses
#
# https://leetcode.com/problems/score-of-parentheses/description/
#
# algorithms
# Medium (64.16%)
# Likes:    5413
# Dislikes: 207
# Total Accepted:    189.2K
# Total Submissions: 295.1K
# Testcase Example:  '"()"'
#
# Given a balanced parentheses string s, return the score of the string.
# 
# The score of a balanced parentheses string is based on the following
# rule:
# 
# 
# "()" has score 1.
# AB has score A + B, where A and B are balanced parentheses strings.
# (A) has score 2 * A, where A is a balanced parentheses string.
# 
# 
# 
# Example 1:
# 
# 
# Input: s = "()"
# Output: 1
# 
# 
# Example 2:
# 
# 
# Input: s = "(())"
# Output: 2
# 
# 
# Example 3:
# 
# 
# Input: s = "()()"
# Output: 2
# 
# 
# 
# Constraints:
# 
# 
# 2 <= s.length <= 50
# s consists of only '(' and ')'.
# s is a balanced parentheses string.
# 
# 
#

# @lc code=start
class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        # basic calculator
        # +(1)
        # +((1) *2)
        # +(1) +(1)
        stack = []
        cur = 0
        for c in s:
            if c == '(':
                stack.append(cur)
                cur = 0
            if c == ')':
                if cur == 0:
                    cur = 1
                else:
                    cur *= 2  
                cur += stack.pop()
        return cur
    

        # recursive
        ans = 0
        i, j = 0, 0
        while i < len(s):
            if s[i] == ')':
                i += 1
                continue
            
            # c == '('
            cnt = 1
            for j in range(i+1, len(s)):
                cnt += 1 if s[j]== '(' else -1
                if cnt == 0:
                    break
            sub = self.scoreOfParentheses(s[i+1: j])
            ans += max(1, sub * 2)
            i = j + 1
        return ans
# @lc code=end

