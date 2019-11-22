#
# @lc app=leetcode id=671 lang=python
#
# [671] Second Minimum Node In a Binary Tree
#
# https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/description/
#
# algorithms
# Easy (43.08%)
# Likes:    458
# Dislikes: 677
# Total Accepted:    60K
# Total Submissions: 139.3K
# Testcase Example:  '[2,2,5,null,null,5,7]'
#
# Given a non-empty special binary tree consisting of nodes with the
# non-negative value, where each node in this tree has exactly two or zero
# sub-node. If the node has two sub-nodes, then this node's value is the
# smaller value among its two sub-nodes. More formally, the property root.val =
# min(root.left.val, root.right.val) always holds.
# 
# Given such a binary tree, you need to output the second minimum value in the
# set made of all the nodes' value in the whole tree.
# 
# If no such second minimum value exists, output -1 instead.
# 
# Example 1:
# 
# 
# Input: 
# ⁠   2
# ⁠  / \
# ⁠ 2   5
# ⁠    / \
# ⁠   5   7
# 
# Output: 5
# Explanation: The smallest value is 2, the second smallest value is 5.
# 
# 
# 
# 
# Example 2:
# 
# 
# Input: 
# ⁠   2
# ⁠  / \
# ⁠ 2   2
# 
# Output: -1
# Explanation: The smallest value is 2, but there isn't any second smallest
# value.
# 
# 
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
    def findSecondMinimumValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return -1
        
        if not root.left and not root.right:
            return -1
            
        left_val = root.left.val
        right_val = root.right.val
        if root.left.val == root.val:
            left_val = self.findSecondMinimumValue(root.left)
        if root.right.val == root.val:
            right_val = self.findSecondMinimumValue(root.right)
        
        if left_val!=-1 and right_val!=-1:
            return min(left_val, right_val)
        elif left_val!=-1:
            return left_val
        else:
            return right_val




# @lc code=end

sol = Solution()
root = TreeNode(2)  
root.left = TreeNode(2)
root.right = TreeNode(5)
root.right.left = TreeNode(5)
root.right.right = TreeNode(7)
print(sol.findSecondMinimumValue(root))