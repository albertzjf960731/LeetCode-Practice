#
# @lc app=leetcode id=58 lang=python
#
# [58] Length of Last Word
#
# https://leetcode.com/problems/length-of-last-word/description/
#
# algorithms
# Easy (32.33%)
# Likes:    466
# Dislikes: 1913
# Total Accepted:    309.6K
# Total Submissions: 957.5K
# Testcase Example:  '"Hello World"'
#
# Given a string s consists of upper/lower-case alphabets and empty space
# characters ' ', return the length of last word in the string.
# 
# If the last word does not exist, return 0.
# 
# Note: A word is defined as a character sequence consists of non-space
# characters only.
# 
# Example:
# 
# 
# Input: "Hello World"
# Output: 5
# 
# 
# 
# 
#

# @lc code=start
class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        count = 0   
        index = len(s)-1
        while True:
            if index<0 or s[index] != ' ':
                break
            index -= 1
        for i in range(index, -1, -1):
            if s[i] == ' ':
                break
            count += 1
        return count
# @lc code=end
sol = Solution()
print(sol.lengthOfLastWord('hello world'))
