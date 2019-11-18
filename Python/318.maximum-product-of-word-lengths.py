#
# @lc app=leetcode id=318 lang=python
#
# [318] Maximum Product of Word Lengths
#
# https://leetcode.com/problems/maximum-product-of-word-lengths/description/
#
# algorithms
# Medium (49.52%)
# Likes:    638
# Dislikes: 52
# Total Accepted:    87.1K
# Total Submissions: 175.6K
# Testcase Example:  '["abcw","baz","foo","bar","xtfn","abcdef"]'
#
# Given a string array words, find the maximum value of length(word[i]) *
# length(word[j]) where the two words do not share common letters. You may
# assume that each word will contain only lower case letters. If no such two
# words exist, return 0.
# 
# Example 1:
# 
# 
# Input: ["abcw","baz","foo","bar","xtfn","abcdef"]
# Output: 16 
# Explanation: The two words can be "abcw", "xtfn".
# 
# Example 2:
# 
# 
# Input: ["a","ab","abc","d","cd","bcd","abcd"]
# Output: 4 
# Explanation: The two words can be "ab", "cd".
# 
# Example 3:
# 
# 
# Input: ["a","aa","aaa","aaaa"]
# Output: 0 
# Explanation: No such pair of words.
# 
# 
#

# @lc code=start
class Solution(object):
    def maxProduct(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        # len_list = []
        # for word in words:
        #     len_list.append(len(word))
        # len_list.sort()
        # return len_list[-1] * len_list[-2]
        

        # 本题主要问题是判断两个字符串是否含相同字符，由于字符串只含有小写字符，总共 26 位，因此可以用一个 32 位的整数来存储每个字符是否出现过。

        val = [0 for _ in range(len(words))]
        for i in range(len(words)):
            for c in words[i]:
                val[i] |= 1<<(ord(c)-97)    
        
        res = 0
        for i in range(len(words)):
            for j in range(i+1, len(words)):
                if val[i] & val[j] == 0:
                    res = max(res, len(words[i] * len(words[j])))

        return res 





# @lc code=end

sol = Solution()
words = ["abcw","baz","foo","bar","xtfn","abcdef"]
print(sol.maxProduct(words))