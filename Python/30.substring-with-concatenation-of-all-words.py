#
# @lc app=leetcode id=30 lang=python
#
# [30] Substring with Concatenation of All Words
#
# https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
#
# algorithms
# Hard (24.46%)
# Likes:    674
# Dislikes: 1065
# Total Accepted:    154.5K
# Total Submissions: 631.6K
# Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
#
# You are given a string, s, and a list of words, words, that are all of the
# same length. Find all starting indices of substring(s) in s that is a
# concatenation of each word in words exactly once and without any intervening
# characters.
# 
# 
# 
# Example 1:
# 
# 
# Input:
# ⁠ s = "barfoothefoobarman",
# ⁠ words = ["foo","bar"]
# Output: [0,9]
# Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar"
# respectively.
# The output order does not matter, returning [9,0] is fine too.
# 
# 
# Example 2:
# 
# 
# Input:
# ⁠ s = "wordgoodgoodgoodbestword",
# ⁠ words = ["word","good","best","word"]
# Output: []
# 
# 
#

# @lc code=start
class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        if not words:
            return [] 

        hash_dict = {}
        for word in words:
            hash_dict[word] = hash_dict.get(word, 0) + 1

        res = []
        num_words = len(words)
        len_word = len(words[0])
        for i in range(len(s)-num_words*len_word+1):
            temp_dict = {}
            num = 0
            while num<num_words:
                word = s[i+num*len_word: i+(num+1)*len_word]
                if word in hash_dict:
                    temp_dict[word] = temp_dict.get(word, 0) + 1
                    if temp_dict[word] > hash_dict[word]:
                        break
                else:
                    break
                num+=1

            if num == num_words:
                res.append(i)
        return res 
                
# @lc code=end

sol = Solution()
s = "barfoothefoobarman"
words = ["foo","bar"]
print(sol.findSubstring(s, words))