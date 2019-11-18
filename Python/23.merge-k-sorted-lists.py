#
# @lc app=leetcode id=23 lang=python
#
# [23] Merge k Sorted Lists
#
# https://leetcode.com/problems/merge-k-sorted-lists/description/
#
# algorithms
# Hard (36.73%)
# Likes:    3150
# Dislikes: 207
# Total Accepted:    480.9K
# Total Submissions: 1.3M
# Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
#
# Merge k sorted linked lists and return it as one sorted list. Analyze and
# describe its complexity.
# 
# Example:
# 
# 
# Input:
# [
# 1->4->5,
# 1->3->4,
# 2->6
# ]
# Output: 1->1->2->3->4->4->5->6
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
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        # if len(lists) == 0:
        #     return None
        # if len(lists) == 1:
        #     return lists[0] 
        
        # l_merged = self.merge2Lists(lists[0], lists[1])
        # for i in range(2, len(lists)):
        #     l_merged = self.merge2Lists(l_merged, lists[i])

        # return l_merged

    #     if len(lists) == 0:
    #         return None
    #     interval = 1    
    #     while interval < len(lists):
    #         for i in range(0, len(lists)-interval, interval*2):
    #             lists[i] = self.merge2Lists(lists[i], lists[i+interval])
    #         interval *= 2
    #     return lists[0]

    # def merge2Lists(self, l1, l2):
    #     dummy = cur = ListNode(0)

    #     while l1 and l2: 
    #         if l1.val < l2.val:
    #             cur.next = l1 
    #             l1 = l1.next
    #         else:
    #             cur.next = l2 
    #             l2 = l2.next 
    #         cur = cur.next 
    #     cur.next = l1 or l2 
    #     return dummy.next

        # ln = []
        # for l in lists:
        #     while l:
        #         ln.append(l.val)
        #         l = l.next
        
        # ln.sort()

        # head = ListNode(0)
        # cur = head
        # for n in ln:
        #     cur.next = ListNode(n)
        #     cur = cur.next  
        # return head.next


        from heapq import heappush, heappop, heapreplace, heapify

        dummy = cur = ListNode(0)

        min_heap = [(node.val, node) for node in lists if node]
        heapify(min_heap)

        while min_heap:
            val, node = heappop(min_heap)
            if node.next:
                heappush(min_heap, (node.next.val, node.next))
            cur.next = node 
            cur = cur.next
        return dummy.next

# @lc code=end

