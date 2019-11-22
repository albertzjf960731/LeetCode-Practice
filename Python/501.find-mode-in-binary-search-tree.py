#
# @lc app=leetcode id=501 lang=python
#
# [501] Find Mode in Binary Search Tree
#
# https://leetcode.com/problems/find-mode-in-binary-search-tree/description/
#
# algorithms
# Easy (40.41%)
# Likes:    658
# Dislikes: 263
# Total Accepted:    67.6K
# Total Submissions: 167K
# Testcase Example:  '[1,null,2,2]'
#
# Given a binary search tree (BST) with duplicates, find all the mode(s) (the
# most frequently occurred element) in the given BST.
# 
# Assume a BST is defined as follows:
# 
# 
# The left subtree of a node contains only nodes with keys less than or equal
# to the node's key.
# The right subtree of a node contains only nodes with keys greater than or
# equal to the node's key.
# Both the left and right subtrees must also be binary search trees.
# 
# 
# 
# 
# For example:
# Given BST [1,null,2,2],
# 
# 
# ⁠  1
# ⁠   \
# ⁠    2
# ⁠   /
# ⁠  2
# 
# 
# 
# 
# return [2].
# 
# Note: If a tree has more than one mode, you can return them in any order.
# 
# Follow up: Could you do that without using any extra space? (Assume that the
# implicit stack space incurred due to recursion does not count).
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
    def findMode(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        
        if not root:
            return []
            
        nums = []
        self.inorder(root, nums)

        res = {}
        for num in nums:
            res[num] = res.get(num, 0)+1  
        mode = max(v for k, v in res.items())
        return [num for num in res if res[num] == mode]

    def inorder(self, node, res):
        if not node:
            return 
        self.inorder(node.left, res)
        res.append(node.val)
        self.inorder(node.right, res)


    # def inorder(self, root):
    #     res = []

    #     stack = []
    #     cur = root 
    #     while cur or stack:
    #         while cur:
    #             stack.append(cur)
    #             cur = cur.left
            
    #         cur = stack.pop()
    #         res.append(cur.val)
    #         cur = cur.right

    #     return res
# @lc code=end

