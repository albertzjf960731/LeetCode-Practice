#
# @lc app=leetcode id=524 lang=python
#
# [524] Longest Word in Dictionary through Deleting
#
# https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/description/
#
# algorithms
# Medium (46.92%)
# Likes:    404
# Dislikes: 197
# Total Accepted:    53.4K
# Total Submissions: 113.4K
# Testcase Example:  '"abpcplea"\n["ale","apple","monkey","plea"]'
#
# 
# Given a string and a string dictionary, find the longest string in the
# dictionary that can be formed by deleting some characters of the given
# string. If there are more than one possible results, return the longest word
# with the smallest lexicographical order. If there is no possible result,
# return the empty string.
# 
# Example 1:
# 
# Input:
# s = "abpcplea", d = ["ale","apple","monkey","plea"]
# 
# Output: 
# "apple"
# 
# 
# 
# 
# Example 2:
# 
# Input:
# s = "abpcplea", d = ["a","b","c"]
# 
# Output: 
# "a"
# 
# 
# 
# Note:
# 
# All the strings in the input will only contain lower-case letters.
# The size of the dictionary won't exceed 1,000.
# The length of all the strings in the input won't exceed 1,000.
# 
# 
#

# @lc code=start
class Solution(object):
    def findLongestWord(self, s, words):
        """
        :type s: str
        :type d: List[str]
        :rtype: str
        """            
    #     ans = ''
    #     for word in wordDict:
    #         if len(word) < len(ans) or (len(word) ==len(ans) and word > ans):
    #             continue
    #         if self.is_sub(s, word):
    #             ans = word 
    #     return ans

    # def is_sub(self, s, word):
    #     i, j = 0, 0
    #     while i<len(s) and j<len(word):
    #         if s[i] == word[j]:
    #             j+=1
    #         i+=1
    #     return j==len(word)

        # 先对words排序
        words.sort(key=lambda x: (-len(x), x))
        for word in words:
            j = 0
            for c in s:
                if j<len(word) and word[j] == c:
                    j+=1
            if j==len(word):
                return word
        return ''


# @lc code=end

sol = Solution()
s = 'abpcplea'
words = ['a', 'b', 'c']
print(sol.findLongestWord(s, words))