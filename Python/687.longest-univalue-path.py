#
# @lc app=leetcode id=687 lang=python
#
# [687] Longest Univalue Path
#
# https://leetcode.com/problems/longest-univalue-path/description/
#
# algorithms
# Easy (34.64%)
# Likes:    1207
# Dislikes: 314
# Total Accepted:    71.7K
# Total Submissions: 206.6K
# Testcase Example:  '[5,4,5,1,1,5]'
#
# Given a binary tree, find the length of the longest path where each node in
# the path has the same value. This path may or may not pass through the root.
# 
# The length of path between two nodes is represented by the number of edges
# between them.
# 
# 
# 
# Example 1:
# 
# Input:
# 
# 
# ⁠             5
# ⁠            / \
# ⁠           4   5
# ⁠          / \   \
# ⁠         1   1   5
# 
# 
# Output: 2
# 
# 
# 
# Example 2:
# 
# Input:
# 
# 
# ⁠             1
# ⁠            / \
# ⁠           4   5
# ⁠          / \   \
# ⁠         4   4   5
# 
# 
# Output: 2
# 
# 
# 
# Note: The given binary tree has not more than 10000 nodes. The height of the
# tree is not more than 1000.
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
    def longestUnivaluePath(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """

    #     self.ans = 0
    #     self.dfs(root)
    #     return self.ans

    # def dfs(self, root):
    #     if not root:
    #         return 0

    #     # 先计算，不然会覆盖结果
    #     left = self.dfs(root.left)
    #     right = self.dfs(root.right)

    #     if root.left and root.left.val == root.val:
    #         left_path = left+1  
    #     else:
    #         left_path = 0
    #     if root.right and root.right.val == root.val:
    #         right_path = right+1  
    #     else:
    #         right_path = 0
    #     self.ans = max(self.ans, left_path + right_path)
    #     return max(left_path, right_path)


        return self.dfs(root)[0]
    def dfs(self, root):
        if not root:
            return (0, 0)
        l1, l2 = self.dfs(root.left)
        r1, r2 = self.dfs(root.right)

        if root.left and root.left.val == root.val:
            l2 += 1
        else:
            l2 = 0
        if root.right and root.right.val == root.val:
            r2 += 1
        else:
            r2 = 0 
        return max(l1, r1, l2 + r2), max(l2, r2)


# @lc code=end

sol = Solution()
root = TreeNode(5)
root.left = TreeNode(4) 
root.left.left = TreeNode(1)
root.left.right = TreeNode(1)
root.right = TreeNode(5)
root.right.right = TreeNode(5)
print(sol.longestUnivaluePath(root))