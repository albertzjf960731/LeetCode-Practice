#
# @lc app=leetcode id=404 lang=python
#
# [404] Sum of Left Leaves
#
# https://leetcode.com/problems/sum-of-left-leaves/description/
#
# algorithms
# Easy (49.82%)
# Likes:    800
# Dislikes: 93
# Total Accepted:    145.9K
# Total Submissions: 292.5K
# Testcase Example:  '[3,9,20,null,null,15,7]'
#
# Find the sum of all left leaves in a given binary tree.
# 
# Example:
# 
# ⁠   3
# ⁠  / \
# ⁠ 9  20
# ⁠   /  \
# ⁠  15   7
# 
# There are two left leaves in the binary tree, with values 9 and 15
# respectively. Return 24.
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
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        # if not root:
        #     return 0 

        # if root.left and not root.left.left and not root.left.right:
        #     return root.left.val + self.sumOfLeftLeaves(root.right) 
        
        # return self.sumOfLeftLeaves(root.left) + self.sumOfLeftLeaves(root.right)

        ans = 0
        stack = [(root, False)]
        while stack:
            cur, is_left = stack.pop()

            if not cur:
                continue
            if not cur.left and not cur.right:
                if is_left:
                    ans += cur.val
            else:
                stack.append((cur.left, True))
                stack.append((cur.right, False))
        return ans

        
# @lc code=end

