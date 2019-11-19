#
# @lc app=leetcode id=205 lang=python
#
# [205] Isomorphic Strings
#
# https://leetcode.com/problems/isomorphic-strings/description/
#
# algorithms
# Easy (38.52%)
# Likes:    969
# Dislikes: 282
# Total Accepted:    243.4K
# Total Submissions: 630.4K
# Testcase Example:  '"egg"\n"add"'
#
# Given two strings s and t, determine if they are isomorphic.
# 
# Two strings are isomorphic if the characters in s can be replaced to get t.
# 
# All occurrences of a character must be replaced with another character while
# preserving the order of characters. No two characters may map to the same
# character but a character may map to itself.
# 
# Example 1:
# 
# 
# Input: s = "egg", t = "add"
# Output: true
# 
# 
# Example 2:
# 
# 
# Input: s = "foo", t = "bar"
# Output: false
# 
# Example 3:
# 
# 
# Input: s = "paper", t = "title"
# Output: true
# 
# Note:
# You may assume both s and t have the same length.
# 
#

# @lc code=start
class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """

        # return len(set(zip(s, t))) == len(set(s)) == len(set(t))

        # dict_s, dict_t = dict(), dict() 
        # for index, val in enumerate(s):
        #     dict_s[val] = dict_s.get(val, []) + [index] 
        # for index, val in enumerate(t):
        #     dict_t[val] = dict_t.get(val, []) + [index]
        # return sorted(dict_s.values()) == sorted(dict_t.values())


        if len(s) != len(t):
            return False
        
        dic = {}
        for i, c in enumerate(s):
            if c in dic:
                if dic[c] != t[i]:
                    return False
            elif t[i] in dic.values():
                return False
            else:
                dic[c] = t[i]
        
        # dic = {}
        # for i, c in enumerate(t):
        #     if c in dic:
        #         if dic[c] != s[i]:
        #             return False
        #     else:
        #         dic[c] = s[i]
        return True
        
# @lc code=end

