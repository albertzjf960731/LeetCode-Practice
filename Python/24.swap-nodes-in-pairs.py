#
# @lc app=leetcode id=24 lang=python
#
# [24] Swap Nodes in Pairs
#
# https://leetcode.com/problems/swap-nodes-in-pairs/description/
#
# algorithms
# Medium (46.87%)
# Likes:    1484
# Dislikes: 136
# Total Accepted:    371.1K
# Total Submissions: 790.7K
# Testcase Example:  '[1,2,3,4]'
#
# Given a linked list, swap every two adjacent nodes and return its head.
# 
# You may not modify the values in the list's nodes, only nodes itself may be
# changed.
# 
# 
# 
# Example:
# 
# 
# Given 1->2->3->4, you should return the list as 2->1->4->3.
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
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # if not head or not head.next:
        #     return head

        # first, second = head, head.next.next
        # head = first.next

        # while True:
        #     first.next.next = first
        #     first.next = second

        #     if not second or not second.next:
        #         break
        #     else:
        #         first.next = second.next

        #         first = second
        #         second = second.next.next


        # return head

        dummy = ListNode(0)
        dummy.next = head
        point = dummy

        while point.next and point.next.next:
            first = point.next
            second = point.next.next

            point.next = second
            first.next = second.next
            second.next = first

            point = first
        return dummy.next
# @lc code=end

sol = Solution()
dummy = ListNode(0)
cur = dummy
for val in [1,2,3]:
    cur.next = ListNode(val)
    cur = cur.next

head = sol.swapPairs(dummy.next)
cur = head
while cur:
    print(cur.val)
    cur = cur.next
