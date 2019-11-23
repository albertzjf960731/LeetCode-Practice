#
# @lc app=leetcode id=10 lang=python
#
# [10] Regular Expression Matching
#
# https://leetcode.com/problems/regular-expression-matching/description/
#
# algorithms
# Hard (25.87%)
# Likes:    3222
# Dislikes: 600
# Total Accepted:    355.3K
# Total Submissions: 1.4M
# Testcase Example:  '"aa"\n"a"'
#
# Given an input string (s) and a pattern (p), implement regular expression
# matching with support for '.' and '*'.
# 
# 
# '.' Matches any single character.
# '*' Matches zero or more of the preceding element.
# 
# 
# The matching should cover the entire input string (not partial).
# 
# Note:
# 
# 
# s could be empty and contains only lowercase letters a-z.
# p could be empty and contains only lowercase letters a-z, and characters like
# . or *.
# 
# 
# Example 1:
# 
# 
# Input:
# s = "aa"
# p = "a"
# Output: false
# Explanation: "a" does not match the entire string "aa".
# 
# 
# Example 2:
# 
# 
# Input:
# s = "aa"
# p = "a*"
# Output: true
# Explanation: '*' means zero or more of the preceding element, 'a'. Therefore,
# by repeating 'a' once, it becomes "aa".
# 
# 
# Example 3:
# 
# 
# Input:
# s = "ab"
# p = ".*"
# Output: true
# Explanation: ".*" means "zero or more (*) of any character (.)".
# 
# 
# Example 4:
# 
# 
# Input:
# s = "aab"
# p = "c*a*b"
# Output: true
# Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore,
# it matches "aab".
# 
# 
# Example 5:
# 
# 
# Input:
# s = "mississippi"
# p = "mis*is*p*."
# Output: false
# 
# 
#

# @lc code=start
class Solution(object):
    def __init__(self):
        self.cache = {}
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        
        # 递归
        # if not p:
        #     return not s

        # first_match = len(s)>0 and (s[0] == p[0] or p[0] == '.')  

        # if len(p) >= 2 and p[1] == '*':
        #     return self.isMatch(s, p[2:]) or (first_match and self.isMatch(s[1:], p))
        # else:
        #     return first_match and self.isMatch(s[1:], p[1:]) 
    
        # if (s, p) in self.cache:
        #     return self.cache[(s, p)]
        # if not p:
        #     return not s
        # if p[-1] == '*':
        #     # *=0
        #     if self.isMatch(s, p[:-2]):
        #         self.cache[(s, p)] = True
        #         return True 
        #     # *>=1
        #     if s and (s[-1] == p[-2] or p[-2]=='.') and self.isMatch(s[:-1], p):
        #         self.cache[(s, p)] = True
        #         return True 
        # if s and (p[-1] == s[-1] or p[-1] == '.') and self.isMatch(s[:-1], p[:-1]):
        #     self.cache[(s, p)] = True
        #     return True 
        # self.cache[(s, p)] = False
        # return False

        # 动态规划
        dp = [[False for _ in range(len(p)+1)] for _ in range(len(s)+1)]

        dp[0][0] = True # 两个空字符串
        for j in range(1, len(p)):
            dp[0][j+1] = (p[j] == '*' and dp[0][j-1])

        for i in range(len(s)):
            for j in range(len(p)):
                if p[j] == '*':
                    # *=0
                    dp[i+1][j+1] = dp[i+1][j-1] #or dp[i+1][j]
                    if p[j-1] == s[i] or p[j-1] == '.':
                        dp[i+1][j+1] |= dp[i][j+1]
                if p[j] == s[i] or p[j] == '.':
                    dp[i+1][j+1] = dp[i][j]
        return dp[-1][-1]

# @lc code=end

sol = Solution()
print(sol.isMatch('aab', 'c*a*b'))