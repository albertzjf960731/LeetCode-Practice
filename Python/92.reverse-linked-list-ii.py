#
# @lc app=leetcode id=92 lang=python
#
# [92] Reverse Linked List II
#
# https://leetcode.com/problems/reverse-linked-list-ii/description/
#
# algorithms
# Medium (36.41%)
# Likes:    1560
# Dislikes: 108
# Total Accepted:    223.9K
# Total Submissions: 613.9K
# Testcase Example:  '[1,2,3,4,5]\n2\n4'
#
# Reverse a linked list from position m to n. Do it in one-pass.
# 
# Note: 1 ≤ m ≤ n ≤ length of list.
# 
# Example:
# 
# 
# Input: 1->2->3->4->5->NULL, m = 2, n = 4
# Output: 1->4->3->2->5->NULL
# 
# 
#

# @lc code=start
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        # if m == n:
        #     return head

        # dummy = ListNode(0)
        # dummy.next = head

        # count = 0
        # l1 = ListNode(None)
        # l2 = ListNode(None)
        # pre = dummy

        # while head:
        #     count += 1
        #     if count == m:
        #         l1 = pre 
        #         l2 = head 
        #     if count > m and count < n:
        #         temp = head.next
        #         head.next = pre
        #         pre = head
        #         head = temp
        #         continue
        #     if count == n:
        #         l2.next = head.next
        #         head.next = pre
        #         l1.next = head
        #         break

        #     head = head.next
        #     pre = pre.next
        # return dummy.next

        if m == n:
            return head
        dummy = ListNode(0)
        dummy.next = head
        pre = dummy

        for _ in range(m-1):
            pre = pre.next
        
        reverse = None
        cur = pre.next
        for i in range(n-m+1):
            nex = cur.next
            cur.next = reverse
            reverse = cur
            cur = nex
        pre.next.next = cur 
        pre.next = reverse

        return dummy.next

# @lc code=end

