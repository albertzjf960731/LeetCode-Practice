#
# @lc app=leetcode id=543 lang=python
#
# [543] Diameter of Binary Tree
#
# https://leetcode.com/problems/diameter-of-binary-tree/description/
#
# algorithms
# Easy (47.65%)
# Likes:    1844
# Dislikes: 113
# Total Accepted:    178K
# Total Submissions: 372.4K
# Testcase Example:  '[1,2,3,4,5]'
#
# 
# Given a binary tree, you need to compute the length of the diameter of the
# tree. The diameter of a binary tree is the length of the longest path between
# any two nodes in a tree. This path may or may not pass through the root.
# 
# 
# 
# Example:
# Given a binary tree 
# 
# ⁠         1
# ⁠        / \
# ⁠       2   3
# ⁠      / \     
# ⁠     4   5    
# 
# 
# 
# Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
# 
# 
# Note:
# The length of path between two nodes is represented by the number of edges
# between them.
# 
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.dia = 0
        self.depth(root)
        return self.dia

    def depth(self, root):
        if not root:
            return 0 

        left_depth = self.depth(root.left)
        righ_depth = self.depth(root.right)
        
        self.dia = max(self.dia, left_depth+righ_depth)
        return max(left_depth, righ_depth) + 1

# @lc code=end

