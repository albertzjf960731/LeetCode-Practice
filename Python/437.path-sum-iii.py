#
# @lc app=leetcode id=437 lang=python
#
# [437] Path Sum III
#
# https://leetcode.com/problems/path-sum-iii/description/
#
# algorithms
# Easy (44.09%)
# Likes:    2400
# Dislikes: 154
# Total Accepted:    134.6K
# Total Submissions: 304.4K
# Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
#
# You are given a binary tree in which each node contains an integer value.
# 
# Find the number of paths that sum to a given value.
# 
# The path does not need to start or end at the root or a leaf, but it must go
# downwards
# (traveling only from parent nodes to child nodes).
# 
# The tree has no more than 1,000 nodes and the values are in the range
# -1,000,000 to 1,000,000.
# 
# Example:
# 
# root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
# 
# ⁠     10
# ⁠    /  \
# ⁠   5   -3
# ⁠  / \    \
# ⁠ 3   2   11
# ⁠/ \   \
# 3  -2   1
# 
# Return 3. The paths that sum to 8 are:
# 
# 1.  5 -> 3
# 2.  5 -> 2 -> 1
# 3. -3 -> 11
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
    def pathSum(self, root, target):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: int
        """
        if not root:
            return 0

        return self.dfs(root, target) + self.pathSum(root.left, target) + self.pathSum(root.right, target)
    
    def dfs(self, root, target):
        if not root:
            return 0 
        # if target<0:
        #     return 0 

        ans = 0
        if root.val == target:
            ans += 1
        ans += self.dfs(root.left, target-root.val)
        ans += self.dfs(root.right, target-root.val)
        return ans 

# @lc code=end

sol = Solution()
# [1,null,2,null,3,null,4,null,5]
root = TreeNode(1)
root.right = TreeNode(2)
root.right.right = TreeNode(3)
root.right.right.right = TreeNode(4)
root.right.right.right.right = TreeNode(5)
print(sol.pathSum(root, 3))
