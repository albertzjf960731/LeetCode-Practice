#
# @lc app=leetcode id=115 lang=python
#
# [115] Distinct Subsequences
#
# https://leetcode.com/problems/distinct-subsequences/description/
#
# algorithms
# Hard (36.06%)
# Likes:    838
# Dislikes: 45
# Total Accepted:    117.1K
# Total Submissions: 324.5K
# Testcase Example:  '"rabbbit"\n"rabbit"'
#
# Given a string S and a string T, count the number of distinct subsequences of
# S which equals T.
# 
# A subsequence of a string is a new string which is formed from the original
# string by deleting some (can be none) of the characters without disturbing
# the relative positions of the remaining characters. (ie, "ACE" is a
# subsequence of "ABCDE" while "AEC" is not).
# 
# Example 1:
# 
# 
# Input: S = "rabbbit", T = "rabbit"
# Output: 3
# Explanation:
# 
# As shown below, there are 3 ways you can generate "rabbit" from S.
# (The caret symbol ^ means the chosen letters)
# 
# rabbbit
# ^^^^ ^^
# rabbbit
# ^^ ^^^^
# rabbbit
# ^^^ ^^^
# 
# 
# Example 2:
# 
# 
# Input: S = "babgbag", T = "bag"
# Output: 5
# Explanation:
# 
# As shown below, there are 5 ways you can generate "bag" from S.
# (The caret symbol ^ means the chosen letters)
# 
# babgbag
# ^^ ^
# babgbag
# ^^    ^
# babgbag
# ^    ^^
# babgbag
# ⁠ ^  ^^
# babgbag
# ⁠   ^^^
# 
# 
#

# @lc code=start
class Solution(object):
    def numDistinct(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        # l1, l2 = len(s), len(t)

        # dp = [[1 for _ in range(l2+1)] for _ in range(l1+1)]

        # for j in range(1, l2+1):
        #     dp[0][j] = 0
        # for i in range(1, l1+1):
        #     for j in range(1, l2+1):
        #         if s[i-1] == t[j-1]:
        #             dp[i][j] = dp[i-1][j] + dp[i-1][j-1]
        #         else:
        #             dp[i][j] = dp[i-1][j] 
        # return dp[-1][-1]


        l1, l2 = len(s), len(t)

        dp = [0 for _ in range(l2+1)] 
        dp[0] = 1

        for i in range(1, l1+1):
            pre = dp[:]
            for j in range(1, l2+1):
                if s[i-1] == t[j-1]:
                    dp[j] = pre[j] + pre[j-1]
                else:
                    dp[j] = pre[j] 
        return dp[-1]



# @lc code=end

sol = Solution()
s = "rabbbit"
t = "rabbit"
print(sol.numDistinct(s, t))