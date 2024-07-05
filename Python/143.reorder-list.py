#
# @lc app=leetcode id=143 lang=python3
#
# [143] Reorder List
#
# https://leetcode.com/problems/reorder-list/description/
#
# algorithms
# Medium (58.87%)
# Likes:    11014
# Dislikes: 400
# Total Accepted:    1M
# Total Submissions: 1.7M
# Testcase Example:  '[1,2,3,4]'
#
# You are given the head of a singly linked-list. The list can be represented
# as:
# 
# 
# L0 → L1 → … → Ln - 1 → Ln
# 
# 
# Reorder the list to be on the following form:
# 
# 
# L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
# 
# 
# You may not modify the values in the list's nodes. Only nodes themselves may
# be changed.
# 
# 
# Example 1:
# 
# 
# Input: head = [1,2,3,4]
# Output: [1,4,2,3]
# 
# 
# Example 2:
# 
# 
# Input: head = [1,2,3,4,5]
# Output: [1,5,2,4,3]
# 
# 
# 
# Constraints:
# 
# 
# The number of nodes in the list is in the range [1, 5 * 10^4].
# 1 <= Node.val <= 1000
# 
# 
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        dummy = ListNode(-1)
        dummy.next = head
        slow, fast = dummy, dummy
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        head2 = slow.next
        slow.next = None

        cur2 = head2
        prev = None
        while cur2:
            nxt = cur2.next
            cur2.next = prev
            prev = cur2
            cur2 = nxt
        head2 = prev

        cur = dummy
        cur1, cur2 = head, head2
        while cur1 and cur2:
            cur.next = cur1
            cur = cur.next
            cur1 = cur1.next

            cur.next = cur2
            cur = cur.next
            cur2 = cur2.next
        cur.next = cur1 if cur1 else cur2


        # stack method
        stack = []
        cur = head
        while cur:
            stack.append(cur)
            cur = cur.next
        
        cnt = (len(stack) - 1) // 2
        cur = head
        for i in range(cnt):
            tmp = stack.pop()

            nxt = cur.next
            cur.next = tmp
            tmp.next = nxt
            cur = nxt
        stack[-1].next = None

# @lc code=end

