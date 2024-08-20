#
# @lc app=leetcode id=953 lang=python3
#
# [953] Verifying an Alien Dictionary
#
# https://leetcode.com/problems/verifying-an-alien-dictionary/description/
#
# algorithms
# Easy (55.16%)
# Likes:    4890
# Dislikes: 1634
# Total Accepted:    516.8K
# Total Submissions: 937K
# Testcase Example:  '["hello","leetcode"]\n"hlabcdefgijkmnopqrstuvwxyz"'
#
# In an alien language, surprisingly, they also use English lowercase letters,
# but possibly in a different order. The order of the alphabet is some
# permutation of lowercase letters.
# 
# Given a sequence of words written in the alien language, and the order of the
# alphabet, return true if and only if the given words are sorted
# lexicographically in this alien language.
# 
# 
# Example 1:
# 
# 
# Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
# Output: true
# Explanation: As 'h' comes before 'l' in this language, then the sequence is
# sorted.
# 
# 
# Example 2:
# 
# 
# Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
# Output: false
# Explanation: As 'd' comes after 'l' in this language, then words[0] >
# words[1], hence the sequence is unsorted.
# 
# 
# Example 3:
# 
# 
# Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
# Output: false
# Explanation: The first three characters "app" match, and the second string is
# shorter (in size.) According to lexicographical rules "apple" > "app",
# because 'l' > '∅', where '∅' is defined as the blank character which is less
# than any other character (More info).
# 
# 
# 
# Constraints:
# 
# 
# 1 <= words.length <= 100
# 1 <= words[i].length <= 20
# order.length == 26
# All characters in words[i] and order are English lowercase letters.
# 
# 
#

# @lc code=start
class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        c2i = {c: i for i, c in enumerate(order)}
        for i in range(len(words) - 1):
            for j in range(len(words[i])):
                if j >= len(words[i + 1]):
                    return False
                if words[i][j] != words[i + 1][j]:
                    if c2i[words[i][j]] > c2i[words[i + 1][j]]:
                        return False
                    break
        return True
        
# @lc code=end

