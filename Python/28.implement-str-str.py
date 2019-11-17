#
# @lc app=leetcode id=28 lang=python
#
# [28] Implement strStr()
#
# https://leetcode.com/problems/implement-strstr/description/
#
# algorithms
# Easy (33.14%)
# Likes:    1101
# Dislikes: 1527
# Total Accepted:    515.1K
# Total Submissions: 1.6M
# Testcase Example:  '"hello"\n"ll"'
#
# Implement strStr().
# 
# Return the index of the first occurrence of needle in haystack, or -1 if
# needle is not part of haystack.
# 
# Example 1:
# 
# 
# Input: haystack = "hello", needle = "ll"
# Output: 2
# 
# 
# Example 2:
# 
# 
# Input: haystack = "aaaaa", needle = "bba"
# Output: -1
# 
# 
# Clarification:
# 
# What should we return when needle is an empty string? This is a great
# question to ask during an interview.
# 
# For the purpose of this problem, we will return 0 when needle is an empty
# string. This is consistent to C's strstr() and Java's indexOf().
# 
#

# @lc code=start
class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        # return haystack.find(needle)
        if not needle:
            return 0 

        for i in range(len(haystack)):
            for j in range(len(needle)+len(haystack)):
                if j == len(needle):
                    return i
                if i + j == len(haystack):
                    return -1
                if haystack[i+j] != needle[j]:
                    break
        return -1

                    
# @lc code=end

sol = Solution()
haystack = "hello"
needle = "ll"
print(sol.strStr(haystack, needle))
