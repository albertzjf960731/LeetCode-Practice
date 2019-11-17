#
# @lc app=leetcode id=142 lang=python
#
# [142] Linked List Cycle II
#
# https://leetcode.com/problems/linked-list-cycle-ii/description/
#
# algorithms
# Medium (33.99%)
# Likes:    1832
# Dislikes: 147
# Total Accepted:    251.4K
# Total Submissions: 738.1K
# Testcase Example:  '[3,2,0,-4]\n1'
#
# Given a linked list, return the node where the cycle begins. If there is no
# cycle, return null.
# 
# To represent a cycle in the given linked list, we use an integer pos which
# represents the position (0-indexed) in the linked list where tail connects
# to. If pos is -1, then there is no cycle in the linked list.
# 
# Note: Do not modify the linked list.
# 
# 
# 
# Example 1:
# 
# 
# Input: head = [3,2,0,-4], pos = 1
# Output: tail connects to node index 1
# Explanation: There is a cycle in the linked list, where tail connects to the
# second node.
# 
# 
# 
# 
# Example 2:
# 
# 
# Input: head = [1,2], pos = 0
# Output: tail connects to node index 0
# Explanation: There is a cycle in the linked list, where tail connects to the
# first node.
# 
# 
# 
# 
# Example 3:
# 
# 
# Input: head = [1], pos = -1
# Output: no cycle
# Explanation: There is no cycle in the linked list.
# 
# 
# 
# 
# 
# 
# Follow-up:
# Can you solve it without using extra space?
# 
#

# @lc code=start
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """

        # hash_set = set()
        # while head:
        #     hash_set.add(head)
        #     head = head.next  
        #     if head in hash_set:
        #         return head
        # return None

        # try:
        #     fast = head.next
        #     slow = head
        #     while fast is not slow:
        #         fast = fast.next.next
        #         slow = slow.next
        # except:
        #     # if there is an exception, we reach the end and there is no cycle
        #     return None

        # # since fast starts at head.next, we need to move slow one step forward
        # slow = slow.next
        # while head is not slow:
        #     head = head.next
        #     slow = slow.next

        # return head
        
        slow = fast = head
        while fast:
            if not fast.next:
                return None
            slow = slow.next
            fast = fast.next.next

            if fast == slow:
                meet = fast
                while head is not meet:
                    head = head.next
                    meet = meet.next
                return head
        return None


# @lc code=end

dummy = ListNode(0)
head = dummy
vals = [3,2,0,-4]
for val in vals:
    head.next = ListNode(val)
    head = head.next
dummy.next.next.next.next.next = dummy.next.next
sol  = Solution()
sol.detectCycle(dummy.next)
