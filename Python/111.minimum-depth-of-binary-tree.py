#
# @lc app=leetcode id=111 lang=python
#
# [111] Minimum Depth of Binary Tree
#
# https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
#
# algorithms
# Easy (36.10%)
# Likes:    890
# Dislikes: 508
# Total Accepted:    338.4K
# Total Submissions: 936.9K
# Testcase Example:  '[3,9,20,null,null,15,7]'
#
# Given a binary tree, find its minimum depth.
# 
# The minimum depth is the number of nodes along the shortest path from the
# root node down to the nearest leaf node.
# 
# Note: A leaf is a node with no children.
# 
# Example:
# 
# Given binary tree [3,9,20,null,null,15,7],
# 
# 
# ⁠   3
# ⁠  / \
# ⁠ 9  20
# ⁠   /  \
# ⁠  15   7
# 
# return its minimum depth = 2.
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
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
    #     if not root:
    #         return 0

    #     return self.min_depth(root)
    
    # def min_depth(self, root):
    #     if not root.left and not root.right:
    #         return 1    
    #     elif not root.left:
    #         return self.min_depth(root.right) + 1
    #     elif not root.right:
    #         return self.min_depth(root.left) + 1

    #     return min(self.min_depth(root.left), self.min_depth(root.right)) + 1

        if not root:
            return 0
        left_depth = self.minDepth(root.left)
        right_depth = self.minDepth(root.right)
        if not left_depth or not right_depth:
            return left_depth + right_depth + 1
        return min(left_depth, right_depth)+1


        # if not root:
        #     return 0 
        
        # from collections import deque 
        # queue = deque([root])

        # level = 1
        # while queue:
        #     for _ in range(len(queue)):
        #         node = queue.popleft()
        #         if not node.left and not node.right:
        #             return level
        #         # if node:
        #         if node.left:
        #             queue.append(node.left)
        #         if node.right:
        #             queue.append(node.right)

        #     level += 1
        # return level
# @lc code=end

