#
# @lc app=leetcode id=91 lang=python
#
# [91] Decode Ways
#
# https://leetcode.com/problems/decode-ways/description/
#
# algorithms
# Medium (23.12%)
# Likes:    1826
# Dislikes: 2063
# Total Accepted:    311.3K
# Total Submissions: 1.3M
# Testcase Example:  '"12"'
#
# A message containing letters from A-Z is being encoded to numbers using the
# following mapping:
# 
# 
# 'A' -> 1
# 'B' -> 2
# ...
# 'Z' -> 26
# 
# 
# Given a non-empty string containing only digits, determine the total number
# of ways to decode it.
# 
# Example 1:
# 
# 
# Input: "12"
# Output: 2
# Explanation: It could be decoded as "AB" (1 2) or "L" (12).
# 
# 
# Example 2:
# 
# 
# Input: "226"
# Output: 3
# Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
# 6).
# 
#

# @lc code=start
class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s or s[0] == '0':
            return 0 
        
        n = len(s)
        dp = [0 for _ in range(n+1)]
        dp[0] = 1
        dp[1] = 1 if s[0]!='0' else 0

        for i in range(2, n+1):

            first = int(s[i-1:i])
            second = int(s[i-2:i])
            if 1<= first <= 9:
                dp[i] += dp[i-1]    
            if 10 <= second <= 26:
                dp[i] += dp[i-2]    

        return dp[-1]

        # first = 1
        # second = 1 if s[0]!='0' else 0

        # for i in range(2, n+1):
        #     cur = 0 
        #     if 1<= int(s[i-1:i]) <= 9:
        #         cur += first   
        #     if 10 <= int(s[i-2:i]) <= 26:
        #         cur += second   

        #     second = first
        #     first = cur
        # return first
# @lc code=end

sol = Solution()
s = '226'
print(sol.numDecodings(s))