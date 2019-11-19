#
# @lc app=leetcode id=345 lang=python
#
# [345] Reverse Vowels of a String
#
# https://leetcode.com/problems/reverse-vowels-of-a-string/description/
#
# algorithms
# Easy (42.40%)
# Likes:    478
# Dislikes: 873
# Total Accepted:    181K
# Total Submissions: 426.2K
# Testcase Example:  '"hello"'
#
# Write a function that takes a string as input and reverse only the vowels of
# a string.
# 
# Example 1:
# 
# 
# Input: "hello"
# Output: "holle"
# 
# 
# 
# Example 2:
# 
# 
# Input: "leetcode"
# Output: "leotcede"
# 
# 
# Note:
# The vowels does not include the letter "y".
# 
# 
# 
#

# @lc code=start
class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        s = list(s)
        vowel_set = set('aeiouAEIOU')

        l, r = 0, len(s)-1
        while l<r:
            if s[l] in vowel_set and s[r] in vowel_set:
                s[l], s[r] = s[r], s[l]
                l += 1
                r -= 1
            if s[l] not in vowel_set:
                l+=1
            if s[r] not in vowel_set:
                r-=1

        return ''.join(s)

# @lc code=end

sol = Solution()
s = "Euston saw I was not Sue."
sol.reverseVowels(s)
print(s)