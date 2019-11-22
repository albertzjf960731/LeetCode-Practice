#
# @lc app=leetcode id=110 lang=python
#
# [110] Balanced Binary Tree
#
# https://leetcode.com/problems/balanced-binary-tree/description/
#
# algorithms
# Easy (41.97%)
# Likes:    1540
# Dislikes: 140
# Total Accepted:    369.7K
# Total Submissions: 880K
# Testcase Example:  '[3,9,20,null,null,15,7]'
#
# Given a binary tree, determine if it is height-balanced.
# 
# For this problem, a height-balanced binary tree is defined as:
# 
# 
# a binary tree in which the left and right subtrees of every node differ in
# height by no more than 1.
# 
# 
# 
# 
# Example 1:
# 
# Given the following tree [3,9,20,null,null,15,7]:
# 
# 
# ⁠   3
# ⁠  / \
# ⁠ 9  20
# ⁠   /  \
# ⁠  15   7
# 
# Return true.
# 
# Example 2:
# 
# Given the following tree [1,2,2,3,3,null,null,4,4]:
# 
# 
# ⁠      1
# ⁠     / \
# ⁠    2   2
# ⁠   / \
# ⁠  3   3
# ⁠ / \
# ⁠4   4
# 
# 
# Return false.
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
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        # if not root:
        #     return True

        # left_depth = self.depth(root.left)
        # right_depth = self.depth(root.right)

        # if abs(left_depth - right_depth) > 1:
        #     return False

        # return self.isBalanced(root.left) and self.isBalanced(root.right)

        self.ans = True
        self.depth(root)
        return self.ans 
        
    def depth(self, root):
        if not root:
            return 0 

        left_depth = self.depth(root.left)
        right_depth = self.depth(root.right)
        
        # if left_depth == -1:
        #     return -1
        # if right_depth == -1:
        #     return -1    
    
        if abs(left_depth - right_depth) > 1:
            self.ans = False

        return max(left_depth, right_depth) + 1

# @lc code=end

