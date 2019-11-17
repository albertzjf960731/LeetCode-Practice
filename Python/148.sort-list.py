#
# @lc app=leetcode id=148 lang=python
#
# [148] Sort List
#
# https://leetcode.com/problems/sort-list/description/
#
# algorithms
# Medium (37.91%)
# Likes:    1836
# Dislikes: 95
# Total Accepted:    214K
# Total Submissions: 564.2K
# Testcase Example:  '[4,2,1,3]'
#
# Sort a linked list in O(n log n) time using constant space complexity.
# 
# Example 1:
# 
# 
# Input: 4->2->1->3
# Output: 1->2->3->4
# 
# 
# Example 2:
# 
# 
# Input: -1->5->3->4->0
# Output: -1->0->3->4->5
# 
#

# @lc code=start
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        return self.merge_sort(head)
    
    def merge_sort(self, head):
        if not head or not head.next:
            return head
        
        dummy = ListNode(0)
        dummy.next = head
        slow, fast = dummy, dummy

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        head2 = slow.next
        slow.next = None

        head = self.merge_sort(head)
        head2 = self.merge_sort(head2)

        return self.merge(head, head2)
    
    def merge(self, l1, l2):
        dummy = cur = ListNode(0)

        while l1 and l2: 
            if l1.val < l2.val:
                cur.next = l1 
                l1 = l1.next
            else:
                cur.next = l2 
                l2 = l2.next 
            cur = cur.next 
        cur.next = l1 or l2 
        return dummy.next
        
        
# @lc code=end

sol = Solution()
head = ListNode(0)
cur = head

for val in [4,2,1,3]:
    cur.next = ListNode(val)
    cur = cur.next

sol.sortList(head.next)


