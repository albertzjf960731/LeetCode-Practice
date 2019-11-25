#
# @lc app=leetcode id=389 lang=python
#
# [389] Find the Difference
#
# https://leetcode.com/problems/find-the-difference/description/
#
# algorithms
# Easy (53.87%)
# Likes:    579
# Dislikes: 251
# Total Accepted:    164.5K
# Total Submissions: 305.2K
# Testcase Example:  '"abcd"\n"abcde"'
#
# 
# Given two strings s and t which consist of only lowercase letters.
# 
# String t is generated by random shuffling string s and then add one more
# letter at a random position.
# 
# Find the letter that was added in t.
# 
# Example:
# 
# Input:
# s = "abcd"
# t = "abcde"
# 
# Output:
# e
# 
# Explanation:
# 'e' is the letter that was added.
# 
#

# @lc code=start
class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        # for item in (set(t) - set(s)):
        #     return item

        ans = 0
        for c in s:
            ans ^= ord(c)
        for c in t:
            ans ^= ord(c)
        return chr(ans)

# @lc code=end
