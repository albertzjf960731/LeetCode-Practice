#
# @lc app=leetcode id=647 lang=python
#
# [647] Palindromic Substrings
#
# https://leetcode.com/problems/palindromic-substrings/description/
#
# algorithms
# Medium (58.32%)
# Likes:    1777
# Dislikes: 92
# Total Accepted:    132.2K
# Total Submissions: 226.2K
# Testcase Example:  '"abc"'
#
# Given a string, your task is to count how many palindromic substrings in this
# string.
# 
# The substrings with different start indexes or end indexes are counted as
# different substrings even they consist of same characters.
# 
# Example 1:
# 
# 
# Input: "abc"
# Output: 3
# Explanation: Three palindromic strings: "a", "b", "c".
# 
# 
# 
# 
# Example 2:
# 
# 
# Input: "aaa"
# Output: 6
# Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
# 
# 
# 
# 
# Note:
# 
# 
# The input string length won't exceed 1000.
# 
# 
# 
#

# @lc code=start
class Solution(object):
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        # n = len(s)
        # ans = 0
        # for m in range(n*2-1):
        #     l = m // 2
        #     r = l + m%2
        #     print(l, r)
        #     while l>=0 and r<n and s[l]==s[r]:
        #         ans += 1
        #         l -= 1
        #         r += 1
        # return ans 

        ans = 0
        for i in range(len(s)):
            ans += self.helper(s, i, i)
            ans += self.helper(s, i, i+1)
        return ans 

    def helper(self, s, l, r):
        ans = 0
        while l >= 0 and r < len(s) and s[l] == s[r]:
            l -= 1
            r += 1
            ans += 1
        return ans

# @lc code=end

sol = Solution()
s = 'abcc'
print(sol.countSubstrings(s))