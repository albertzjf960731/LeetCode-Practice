#
# @lc app=leetcode id=667 lang=python
#
# [667] Beautiful Arrangement II
#
# https://leetcode.com/problems/beautiful-arrangement-ii/description/
#
# algorithms
# Medium (52.77%)
# Likes:    262
# Dislikes: 554
# Total Accepted:    20.5K
# Total Submissions: 38.9K
# Testcase Example:  '3\n2'
#
# 
# Given two integers n and k, you need to construct a list which contains n
# different positive integers ranging from 1 to n and obeys the following
# requirement: 
# 
# Suppose this list is [a1, a2, a3, ... , an], then the list [|a1 - a2|, |a2 -
# a3|, |a3 - a4|, ... , |an-1 - an|] has exactly k distinct integers.
# 
# 
# 
# If there are multiple answers, print any of them.
# 
# 
# Example 1:
# 
# Input: n = 3, k = 1
# Output: [1, 2, 3]
# Explanation: The [1, 2, 3] has three different positive integers ranging from
# 1 to 3, and the [1, 1] has exactly 1 distinct integer: 1.
# 
# 
# 
# Example 2:
# 
# Input: n = 3, k = 2
# Output: [1, 3, 2]
# Explanation: The [1, 3, 2] has three different positive integers ranging from
# 1 to 3, and the [2, 1] has exactly 2 distinct integers: 1 and 2.
# 
# 
# 
# Note:
# 
# The n and k are in the range 1 
# 
# 
#

# @lc code=start
class Solution(object):
    def constructArray(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[int]
        """
        res = [0 for _ in range(n)]
        res[0] = 1
        
        i = 1 
        interval = k
        while i<=k:
            res[i] = res[i-1]+interval if i%2==1 else res[i-1] -interval

            i+=1
            interval-=1

        for i in range(k+1, n):
            res[i] = i+1
        return res
# @lc code=end

