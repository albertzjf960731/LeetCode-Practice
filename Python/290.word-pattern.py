#
# @lc app=leetcode id=290 lang=python
#
# [290] Word Pattern
#
# https://leetcode.com/problems/word-pattern/description/
#
# algorithms
# Easy (35.80%)
# Likes:    813
# Dislikes: 112
# Total Accepted:    161.8K
# Total Submissions: 451.1K
# Testcase Example:  '"abba"\n"dog cat cat dog"'
#
# Given a pattern and a string str, find if str follows the same pattern.
# 
# Here follow means a full match, such that there is a bijection between a
# letter in pattern and a non-empty word in str.
# 
# Example 1:
# 
# 
# Input: pattern = "abba", str = "dog cat cat dog"
# Output: true
# 
# Example 2:
# 
# 
# Input:pattern = "abba", str = "dog cat cat fish"
# Output: false
# 
# Example 3:
# 
# 
# Input: pattern = "aaaa", str = "dog cat cat dog"
# Output: false
# 
# Example 4:
# 
# 
# Input: pattern = "abba", str = "dog dog dog dog"
# Output: false
# 
# Notes:
# You may assume pattern contains only lowercase letters, and str contains
# lowercase letters that may be separated by a single space.
# 
#

# @lc code=start
class Solution(object):
    def wordPattern(self, pattern, s):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        # t = s.split(' ')
        # s = pattern
        # return len(set(zip(s, t))) == len(set(s)) == len(set(t)) and len(s) == len(t)


        words = s.split(' ')
        if len(pattern) != len(words):
            return False
        
        dic = {}
        for i, c in enumerate(pattern):
            if c in dic:
                if dic[c] != words[i]:
                    return False
            # elif words[i] in dic.values():
            #     return False
            else:
                dic[c] = words[i]
        
        dic = {}
        for i, word in enumerate(words):
            if word in dic:
                if dic[word] != pattern[i]:
                    return False
            else:
                dic[word] = pattern[i]
        return True
        
# @lc code=end

sol = Solution()
pattern = 'abba'
s = "dog cat cat dog"
sol.wordPattern(pattern, s)