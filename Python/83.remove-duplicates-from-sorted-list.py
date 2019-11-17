#
# @lc app=leetcode id=83 lang=python
#
# [83] Remove Duplicates from Sorted List
#
# https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
#
# algorithms
# Easy (43.63%)
# Likes:    973
# Dislikes: 88
# Total Accepted:    378.7K
# Total Submissions: 867.2K
# Testcase Example:  '[1,1,2]'
#
# Given a sorted linked list, delete all duplicates such that each element
# appear only once.
# 
# Example 1:
# 
# 
# Input: 1->1->2
# Output: 1->2
# 
# 
# Example 2:
# 
# 
# Input: 1->1->2->3->3
# Output: 1->2->3
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
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # if not head:
        #     return head

        # cur = head
        # nex = cur.next
        # while cur and nex:
        #     while nex and nex.val == cur.val:
        #         nex = nex.next
        #     cur.next = nex

        #     if nex:
        #         cur = nex
        #         nex = cur.next
        # return head

        cur = head 
        while cur and cur.next:
            if cur.val == cur.next.val:
                cur.next = cur.next.next

            else:
                cur = cur.next
        return head
        
# @lc code=end

sol = Solution()
head = ListNode(0)
vals = [1,1,2,3,3]
cur = head
for val in vals:
    cur.next = ListNode(val)
    cur = cur.next

head = sol.deleteDuplicates(head.next)
while head:
    print(head.val)
    head = head.next