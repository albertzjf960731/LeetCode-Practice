#
# @lc app=leetcode id=255 lang=python3
#
# [255] Verify Preorder Sequence in Binary Search Tree
#
# https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/description/
#
# algorithms
# Medium (49.95%)
# Likes:    1201
# Dislikes: 89
# Total Accepted:    81.7K
# Total Submissions: 163.2K
# Testcase Example:  '[5,2,1,3,6]'
#
# Given an array of unique integers preorder, return true if it is the correct
# preorder traversal sequence of a binary search tree.
# 
# 
# Example 1:
# 
# 
# Input: preorder = [5,2,1,3,6]
# Output: true
# 
# 
# Example 2:
# 
# 
# Input: preorder = [5,2,6,1,3]
# Output: false
# 
# 
# 
# Constraints:
# 
# 
# 1 <= preorder.length <= 10^4
# 1 <= preorder[i] <= 10^4
# All the elements of preorder are unique.
# 
# 
# 
# Follow up: Could you do it using only constant space complexity?
# 
#

# @lc code=start
class Solution:
    def verifyPreorder(self, preorder: List[int]) -> bool:
        min_val = float('-inf')
        stack = []
        for num in preorder:
            while stack and num > stack[-1]:
                min_val = stack.pop()
            if num < min_val:
                return False
            stack.append(num)
        return True
    
        inorder = []
        stack = []
        for num in preorder:
            while stack and num > stack[-1]:
                inorder.append(stack.pop())
            stack.append(num)
        inorder.extend(reversed(stack))
        return inorder == sorted(inorder)
        
# @lc code=end

