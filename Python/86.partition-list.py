#
# @lc app=leetcode id=86 lang=python
#
# [86] Partition List
#
# https://leetcode.com/problems/partition-list/description/
#
# algorithms
# Medium (38.83%)
# Likes:    867
# Dislikes: 228
# Total Accepted:    184K
# Total Submissions: 473.3K
# Testcase Example:  '[1,4,3,2,5,2]\n3'
#
# Given a linked list and a value x, partition it such that all nodes less than
# x come before nodes greater than or equal to x.
# 
# You should preserve the original relative order of the nodes in each of the
# two partitions.
# 
# Example:
# 
# 
# Input: head = 1->4->3->2->5->2, x = 3
# Output: 1->2->2->4->3->5
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
    def partition(self, head, target):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        # dummy = ListNode(0)
        # dummy.next = head 
        
        # tail = ListNode(None)

        # head = dummy
        # while head.next:
        #     if head.next.val >= target:
        #         tail = head
        #         head = head.next
        #         break
        #     else:
        #         head = head.next
        
        # while head.next:
        #     if head.next.val < target:
        #         move = head.next
        #         head.next = move.next
                
        #         move.next = tail.next
        #         tail.next = move
        #         tail = move
        #     else:
        #         head = head.next
        
        # return dummy.next
        
        h1 = l1 = ListNode(0)
        h2 = l2 = ListNode(0)
        while head:
            if head.val < target:
                l1.next = head
                l1 = l1.next
            else:
                l2.next = head
                l2 = l2.next
            head = head.next
        l2.next = None
        l1.next = h2.next

        return h1.next


# @lc code=end


sol = Solution()
vals = [1,4,3,2,5,2]
cur = head = ListNode(0)

for val in vals:
    cur.next = ListNode(val)
    cur = cur.next
sol.partition(head.next, target=3)