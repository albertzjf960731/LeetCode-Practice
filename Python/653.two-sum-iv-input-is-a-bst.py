#
# @lc app=leetcode id=653 lang=python
#
# [653] Two Sum IV - Input is a BST
#
# https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
#
# algorithms
# Easy (53.59%)
# Likes:    1064
# Dislikes: 121
# Total Accepted:    109.7K
# Total Submissions: 204.1K
# Testcase Example:  '[5,3,6,2,4,null,7]\n9'
#
# Given a Binary Search Tree and a target number, return true if there exist
# two elements in the BST such that their sum is equal to the given target.
# 
# Example 1:
# 
# 
# Input: 
# ⁠   5
# ⁠  / \
# ⁠ 3   6
# ⁠/ \   \
# 2   4   7
# 
# Target = 9
# 
# Output: True
# 
# 
# 
# 
# Example 2:
# 
# 
# Input: 
# ⁠   5
# ⁠  / \
# ⁠ 3   6
# ⁠/ \   \
# 2   4   7
# 
# Target = 28
# 
# Output: False
# 
# 
# 
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
    def findTarget(self, root, target):
        """
        :type root: TreeNode
        :type k: int
        :rtype: bool
        """
    #     nums = self.inorder(root)
    #     l, r = 0, len(nums)-1
    #     while l<r:
    #         s = nums[l] + nums[r]
    #         if s == target:
    #             return True
    #         elif s<target:
    #             l += 1
    #         else:
    #             r -= 1
    #     return False

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

        if not root:
            return False
        return self.dfs(root, set(), target)

    def dfs(self, root, nodes, target):
        if not root:
            return False

        remain = target-root.val
        if remain in nodes:
            return True
        nodes.add(root.val)
        
        return self.dfs(root.left, nodes, target) or self.dfs(root.right, nodes, target)


# @lc code=end

