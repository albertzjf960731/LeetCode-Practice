#
# @lc app=leetcode id=680 lang=python
#
# [680] Valid Palindrome II
#
# https://leetcode.com/problems/valid-palindrome-ii/description/
#
# algorithms
# Easy (35.21%)
# Likes:    1006
# Dislikes: 69
# Total Accepted:    105.8K
# Total Submissions: 299.4K
# Testcase Example:  '"aba"'
#
# 
# Given a non-empty string s, you may delete at most one character.  Judge
# whether you can make it a palindrome.
# 
# 
# Example 1:
# 
# Input: "aba"
# Output: True
# 
# 
# 
# Example 2:
# 
# Input: "abca"
# Output: True
# Explanation: You could delete the character 'c'.
# 
# 
# 
# Note:
# 
# The string will only contain lowercase characters a-z.
# The maximum length of the string is 50000.
# 
# 
#

# @lc code=start
class Solution(object):
    def validPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        
        def is_palin(s):
            return s==s[::-1]

        count = 1
        l, r = 0, len(s)-1
        while l < r:
            if s[l] != s[r]:
                return is_palin(s[l+1:r+1]) or is_palin(s[l:r])
            l +=1; r -= 1
        return True
        
# @lc code=end

sol = Solution()
s = "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga"

print(sol.validPalindrome(s))