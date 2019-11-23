#
# @lc app=leetcode id=44 lang=python
#
# [44] Wildcard Matching
#
# https://leetcode.com/problems/wildcard-matching/description/
#
# algorithms
# Hard (23.58%)
# Likes:    1387
# Dislikes: 82
# Total Accepted:    203.4K
# Total Submissions: 862K
# Testcase Example:  '"aa"\n"a"'
#
# Given an input string (s) and a pattern (p), implement wildcard pattern
# matching with support for '?' and '*'.
# 
# 
# '?' Matches any single character.
# '*' Matches any sequence of characters (including the empty sequence).
# 
# 
# The matching should cover the entire input string (not partial).
# 
# Note:
# 
# 
# s could be empty and contains only lowercase letters a-z.
# p could be empty and contains only lowercase letters a-z, and characters like
# ? or *.
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
# p = "*"
# Output: true
# Explanation: '*' matches any sequence.
# 
# 
# Example 3:
# 
# 
# Input:
# s = "cb"
# p = "?a"
# Output: false
# Explanation: '?' matches 'c', but the second letter is 'a', which does not
# match 'b'.
# 
# 
# Example 4:
# 
# 
# Input:
# s = "adceb"
# p = "*a*b"
# Output: true
# Explanation: The first '*' matches the empty sequence, while the second '*'
# matches the substring "dce".
# 
# 
# Example 5:
# 
# 
# Input:
# s = "acdcb"
# p = "a*c?b"
# Output: false
# 
# 
#

# @lc code=start
class Solution(object):
    # def __init__(self):
    #     self.cache = {}
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        # if (s, p) in self.cache:
        #     return self.cache[(s, p)]
        
        # if not p:
        #     return not s
        # if not s:
        #     for c in p:
        #         if c != '*':
        #             return False
        #     return True
            
        # if p[-1] == '*':
            # if self.isMatch(s[:-1], p) or self.isMatch(s, p[:-1]):
        #         self.cache[(s, p)] = True
        #         return True 

        # if (p[-1] == s[-1] or p[-1] == '?') and self.isMatch(s[:-1], p[:-1]):
        #     self.cache[(s, p)] = True
        #     return True 
        # self.cache[(s, p)] = False
        # return False

        # # 动态规划
        # 索引在字符串和dp 中的含义是不同的
        dp = [[False for _ in range(len(p)+1)] for _ in range(len(s)+1)]

        dp[0][0] = True
        for j in range(len(p)):
            if p[j] == '*':
                dp[0][j+1] = dp[0][j]

        for i in range(len(s)):
            for j in range(len(p)):
                if p[j] == '*':
                    # * 表示空 or * 表示任意值
                    dp[i+1][j+1] = dp[i][j+1] or dp[i+1][j]
                if p[j] == s[i] or p[j] == '?':
                    dp[i+1][j+1] = dp[i][j]
        return dp[-1][-1]

        # 贪心
        i, j = 0, 0
        match = 0
        start = -1
        while i < len(s):
            if j < len(p) and (p[j] == '?' or s[i] == p[j]):
                i += 1
                j += 1
            elif j < len(p) and p[j] == '*':
                start = j
                match = i 
                j += 1
            elif start != -1:
                j = start + 1
                match += 1
                i = match 
            else: 
                return False

        while j < len(p) and p[j] == '*':
            j += 1
        return j == len(p)

# @lc code=end

sol = Solution()
print(sol.isMatch('aa', '*'))