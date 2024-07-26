#
# @lc app=leetcode id=993 lang=python3
#
# [993] Cousins in Binary Tree
#
# https://leetcode.com/problems/cousins-in-binary-tree/description/
#
# algorithms
# Easy (56.12%)
# Likes:    4013
# Dislikes: 206
# Total Accepted:    282.2K
# Total Submissions: 500.2K
# Testcase Example:  '[1,2,3,4]\n4\n3'
#
# Given the root of a binary tree with unique values and the values of two
# different nodes of the tree x and y, return true if the nodes corresponding
# to the values x and y in the tree are cousins, or false otherwise.
# 
# Two nodes of a binary tree are cousins if they have the same depth with
# different parents.
# 
# Note that in a binary tree, the root node is at the depth 0, and children of
# each depth k node are at the depth k + 1.
# 
# 
# Example 1:
# 
# 
# Input: root = [1,2,3,4], x = 4, y = 3
# Output: false
# 
# 
# Example 2:
# 
# 
# Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
# Output: true
# 
# 
# Example 3:
# 
# 
# Input: root = [1,2,3,null,4], x = 2, y = 3
# Output: false
# 
# 
# 
# Constraints:
# 
# 
# The number of nodes in the tree is in the range [2, 100].
# 1 <= Node.val <= 100
# Each node has a unique value.
# x != y
# x and y are exist in the tree.
# 
# 
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCousins(self, root: Optional[TreeNode], x: int, y: int) -> bool:
        queue = deque([root])
        while queue:
            tmp = []
            for _ in range(len(queue)):
                node = queue.popleft()

                tmp.append(node.val)
                if node.left and node.right:
                    if (node.left.val == x and node.right.val == y) or (node.left.val == y and node.right.val == x):
                        return False

                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            if x in tmp and y in tmp:
                return True
        return False


        self.x_depth = 0
        self.y_depth = 0
        self.x_parent = None
        self.y_parent = None
        self.dfs(root, x, y, 0, None)
        return self.x_depth == self.y_depth and self.x_parent != self.y_parent

    def dfs(self, root, x, y, depth, parent):
        if not root:
            return
        if root.val == x:
            self.x_depth = depth
            self.x_parent = parent
        if root.val == y:
            self.y_depth = depth
            self.y_parent = parent
        self.dfs(root.left, x, y, depth+1, root)
        self.dfs(root.right, x, y, depth+1, root)
# @lc code=end

