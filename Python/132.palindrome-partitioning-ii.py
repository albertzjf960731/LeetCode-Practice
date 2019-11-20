#
# @lc app=leetcode id=132 lang=python
#
# [132] Palindrome Partitioning II
#
# https://leetcode.com/problems/palindrome-partitioning-ii/description/
#
# algorithms
# Hard (28.57%)
# Likes:    747
# Dislikes: 26
# Total Accepted:    114.5K
# Total Submissions: 399.8K
# Testcase Example:  '"aab"'
#
# Given a string s, partition s such that every substring of the partition is a
# palindrome.
# 
# Return the minimum cuts needed for a palindrome partitioning of s.
# 
# Example:
# 
# 
# Input: "aab"
# Output: 1
# Explanation: The palindrome partitioning ["aa","b"] could be produced using 1
# cut.
# 
# 
#

# @lc code=start
class Solution(object):
    def minCut(self, s):
        """
        :type s: str
        :rtype: int
        """
        # 在i后分割
        # dp = [i for i in range(-1, len(s))]
        # for i in range(len(s)):
        #     for j in range(i, len(s)):
        #         if s[i:j] == s[j:i:-1]:
        #             dp[j+1] = min(dp[j+1], dp[i]+1) 
        # return dp[-1]

        # 分割i之前的数
        dp = [i for i in range(len(s))] + [-1]
        for i in range(len(s)):
            for j in range(i, len(s)):
                if s[i:j+1] == s[i:j+1][::-1]: # s[j:i-1:-1]: # 
                    dp[j] = min(dp[j], dp[i-1]+1) 
        return dp[len(s)-1]

        # if s==s[::-1]:
        #     return 0
        # for i in range(1, len(s)):
        #     if s[:i] == s[:i][::-1] and s[i:] == s[i:][::-1]:
        #         return 1

        # is_pal = [[False] * (i + 1) for i in range(len(s))]
        # dp = [i for i in range(len(s))] + [-1]
        
        # for j in range(len(s)):
        #     for i in range(i, -1, -1):
        #         if s[j] == s[i] and (j - i <=1 or is_pal[j - 1][i + 1]):
        #             is_pal[j][i] = True
        #             dp[j] = min(dp[j], dp[i - 1] + 1)
        # return dp[len(s) - 1]   


        # # algorithm
        # dp = [i for i in range(-1,len(s))] 
        # for i in range(len(s)):
        #     r1, r2 = 0, 0

        #     # odd palindrome
        #     while i-r1 >= 0 and i+r1 < len(s) and s[i-r1] == s[i+r1]:
        #         dp[i+r1+1] = min(dp[i+r1+1], dp[i-r1]+1)
        #         r1 += 1

        #     # even palindrome
        #     while i-r2 >= 0 and i+r2+1 < len(s) and s[i-r2] == s[i+r2+1]:
        #         dp[i+r2+2] = min(dp[i+r2+2], dp[i-r2]+1)
        #         r2 += 1

        # return dp[-1]

# @lc code=end

sol = Solution()
s = "aab" # ccaacabacb aab
print(sol.minCut(s))