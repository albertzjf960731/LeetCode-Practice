#
# @lc app=leetcode id=94 lang=python
#
# [94] Binary Tree Inorder Traversal
#
# https://leetcode.com/problems/binary-tree-inorder-traversal/description/
#
# algorithms
# Medium (59.19%)
# Likes:    2100
# Dislikes: 93
# Total Accepted:    557.4K
# Total Submissions: 941.4K
# Testcase Example:  '[1,null,2,3]'
#
# Given a binary tree, return the inorder traversal of its nodes' values.
# 
# Example:
# 
# 
# Input: [1,null,2,3]
# ⁠  1
# ⁠   \
# ⁠    2
# ⁠   /
# ⁠  3
# 
# Output: [1,3,2]
# 
# Follow up: Recursive solution is trivial, could you do it iteratively?
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
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
    #     ret = []
    #     self.traverse(root, ret)
    #     return ret  
    
    # def traverse(self, node, ret):
    #     if not node:
    #         return 
    #     self.traverse(node.left, ret)
    #     ret.append(node.val)
    #     self.traverse(node.right, ret)

        res = []

        stack = []
        cur = root 
        while cur or stack:
            while cur:
                stack.append(cur)
                cur = cur.left
            
            cur = stack.pop()
            res.append(cur.val)
            cur = cur.right

        return res
# @lc code=end

