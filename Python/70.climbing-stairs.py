#
# @lc app=leetcode id=70 lang=python
#
# [70] Climbing Stairs
#
# https://leetcode.com/problems/climbing-stairs/description/
#
# algorithms
# Easy (45.35%)
# Likes:    2815
# Dislikes: 98
# Total Accepted:    498.9K
# Total Submissions: 1.1M
# Testcase Example:  '2'
#
# You are climbing a stair case. It takes n steps to reach to the top.
# 
# Each time you can either climb 1 or 2 steps. In how many distinct ways can
# you climb to the top?
# 
# Note: Given n will be a positive integer.
# 
# Example 1:
# 
# 
# Input: 2
# Output: 2
# Explanation: There are two ways to climb to the top.
# 1. 1 step + 1 step
# 2. 2 steps
# 
# 
# Example 2:
# 
# 
# Input: 3
# Output: 3
# Explanation: There are three ways to climb to the top.
# 1. 1 step + 1 step + 1 step
# 2. 1 step + 2 steps
# 3. 2 steps + 1 step
# 
# 
#

# @lc code=start
class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        # if n == 1:
        #     return 1
        # elif n == 2:
        #     return 2 
        # return self.climbStairs(n-1) + self.climbStairs(n-2)
        
        # if n == 1:
        #     return 1
        # if n == 2:
        #     return 2
        # num_dict = {1:1, 2: 2}

        # for i in range(3, n+1):
        #     num_dict[i] = num_dict[i-1] + num_dict[i-2]
        # return num_dict[n]

        if n == 1:
            return 1
        if n == 2:
            return 2
        pre2 = 1
        pre1 = 2
        for i in range(3, n+1):
            cur = pre1 + pre2
            pre2, pre1 = pre1, cur
        return cur
            

# @lc code=end

