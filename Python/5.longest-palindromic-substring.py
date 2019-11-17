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
    #     start, end = 0, 1
    #     for i in range(len(s)-1):
    #         for j in range(i, len(s)+1):
    #             if self.is_palindrome(s[i: j]):
    #                 if j-i > end-start:
    #                     sub = s[i: j]
    #                     start, end = i, j
    #     return s[start: end]
        
    # def is_palindrome(self, s):
    #     s_rev = ''
    #     for i in reversed(range(len(s))):
    #         s_rev += s[i]
    #     return s == s_rev

        # if not s:
        #     return ''

        # s_rev = s[::-1]

        # arr = [[0 for i in range(len(s) +1)] 
        #           for j in range(len(s) + 1)]
        # max_len, max_end = 0, 0

        # for i in range(len(s)):
        #     for j in range(len(s)):
        #         if s[i] == s_rev[j]:
        #             if i == 0 and j == 0:
        #                 arr[i][j] = 1
        #             else:
        #                 arr[i][j] = arr[i-1][j-1] + 1
               
        #         if arr[i][j] > max_len:
        #             j_rev = len(s) - j -1
        #             if j_rev + arr[i][j] - 1 == i:
        #                 max_len = arr[i][j]
        #                 max_end = i

        # return s[max_end-max_len+1: max_end+1]

        arr = [[False for i in range(len(s)+1)]
                  for j in range(len(s)+1)]
        max_len = 0
        max_pal = ''
        for length in range(1, len(s)+1):
            for start in range(len(s)):
                end = start + length -1 
                if end >= len(s):
                    break
                
                arr[start][end] = length==1 or (length==2 or arr[start+1][end-1]) and s[start]==s[end]

                if arr[start][end] and length > max_len:
                    max_pal = s[start: end+1]
                    max_len = length
        return max_pal


        res = ''
        for i in range(len(s)):
            # odd case
            tmp = self.helper(s, i, i)
            if len(tmp) > len(res):
                res = tmp 
            
            # even case
            tmp = self.helper(s, i, i+1)
            if len(tmp) > len(res):
                res = tmp 
        return res
    
    def helper(self, s, l, r):
        while l >= 0 and r < len(s) and s[l] == s[r]:
            l -= 1
            r += 1
        return s[l+1: r]
# @lc code=end

sol = Solution()
s = 'cbbd'
print(sol.longestPalindrome(s))
