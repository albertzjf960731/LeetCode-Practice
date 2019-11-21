#
# @lc app=leetcode id=725 lang=python
#
# [725] Split Linked List in Parts
#
# https://leetcode.com/problems/split-linked-list-in-parts/description/
#
# algorithms
# Medium (50.05%)
# Likes:    442
# Dislikes: 92
# Total Accepted:    34.7K
# Total Submissions: 69.3K
# Testcase Example:  '[1,2,3,4]\n5'
#
# Given a (singly) linked list with head node root, write a function to split
# the linked list into k consecutive linked list "parts".
# 
# The length of each part should be as equal as possible: no two parts should
# have a size differing by more than 1.  This may lead to some parts being
# null.
# 
# The parts should be in order of occurrence in the input list, and parts
# occurring earlier should always have a size greater than or equal parts
# occurring later.
# 
# Return a List of ListNode's representing the linked list parts that are
# formed.
# 
# 
# Examples
# 1->2->3->4, k = 5 // 5 equal parts
# [ [1], 
# [2],
# [3],
# [4],
# null ]
# 
# Example 1:
# 
# Input: 
# root = [1, 2, 3], k = 5
# Output: [[1],[2],[3],[],[]]
# Explanation:
# The input and each element of the output are ListNodes, not arrays.
# For example, the input root has root.val = 1, root.next.val = 2,
# \root.next.next.val = 3, and root.next.next.next = null.
# The first element output[0] has output[0].val = 1, output[0].next = null.
# The last element output[4] is null, but it's string representation as a
# ListNode is [].
# 
# 
# 
# Example 2:
# 
# Input: 
# root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
# Output: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]
# Explanation:
# The input has been split into consecutive parts with size difference at most
# 1, and earlier parts are a larger size than the later parts.
# 
# 
# 
# Note:
# The length of root will be in the range [0, 1000].
# Each value of a node in the input will be an integer in the range [0, 999].
# k will be an integer in the range [1, 50].
# 
#

# @lc code=start
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def splitListToParts(self, root, k):
        """
        :type root: ListNode
        :type k: int
        :rtype: List[ListNode]
        """
        cur = root
        n = 0
        while cur:
            n += 1
            cur = cur.next
        
        mod = n % k 
        size = n // k
        res = []
        cur = root

        for i in range(k):
            head = cur 

            cur_size = size + (mod>0)
            mod -= 1

            for j in range(cur_size-1):
                if cur:
                    cur = cur.next
            if cur:
                nex = cur.next
                cur.next = None
                cur = nex
            res.append(head)
        # for j in range(i, k):
        #     res.append([None])
        return res 



# @lc code=end

sol = Solution()
vals =[1,2,3,4,5,6,7]

head = ListNode(None)
cur = head
for val in vals:
    cur.next = ListNode(val)
    cur = cur.next

k = 3
print(sol.splitListToParts(head.next, k))