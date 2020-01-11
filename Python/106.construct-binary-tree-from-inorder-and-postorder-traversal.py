#
# @lc app=leetcode id=106 lang=python
#
# [106] Construct Binary Tree from Inorder and Postorder Traversal
#
# https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
#
# algorithms
# Medium (41.62%)
# Likes:    1107
# Dislikes: 24
# Total Accepted:    178K
# Total Submissions: 425.3K
# Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
#
# Given inorder and postorder traversal of a tree, construct the binary tree.
# 
# Note:
# You may assume that duplicates do not exist in the tree.
# 
# For example, given
# 
# 
# inorder = [9,3,15,20,7]
# postorder = [9,15,7,20,3]
# 
# Return the following binary tree:
# 
# 
# ⁠   3
# ⁠  / \
# ⁠ 9  20
# ⁠   /  \
# ⁠  15   7
# 
# 
#

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# @lc code=start
class Solution(object):
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        # if not inorder or not postorder:
        #     return None
        
        # root = TreeNode(postorder.pop())
        # index = inorder.index(root.val)

        # root.right = self.buildTree(inorder[index+1:], postorder)
        # root.left = self.buildTree(inorder[:index], postorder)

        # return root


        hash_map = {inorder[i]: i for i in range(len(inorder))}

        def DFS(l, r):
            if l > r:
                return None
            root = TreeNode(postorder.pop())
            m = hash_map[root.val]
            root.right = DFS(m+1, r)
            root.left = DFS(l, m-1)
            return root

        return DFS(0, len(inorder)-1)

# @lc code=end

