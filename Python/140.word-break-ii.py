#
# @lc app=leetcode id=140 lang=python
#
# [140] Word Break II
#
# https://leetcode.com/problems/word-break-ii/description/
#
# algorithms
# Hard (28.64%)
# Likes:    1286
# Dislikes: 288
# Total Accepted:    184.2K
# Total Submissions: 640.2K
# Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
#
# Given a non-empty string s and a dictionary wordDict containing a list of
# non-empty words, add spaces in s to construct a sentence where each word is a
# valid dictionary word. Return all such possible sentences.
# 
# Note:
# 
# 
# The same word in the dictionary may be reused multiple times in the
# segmentation.
# You may assume the dictionary does not contain duplicate words.
# 
# 
# Example 1:
# 
# 
# Input:
# s = "catsanddog"
# wordDict = ["cat", "cats", "and", "sand", "dog"]
# Output:
# [
# "cats and dog",
# "cat sand dog"
# ]
# 
# 
# Example 2:
# 
# 
# Input:
# s = "pineapplepenapple"
# wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
# Output:
# [
# "pine apple pen apple",
# "pineapple pen apple",
# "pine applepen apple"
# ]
# Explanation: Note that you are allowed to reuse a dictionary word.
# 
# 
# Example 3:
# 
# 
# Input:
# s = "catsandog"
# wordDict = ["cats", "dog", "sand", "and", "cat"]
# Output:
# []
# 
#

# @lc code=start
class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: List[str]
        """
        # 递归
    #     self.wordDict = wordDict

    #     res = []
    #     self.dfs(s, 0, '', res)
    #     return res    

    # def dfs(self, s, i, path, res):

    #     if i == len(s):
    #          res.append(path[1:])

    #     for j in range(i, len(s)):
    #         if s[i:j+1] in self.wordDict:
    #             self.dfs(s, j+1, path+' '+s[i:j+1], res)

        # 递归+cache
        # 嵌套函数应该可以节约空间

        # res = {len(s): ['']}

        # def dfs(i):
        #     if i not in res:
        #         res[i] = [s[i:j+1] + (tail and ' ' + tail) 
        #                for j in range(i, len(s))
        #                if s[i:j+1] in wordDict
        #                for tail in dfs(j+1)]
        #     return res[i]

        # def dfs(i):
        #     if i not in res:
        #         for j in range(i, len(s)):
        #             if s[i:j+1] in wordDict:
        #                 for tail in dfs(j+1):
        #                     if i not in res:
        #                         res[i] = [s[i:j+1] + (tail and ' ' + tail)]
        #                     else:
        #                         res[i].append(s[i:j+1] + (tail and ' ' + tail))
        #     return res[i]

        # return dfs(0)
            
    
        
        def dfs(s, cache):

            if s in cache: 
                return cache[s]
            if not s: 
                return []
            
            res = []
            for word in wordDict:
                if not s.startswith(word):
                    continue

                if len(word) == len(s):
                    res.append(word)
                else:
                    tails = dfs(s[len(word):], cache)
                    for tail in tails:
                        tail = word + ' ' + tail
                        res.append(tail)
            
            cache[s] = res
            return res
        return dfs(s, {})

      
# @lc code=end

sol = Solution()
s = "catsandog"
wordDict = ["cats","dog","sand","and","cat"]
print(sol.wordBreak(s, wordDict))