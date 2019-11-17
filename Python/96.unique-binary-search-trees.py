#
# @lc app=leetcode id=96 lang=python
#
# [96] Unique Binary Search Trees
#
# https://leetcode.com/problems/unique-binary-search-trees/description/
#
# algorithms
# Medium (48.31%)
# Likes:    2170
# Dislikes: 84
# Total Accepted:    228.8K
# Total Submissions: 473.7K
# Testcase Example:  '3'
#
# Given n, how many structurally unique BST's (binary search trees) that store
# values 1 ... n?
# 
# Example:
# 
# 
# Input: 3
# Output: 5
# Explanation:
# Given n = 3, there are a total of 5 unique BST's:
# 
# ⁠  1         3     3      2      1
# ⁠   \       /     /      / \      \
# ⁠    3     2     1      1   3      2
# ⁠   /     /       \                 \
# ⁠  2     1         2                 3
# 
# 
#

# @lc code=start
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        # 递归
    #     self.memory = dict()

    #     if n == 0:
    #         return 0
    #     return self.helper(n)

    # def helper(self, n):
    #     if n in self.memory:
    #         return self.memory[n]

    #     res = 0
    #     if n==0 or n == 1:
    #         return 1

    #     for i in range(1, n+1):
            
    #         left_num = self.helper(i-1)
    #         right_num = self.helper(n-i)

    #         res += left_num * right_num

    #     self.memory[n] = res 

    #     return res
 
        # 动态规划
        if n == 0:
            return 0
        
        dp = [0 for _ in range(n+1)]
        dp[0] = 1
        for i in range(1, n+1):
            for root in range(1, i+1):
                left = root-1
                right = i - root
                dp[i] += dp[left] * dp[right]
        return dp[n]


# @lc code=end

