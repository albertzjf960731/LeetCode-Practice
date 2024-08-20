#
# @lc app=leetcode id=650 lang=python
#
# [650] 2 Keys Keyboard
#
# https://leetcode.com/problems/2-keys-keyboard/description/
#
# algorithms
# Medium (47.45%)
# Likes:    786
# Dislikes: 56
# Total Accepted:    40.8K
# Total Submissions: 86K
# Testcase Example:  '3'
#
# Initially on a notepad only one character 'A' is present. You can perform two
# operations on this notepad for each step:
# 
# 
# Copy All: You can copy all the characters present on the notepad (partial
# copy is not allowed).
# Paste: You can paste the characters which are copied last time.
# 
# 
# 
# 
# Given a number n. You have to get exactly n 'A' on the notepad by performing
# the minimum number of steps permitted. Output the minimum number of steps to
# get n 'A'.
# 
# Example 1:
# 
# 
# Input: 3
# Output: 3
# Explanation:
# Intitally, we have one character 'A'.
# In step 1, we use Copy All operation.
# In step 2, we use Paste operation to get 'AA'.
# In step 3, we use Paste operation to get 'AAA'.
# 
# 
# 
# 
# Note:
# 
# 
# The n will be in the range [1, 1000].
# 
# 
# 
# 
#

# @lc code=start
class Solution(object):
    def minSteps(self, n):
        """
        :type n: int
        :rtype: int
        """
        # dp = [0 for _ in range(n)]
        # dp[2] = 2
        # dp[3] = 3
        # dp[4] = 4
        # dp[5] = 

        # copy all means i has to be a factor of n
        if n == 1:
            return 0
        for i in range(2, int(n**0.5)+1):
            if n % i == 0:
                return self.minSteps(n//i)+i
        return n 

        # dp = [0 for _ in range(n+1)]
        # h = int(n**0.5)
        # for i in range(2, n+1):
        #     dp[i] = i
        #     for j in range(2, h+1):
        #         if i%j == 0:
        #             dp[i] = dp[j] + dp[i//j]    
        # return dp[n]


# @lc code=end

