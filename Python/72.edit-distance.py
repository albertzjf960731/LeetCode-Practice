#
# @lc app=leetcode id=72 lang=python
#
# [72] Edit Distance
#
# https://leetcode.com/problems/edit-distance/description/
#
# algorithms
# Hard (39.98%)
# Likes:    2658
# Dislikes: 41
# Total Accepted:    206.1K
# Total Submissions: 514.2K
# Testcase Example:  '"horse"\n"ros"'
#
# Given two words word1 and word2, find the minimum number of operations
# required to convert word1 to word2.
# 
# You have the following 3 operations permitted on a word:
# 
# 
# Insert a character
# Delete a character
# Replace a character
# 
# 
# Example 1:
# 
# 
# Input: word1 = "horse", word2 = "ros"
# Output: 3
# Explanation: 
# horse -> rorse (replace 'h' with 'r')
# rorse -> rose (remove 'r')
# rose -> ros (remove 'e')
# 
# 
# Example 2:
# 
# 
# Input: word1 = "intention", word2 = "execution"
# Output: 5
# Explanation: 
# intention -> inention (remove 't')
# inention -> enention (replace 'i' with 'e')
# enention -> exention (replace 'n' with 'x')
# exention -> exection (replace 'n' with 'c')
# exection -> execution (insert 'u')
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
        # 递归
        # if not word1 and not word2:
        #     return 0
        # if not word1:
        #     return len(word2)
        # if not word2:
        #     return len(word1)
        
        # x = self.minDistance(word1, word2[:-1]) + 1
        # y = self.minDistance(word1[:-1], word2) + 1
        # z = self.minDistance(word1[:-1], word2[:-1]) 
        # if word1[-1] != word2[-1]:
        #     z += 1
        # return min(x, y, z)

        # 动态规划
        # l1, l2 = len(word1)+1, len(word2) + 1
        # dp = [[0 for _ in range(l2)] for _ in range(l1)]
        # # dp = [[0] *  l2 ] * l1
        # for i in range(l1):
        #     dp[i][0] = i 
        # for j in range(l2):
        #     dp[0][j] = j 
        # for i in range(1, l1):
        #     for j in range(1, l2):
        #         if word1[i-1] == word2[j-1]:
        #             dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1])
        #         else:
        #             dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+1)
        #         # dp[i][j] = min(
        #         #     dp[i-1][j]+1, 
        #         #     dp[i][j-1]+1, 
        #         #     dp[i-1][j-1]+(word1[i-1]!=word2[j-1]))
        # return dp[-1][-1]
        
        # 求 dp[i][*] 的时候，我们只用到 pd[i - 1][*] 的情况
        l1, l2 = len(word1)+1, len(word2) + 1
        pre = [0 for _ in range(l2)]
        for j in range(l2):
            pre[j] = j 
        for i in range(1, l1):
            cur = [i] * l2
            for j in range(1, l2):
                if word1[i-1] == word2[j-1]:
                    cur[j] = min(cur[j-1]+1, pre[j]+1, pre[j-1])
                else:
                    cur[j] = min(cur[j-1]+1, pre[j]+1, pre[j-1]+1)
                # cur[j] = min(cur[j-1]+1, pre[j]+1, pre[j-1]+(word1[i-1]!=word2[j-1]))

            pre = cur[:]

        return pre[-1]
# @lc code=end

sol = Solution()
word1 = 'horse'
word2 = 'ros'
sol.minDistance(word1, word2)