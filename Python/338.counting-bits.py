#
# @lc app=leetcode id=338 lang=python
#
# [338] Counting Bits
#
# https://leetcode.com/problems/counting-bits/description/
#
# algorithms
# Medium (65.94%)
# Likes:    1746
# Dislikes: 121
# Total Accepted:    201.4K
# Total Submissions: 305K
# Testcase Example:  '2'
#
# Given a non negative integer number num. For every numbers i in the range 0 ≤
# i ≤ num calculate the number of 1's in their binary representation and return
# them as an array.
# 
# Example 1:
# 
# 
# Input: 2
# Output: [0,1,1]
# 
# Example 2:
# 
# 
# Input: 5
# Output: [0,1,1,2,1,2]
# 
# 
# Follow up:
# 
# 
# It is very easy to come up with a solution with run time
# O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a
# single pass?
# Space complexity should be O(n).
# Can you do it like a boss? Do it without using any builtin function like
# __builtin_popcount in c++ or in any other language.
# 
#

# @lc code=start
class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        dp = [0 for _ in range(num+1)]

        for n in range(1, num+1):
            dp[n] = dp[n>>1] + (n&1)
            # dp[n] = dp[n&(n-1)] + 1

        return dp
        
# @lc code=end
sol = Solution()
sol.countBits(4)
