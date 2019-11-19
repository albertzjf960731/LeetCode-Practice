#
# @lc app=leetcode id=242 lang=python
#
# [242] Valid Anagram
#
# https://leetcode.com/problems/valid-anagram/description/
#
# algorithms
# Easy (54.03%)
# Likes:    935
# Dislikes: 123
# Total Accepted:    426.9K
# Total Submissions: 787.7K
# Testcase Example:  '"anagram"\n"nagaram"'
#
# Given two strings s and t , write a function to determine if t is an anagram
# of s.
# 
# Example 1:
# 
# 
# Input: s = "anagram", t = "nagaram"
# Output: true
# 
# 
# Example 2:
# 
# 
# Input: s = "rat", t = "car"
# Output: false
# 
# 
# Note:
# You may assume the string contains only lowercase alphabets.
# 
# Follow up:
# What if the inputs contain unicode characters? How would you adapt your
# solution to such case?
# 
#

# @lc code=start
class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        # return len(s) == len(t) and set(s) == set(t)
        # return sorted(s) == sorted(t)
        
        dict_s, dict_t = dict(), dict()

        for c in s:
            dict_s[c] = dict_s.get(c, 0) + 1
        for c in t:
            dict_t[c] = dict_t.get(c, 0) + 1
        return dict_s == dict_t



# @lc code=end

