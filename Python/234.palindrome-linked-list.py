#
# @lc app=leetcode id=234 lang=python
#
# [234] Palindrome Linked List
#
# https://leetcode.com/problems/palindrome-linked-list/description/
#
# algorithms
# Easy (37.29%)
# Likes:    2101
# Dislikes: 298
# Total Accepted:    319.6K
# Total Submissions: 855.2K
# Testcase Example:  '[1,2]'
#
# Given a singly linked list, determine if it is a palindrome.
# 
# Example 1:
# 
# 
# Input: 1->2
# Output: false
# 
# Example 2:
# 
# 
# Input: 1->2->2->1
# Output: true
# 
# Follow up:
# Could you do it in O(n) time and O(1) space?
# 
#

# @lc code=start
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        # num = []
        # while head:
        #     num.append(head.val)
        #     head = head.next
        
        # return num == num[::-1]
        
        if not head or not head.next:
           return True

        slow = head
        fast = head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        # even
        if fast:
            slow = slow.next
        head1 = head
        while head.next != slow:
            head = head.next
        head.next = None

        head2 = self.reverseList(slow)
        while head1 and head2:
            if head1.val != head2.val:
                return False
            head1 = head1.next
            head2 = head2.next
        return True


    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        pre = ListNode(None)
        cur = head
        while cur:
            nex = cur.next
            cur.next = pre
            pre = cur 
            cur = nex
        return pre


# @lc code=end

sol = Solution()
vals = [1,2,2,1]
head = ListNode(None)
cur = head
for val in vals:
    cur.next = ListNode(val)
    cur = cur.next
print(sol.isPalindrome(head.next))