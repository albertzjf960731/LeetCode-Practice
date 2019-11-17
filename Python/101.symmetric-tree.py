#
# @lc app=leetcode id=101 lang=python
#
# [101] Symmetric Tree
#
# https://leetcode.com/problems/symmetric-tree/description/
#
# algorithms
# Easy (44.75%)
# Likes:    2787
# Dislikes: 61
# Total Accepted:    485.4K
# Total Submissions: 1.1M
# Testcase Example:  '[1,2,2,3,4,4,3]'
#
# Given a binary tree, check whether it is a mirror of itself (ie, symmetric
# around its center).
# 
# For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
# 
# 
# ⁠   1
# ⁠  / \
# ⁠ 2   2
# ⁠/ \ / \
# 3  4 4  3
# 
# 
# 
# 
# But the following [1,2,2,null,3,null,3] is not:
# 
# 
# ⁠   1
# ⁠  / \
# ⁠ 2   2
# ⁠  \   \
# ⁠  3    3
# 
# 
# 
# 
# Note:
# Bonus points if you could solve it both recursively and iteratively.
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
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
    #     if not root:
    #         return True  
    #     return self.helper(root.left, root.right)
    
    # def helper(self, left, right):
    #     if (not left and right) or (not right and left):
    #         return False
        
    #     if left and right:
    #         if left.val != right.val:
    #             return False
    #         return self.helper(left.left, right.right) and self.helper(left.right, right.left)
    #     return True

        # if not root:
        #     return True

        # left_stack, right_stack = [], []
        # cur_left, cur_right = root.left, root.right 

        # while cur_left or left_stack or cur_right or right_stack:
        #     while cur_left:
        #         left_stack.append(cur_left)
        #         cur_left = cur_left.left 
            
        #     while cur_right:
        #         right_stack.append(cur_right)
        #         cur_right = cur_right.right

        #     if len(left_stack) != len(right_stack):
        #         return False
            
        #     cur_left = left_stack.pop()
        #     cur_right = right_stack.pop()
           
        #     if cur_left.val != cur_right.val:
        #         return False
            
        #     cur_left = cur_left.right 
        #     cur_right = cur_right.left

        # return True 

        if not root:
            return True 

        from collections import deque
        left_queue = deque([root.left])
        right_queue = deque([root.right])

        while left_queue and right_queue:
            cur_left = left_queue.popleft()
            cur_right = right_queue.popleft()

            if (not cur_left and cur_right) or (not cur_right and cur_left):
                return False
            
            if cur_left and cur_right:
                if cur_left.val != cur_right.val:
                    return False
                left_queue.append(cur_left.left)
                left_queue.append(cur_left.right)

                right_queue.append(cur_right.right)
                right_queue.append(cur_right.left)

        if left_queue or right_queue:
            return False
        return True
    
# @lc code=end

