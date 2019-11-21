#
# @lc app=leetcode id=343 lang=python
#
# [343] Integer Break
#
# https://leetcode.com/problems/integer-break/description/
#
# algorithms
# Medium (48.78%)
# Likes:    703
# Dislikes: 193
# Total Accepted:    90.9K
# Total Submissions: 186.1K
# Testcase Example:  '2'
#
# Given a positive integer n, break it into the sum of at least two positive
# integers and maximize the product of those integers. Return the maximum
# product you can get.
# 
# Example 1:
# 
# 
# 
# Input: 2
# Output: 1
# Explanation: 2 = 1 + 1, 1 × 1 = 1.
# 
# 
# Example 2:
# 
# 
# Input: 10
# Output: 36
# Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
# 
# Note: You may assume that n is not less than 2 and not larger than 58.
# 
# 
#

# @lc code=start
class Solution(object):
    def integerBreak(self, n):
        """
        :type n: int
        :rtype: int
        """
        # # dp[i] = max(dp[i], dp[i-j]*j] j<i
        # dp = [i-1 for i in range(n+1)]
        # for i in range(2, n+1):
        #     for j in range(1, i):
        #         dp[i] = max(dp[i], dp[i-j]*j, (i-j)*j)
        # return dp[n]

        # break it into nearly all e's
        if n == 2 or n == 3:
            return n - 1
        if n % 3 == 0:
            return 3**(n/3)
        if n % 3 == 1:
            return 3**(n/3 - 1)*4
        if n % 3 == 2:
            return 3**(n/3)*2

        
# @lc code=end

sol = Solution()
n = 10
print(sol.integerBreak(n))
