#
# @lc app=leetcode id=109 lang=python
#
# [109] Convert Sorted List to Binary Search Tree
#
# https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
#
# algorithms
# Medium (43.18%)
# Likes:    1320
# Dislikes: 75
# Total Accepted:    200.3K
# Total Submissions: 463K
# Testcase Example:  '[-10,-3,0,5,9]'
#
# Given a singly linked list where elements are sorted in ascending order,
# convert it to a height balanced BST.
# 
# For this problem, a height-balanced binary tree is defined as a binary tree
# in which the depth of the two subtrees of every node never differ by more
# than 1.
# 
# Example:
# 
# 
# Given the sorted linked list: [-10,-3,0,5,9],
# 
# One possible answer is: [0,-3,9,-10,null,5], which represents the following
# height balanced BST:
# 
# ⁠     0
# ⁠    / \
# ⁠  -3   9
# ⁠  /   /
# ⁠-10  5
# 
# 
#

# @lc code=start
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        return self.dfs(head, None)
    
    def dfs(self, head, tail):

        if head == tail:
            return None

        slow = fast = head
        while fast != tail and fast.next != tail:
            slow = slow.next
            fast = fast.next.next


        root = TreeNode(slow.val)

        root.left = self.dfs(head, slow)
        root.right = self.dfs(slow.next, tail)
        return root

    #     nums = []
    #     while head:
    #         nums.append(head.val)
    #         head = head.next
    #     return self.sortedArrayToBST(nums)

    # def sortedArrayToBST(self, nums):
    #     if not nums:
    #         return 

    #     mid = len(nums) // 2
    #     root = TreeNode(nums[mid])
    #     root.left = self.sortedArrayToBST(nums[:mid])
    #     root.right = self.sortedArrayToBST(nums[mid+1:])
    #     return root
    

    #     self.cur = head
    #     end = 0
    #     while head:
    #         end += 1
    #         head = head.next
    #     return self.helper(0, end)

    # def helper(self, start, end):
    #     if start == end:
    #         return 

    #     mid = (start + end) // 2 

    #     left = self.helper(start, end)   
        
    #     root = TreeNode(self.cur.val)
    #     root.left = left

    #     self.cur = self.cur.next
    #     right = self.helper(mid+1, end)
    #     root.right = right
    #     return root

# @lc code=end

