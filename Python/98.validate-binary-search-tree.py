#
# @lc app=leetcode id=98 lang=python
#
# [98] Validate Binary Search Tree
#
# https://leetcode.com/problems/validate-binary-search-tree/description/
#
# algorithms
# Medium (26.55%)
# Likes:    2582
# Dislikes: 374
# Total Accepted:    505.2K
# Total Submissions: 1.9M
# Testcase Example:  '[2,1,3]'
#
# Given a binary tree, determine if it is a valid binary search tree (BST).
# 
# Assume a BST is defined as follows:
# 
# 
# The left subtree of a node contains only nodes with keys less than the node's
# key.
# The right subtree of a node contains only nodes with keys greater than the
# node's key.
# Both the left and right subtrees must also be binary search trees.
# 
# 
# 
# 
# Example 1:
# 
# 
# ⁠   2
# ⁠  / \
# ⁠ 1   3
# 
# Input: [2,1,3]
# Output: true
# 
# 
# Example 2:
# 
# 
# ⁠   5
# ⁠  / \
# ⁠ 1   4
# / \
# 3   6
# 
# Input: [5,1,4,null,null,3,6]
# Output: false
# Explanation: The root node's value is 5 but its right child's value is 4.
# 
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
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
    #     if not root or (not root.left and  not root.right):
    #         return True

    #     if self.isValidBST(root.left):
    #         if root.left:
    #             if root.val <= self.max_bst(root.left):
    #                 return False
    #     else:
    #         return False

    #     if self.isValidBST(root.right):
    #         if root.right:
    #             if root.val >= self.min_bst(root.right):
    #                 return False
    #     else:
    #         return False
        
    #     return True

        
    # def min_bst(self, root):
    #     m = root.val
    #     while root:
    #         m = min(root.val, m)
    #         root = root.left
    #     return m 
    # def max_bst(self, root):
    #     m = root.val 
    #     while root:
    #         m = max(root.val, m)    
    #         root = root.right
    #     return m

        
    #     inorder = self.inorder_traversal(root)
    #     for i in range(len(inorder)-1):
    #         if inorder[i] >= inorder[i+1]:
    #             return False
    #     return True            

    # def inorder_traversal(self, root):
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


        if not root:
            return True
        
        stack = []
        pre = None
        while root or stack:
            while root:
                stack.append(root)
                root = root.left
            
            root = stack.pop()
            if pre and root.val <= pre.val:
                return False
            pre = root 
            root = root.right

        return True
# @lc code=end

sol = Solution()
root = TreeNode(3)  
root.left = TreeNode(1)
root.right = TreeNode(4)
root.right.left = TreeNode(3)
root.right.right = TreeNode(6)    
print(sol.isValidBST(root))