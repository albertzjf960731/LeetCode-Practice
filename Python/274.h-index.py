#
# @lc app=leetcode id=274 lang=python
#
# [274] H-Index
#
# https://leetcode.com/problems/h-index/description/
#
# algorithms
# Medium (34.99%)
# Likes:    469
# Dislikes: 795
# Total Accepted:    134.8K
# Total Submissions: 385.2K
# Testcase Example:  '[3,0,6,1,5]'
#
# Given an array of citations (each citation is a non-negative integer) of a
# researcher, write a function to compute the researcher's h-index.
# 
# According to the definition of h-index on Wikipedia: "A scientist has index h
# if h of his/her N papers have at least h citations each, and the other N − h
# papers have no more than h citations each."
# 
# Example:
# 
# 
# Input: citations = [3,0,6,1,5]
# Output: 3 
# Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each
# of them had 
# ⁠            received 3, 0, 6, 1, 5 citations respectively. 
# Since the researcher has 3 papers with at least 3 citations each and the
# remaining 
# two with no more than 3 citations each, her h-index is 3.
# 
# Note: If there are several possible values for h, the maximum one is taken as
# the h-index.
# 
#

# @lc code=start
class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        # return sum(i < j for i, j in enumerate(sorted(citations, reverse=True)))

        # n = len(citations)
        # buckets = [0 for _ in range(n+1)]

        # for c in citations:
        #     if c >= n:
        #         buckets[n] += 1
        #     else:
        #         buckets[c] += 1
            
        # count = 0
        # for i in range(n, -1, -1):
        #     count += buckets[i]
        #     if count >= i:
        #         return i 
        # return 0


        # keep updating the priority queue so that it only contains numbers greater than the current H-index and remove the rest.

        from queue import PriorityQueue
        queue = PriorityQueue()
        
        for i in range(len(citations)):
            if citations[i] > queue.qsize():            
                queue.put(citations[i])

            while queue.queue[0] < queue.qsize():
                queue.get()

            print(queue.qsize())
	
# @lc code=end

sol = Solution()
citations = [1,3,3,2,2,15] # 1 1 2 2 2 3
# citations = [5,1,2] # 1, 1, 2
# citations = [1,1,3]
sol.hIndex(citations)