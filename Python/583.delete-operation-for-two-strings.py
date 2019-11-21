#
# @lc app=leetcode id=583 lang=python
#
# [583] Delete Operation for Two Strings
#
# https://leetcode.com/problems/delete-operation-for-two-strings/description/
#
# algorithms
# Medium (46.03%)
# Likes:    812
# Dislikes: 21
# Total Accepted:    38.1K
# Total Submissions: 82.6K
# Testcase Example:  '"sea"\n"eat"'
#
# 
# Given two words word1 and word2, find the minimum number of steps required to
# make word1 and word2 the same, where in each step you can delete one
# character in either string.
# 
# 
# Example 1:
# 
# Input: "sea", "eat"
# Output: 2
# Explanation: You need one step to make "sea" to "ea" and another step to make
# "eat" to "ea".
# 
# 
# 
# Note:
# 
# The length of given words won't exceed 500.
# Characters in given words can only be lower-case letters.
# 
# 
#

# @lc code=start
class Solution(object):
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """

        return len(word1) + len(word2) - self.longest_common_subsequence(word1, word2) * 2
        
    def longest_common_subsequence(self, word1, word2):
        n1 = len(word1)
        n2 = len(word2)
        dp = [[0 for _ in range(n2+1)] for _ in range(n1+1)]
        for i in range(1, n1+1):
            for j in range(1, n2+1):
                if word1[i-1] == word2[j-1]:
                    dp[i][j] = dp[i-1][j-1]+1
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        return dp[-1][-1]
# @lc code=end

