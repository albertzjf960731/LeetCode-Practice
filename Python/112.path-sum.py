#
# @lc app=leetcode id=112 lang=python
#
# [112] Path Sum
#
# https://leetcode.com/problems/path-sum/description/
#
# algorithms
# Easy (39.04%)
# Likes:    1203
# Dislikes: 380
# Total Accepted:    367.5K
# Total Submissions: 941.3K
# Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22'
#
# Given a binary tree and a sum, determine if the tree has a root-to-leaf path
# such that adding up all the values along the path equals the given sum.
# 
# Note: A leaf is a node with no children.
# 
# Example:
# 
# Given the below binary tree and sum = 22,
# 
# 
# ⁠     5
# ⁠    / \
# ⁠   4   8
# ⁠  /   / \
# ⁠ 11  13  4
# ⁠/  \      \
# 7    2      1
# 
# 
# return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
    def hasPathSum(self, root, target):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """

    #     stack = []
    #     stack_sum = []
    #     cur = root 
    #     cur_sum = 0 
    #     while cur or stack:
    #         while cur:
    #             stack.append(cur)
                
    #             cur_sum += cur.val
    #             stack_sum.append(cur_sum)
                
    #             cur = cur.left
            
    #         # if self.stack_sum(stack) == target and not cur:
    #         #     return True
            
    #         cur = stack.pop()
            
    #         cur_sum = stack_sum.pop()
    #         if cur_sum == target and not cur.left and not cur.right:
    #             return True

    #         cur = cur.right
    #     return False
    
    # def stack_sum(self, stack):
    #     s = 0
    #     for node in stack:
    #         s += node.val 
    #     return s

    # === 递归 === 
    #     if not root:
    #         return False

    #     return self.dfs(root, target)
    
    # def dfs(self, root, target):
    #     if not root.left and not root.right:
    #         return root.val == target
    #     elif not root.left:
    #         return self.dfs(root.right, target-root.val)
    #     elif not root.right:
    #         return self.dfs(root.left, target-root.val)
    #     else:
    #         return self.dfs(root.left, target-root.val) or self.helper(root.right, target-root.val)


        if not root:
            return False
        if not root.left and not root.right:
            return root.val == target
        return self.hasPathSum(root.left, target-root.val) or self.hasPathSum(root.right, target-root.val) 


# @lc code=end
