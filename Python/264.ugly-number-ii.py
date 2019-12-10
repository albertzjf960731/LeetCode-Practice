#
# @lc app=leetcode id=264 lang=python
#
# [264] Ugly Number II
#
# https://leetcode.com/problems/ugly-number-ii/description/
#
# algorithms
# Medium (37.84%)
# Likes:    1199
# Dislikes: 74
# Total Accepted:    121.6K
# Total Submissions: 320.2K
# Testcase Example:  '10'
#
# Write a program to find the n-th ugly number.
# 
# Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
# 
# Example:
# 
# 
# Input: n = 10
# Output: 12
# Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10
# ugly numbers.
# 
# Note:  
# 
# 
# 1 is typically treated as an ugly number.
# n does not exceed 1690.
# 
#

# @lc code=start
class Solution(object):
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [0] * n 
        dp[0] = 1

        i2, i3, i5 = 0, 0 , 0
        for i in range(1, n):
            dp[i] = min(dp[i2]*2, dp[i3]*3, dp[i5]*5)
            if dp[i] == dp[i2]*2:
                i2+=1
            if dp[i] == dp[i3]*3:
                i3+=1
            if dp[i] == dp[i5]*5:
                i5+=1
        return dp[n-1]


# @lc code=end

