#
# @lc app=leetcode id=5 lang=python
#
# [5] Longest Palindromic Substring
#
# https://leetcode.com/problems/longest-palindromic-substring/description/
#
# algorithms
# Medium (28.14%)
# Likes:    4628
# Dislikes: 417
# Total Accepted:    697.5K
# Total Submissions: 2.5M
# Testcase Example:  '"babad"'
#
# Given a string s, find the longest palindromic substring in s. You may assume
# that the maximum length of s is 1000.
# 
# Example 1:
# 
# 
# Input: "babad"
# Output: "bab"
# Note: "aba" is also a valid answer.
# 
# 
# Example 2:
# 
# 
# Input: "cbbd"
# Output: "bb"
# 
# 
#

# @lc code=start
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if len(s) == 1:
            return s
            
        n = len(s)
        dp = [[False for _ in range(n)] for _ in range(n)]
        
        for i in range(n):
            dp[i][i] = True
        for i in range(n-1):
            if s[i] == s[i+1]:
                dp[i][i+1] = True

        for l in range(3, n+1):
            for i in range(n-l+1):
                j = i + l - 1
                if s[i] == s[j]:
                    dp[i][j] = dp[i+1][j-1]

        ans = ""
        for i in range(n):
            for j in range(n):
                if dp[i][j] and j - i + 1 > len(ans):
                    ans = s[i:j+1]
        return ans
                    

        # 扩展中心法
        # 遍历所有的回文串中心（考虑奇数、偶数长度），从中心向外扩展可以用O(n)的时间找到该中心位置对应的最长回文串，这个思路其实相当直接，但时空复杂度相对于上面两个动规反而更好

        res = ''
        for i in range(len(s)):
            # odd case
            tmp = self.expand(s, i, i)
            if len(tmp) > len(res):
                res = tmp 
            
            # even case
            tmp = self.expand(s, i, i+1)
            if len(tmp) > len(res):
                res = tmp 
        return res
    
    def expand(self, s, l, r):
        while l >= 0 and r < len(s) and s[l] == s[r]:
            l -= 1
            r += 1
        return s[l+1: r]
# @lc code=end

sol = Solution()
s = 'cbbd'
print(sol.longestPalindrome(s))
