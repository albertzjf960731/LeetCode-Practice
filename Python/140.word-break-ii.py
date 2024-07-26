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
        ans = []
        self.dfs(s, 0, wordDict, "", ans)
        return ans
    
    def dfs(self, s, idx, wordDict, path, ans):
        if idx == len(s):
            ans.append(path[1:])

        for i in range(idx, len(s)):
            if s[idx: i+1] in wordDict:
                self.dfs(s, i+1, wordDict, path+" "+s[idx: i+1], ans)


        # dfs with memoization
        dp = {}
        return self.dfs(s, wordDict, dp)
    
    def dfs(self, s, wordDict, dp):
        if s in dp:
            return dp[s]
        
        ans = []
        for w in wordDict:
            if not s.startswith(w):
                continue
            if w == s:
                ans.append(w)
            else:
                tails = self.dfs(s[len(w):], wordDict, dp)
                for t in tails:
                    t = w + " " + t
                    ans.append(t)
        dp[s] = ans
        return ans
      
# @lc code=end

sol = Solution()
s = "catsandog"
wordDict = ["cats","dog","sand","and","cat"]
print(sol.wordBreak(s, wordDict))