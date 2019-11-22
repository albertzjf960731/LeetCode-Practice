#
# @lc app=leetcode id=530 lang=python
#
# [530] Minimum Absolute Difference in BST
#
# https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
#
# algorithms
# Easy (51.71%)
# Likes:    626
# Dislikes: 51
# Total Accepted:    71.3K
# Total Submissions: 137.6K
# Testcase Example:  '[1,null,3,2]'
#
# Given a binary search tree with non-negative values, find the minimum
# absolute difference between values of any two nodes.
# 
# Example:
# 
# 
# Input:
# 
# ⁠  1
# ⁠   \
# ⁠    3
# ⁠   /
# ⁠  2
# 
# Output:
# 1
# 
# Explanation:
# The minimum absolute difference is 1, which is the difference between 2 and 1
# (or between 2 and 3).
# 
# 
# 
# 
# Note: There are at least two nodes in this BST.
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def getMinimumDifference(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        res = []
        self.inorder(root, res)
        ans = float('inf')
        for i in range(len(res)-1):
            ans = min(ans, abs(res[i]-res[i+1]))
        return ans 
    
    def inorder(self, node, res):
        if not node:
            return 
        self.inorder(node.left, res)
        res.append(node.val)
        self.inorder(node.right, res)

        
# @lc code=end

