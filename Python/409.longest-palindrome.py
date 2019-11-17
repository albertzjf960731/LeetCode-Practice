#
# @lc app=leetcode id=409 lang=python
#
# [409] Longest Palindrome
#
# https://leetcode.com/problems/longest-palindrome/description/
#
# algorithms
# Easy (48.93%)
# Likes:    666
# Dislikes: 67
# Total Accepted:    115.4K
# Total Submissions: 235.5K
# Testcase Example:  '"abccccdd"'
#
# Given a string which consists of lowercase or uppercase letters, find the
# length of the longest palindromes that can be built with those letters.
# 
# This is case sensitive, for example "Aa" is not considered a palindrome
# here.
# 
# Note:
# Assume the length of given string will not exceed 1,010.
# 
# 
# Example: 
# 
# Input:
# "abccccdd"
# 
# Output:
# 7
# 
# Explanation:
# One longest palindrome that can be built is "dccaccd", whose length is 7.
# 
# 
#

# @lc code=start
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        hash_dict = {}
        for c in s:
            if c not in hash_dict:
                hash_dict[c] = 0
            hash_dict[c] += 1

        ans = 0
        odd = 0
        for k, v in hash_dict.items():
            if v == 1:
                odd = 1
            else:
                if v % 2 == 0:
                    ans +=v 
                else:
                    ans += v // 2 * 2
                    odd = 1 
        return ans + odd
# @lc code=end

sol = Solution()
sol.longestPalindrome('ccc')