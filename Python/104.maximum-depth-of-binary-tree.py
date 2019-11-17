#
# @lc app=leetcode id=104 lang=python
#
# [104] Maximum Depth of Binary Tree
#
# https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
#
# algorithms
# Easy (62.60%)
# Likes:    1655
# Dislikes: 61
# Total Accepted:    613.8K
# Total Submissions: 979.7K
# Testcase Example:  '[3,9,20,null,null,15,7]'
#
# Given a binary tree, find its maximum depth.
# 
# The maximum depth is the number of nodes along the longest path from the root
# node down to the farthest leaf node.
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
# return its depth = 3.
# 
#

# @lc code=start
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        # if not root:
        #     return 0 
        # return max(self.maxDepth(root.left), self.maxDepth(root.right)) + 1

        if not root:
            return 0 
        
        from collections import deque 
        queue = deque([root])

        level = 0
        while queue:
            for _ in range(len(queue)):
                node = queue.popleft()
                # if node:
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

            level += 1
        return level
            
# @lc code=end

