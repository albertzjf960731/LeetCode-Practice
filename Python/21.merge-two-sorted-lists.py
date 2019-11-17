#
# @lc app=leetcode id=21 lang=python
#
# [21] Merge Two Sorted Lists
#
# https://leetcode.com/problems/merge-two-sorted-lists/description/
#
# algorithms
# Easy (49.58%)
# Likes:    2806
# Dislikes: 409
# Total Accepted:    725.6K
# Total Submissions: 1.5M
# Testcase Example:  '[1,2,4]\n[1,3,4]'
#
# Merge two sorted linked lists and return it as a new list. The new list
# should be made by splicing together the nodes of the first two lists.
# 
# Example:
# 
# Input: 1->2->4, 1->3->4
# Output: 1->1->2->3->4->4
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
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        # index1, index2 = 0, 0 
        # l3 = []

        # while index1 < len(l1) and index2 < len(l2):
        #     if l1[index1] <= l2[index2]:
        #         l3.append(l1[index1])
        #         index1 += 1
        #     else:
        #         l3.append(l2[index2])
        #         index2 += 1
        # if index1 == len(l1):
        #     l3.extend(l2[index2:])
        # else:
        #     l3.extend(l1[index1:])
        # return l3

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

        # recursively 
        # if not l1 or not l2:
        #     return l1 or l2 
        
        # if l1.val < l2.val:
        #     l1.next = self.mergeTwoLists(l1.next, l2)
        #     return l1 
        # else:
        #     l2.next = self.mergeTwoLists(l1, l2.next)
        #     return l2
        
# @lc code=end
