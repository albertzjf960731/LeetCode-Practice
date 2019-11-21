#
# @lc app=leetcode id=445 lang=python
#
# [445] Add Two Numbers II
#
# https://leetcode.com/problems/add-two-numbers-ii/description/
#
# algorithms
# Medium (51.74%)
# Likes:    946
# Dislikes: 125
# Total Accepted:    117.1K
# Total Submissions: 225.4K
# Testcase Example:  '[7,2,4,3]\n[5,6,4]'
#
# You are given two non-empty linked lists representing two non-negative
# integers. The most significant digit comes first and each of their nodes
# contain a single digit. Add the two numbers and return it as a linked list.
# 
# You may assume the two numbers do not contain any leading zero, except the
# number 0 itself.
# 
# Follow up:
# What if you cannot modify the input lists? In other words, reversing the
# lists is not allowed.
# 
# 
# 
# Example:
# 
# Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
# Output: 7 -> 8 -> 0 -> 7
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
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        num1 = num2 = ''

        while l1:
            num1 += str(l1.val)
            l1 = l1.next    
        while l2:
            num2 += str(l2.val)
            l2 = l2.next
        
        num3 = str(int(num1)+int(num2))
        
        dummy = ListNode(0) 
        cur = dummy
        for i in range(len(num3)):
            cur.next = ListNode(num3[i])
            cur = cur.next
        return dummy.next

        
# @lc code=end

