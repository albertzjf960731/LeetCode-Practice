#
# @lc app=leetcode id=378 lang=python3
#
# [378] Kth Smallest Element in a Sorted Matrix
#
# https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
#
# algorithms
# Medium (51.17%)
# Likes:    1585
# Dislikes: 96
# Total Accepted:    138.3K
# Total Submissions: 269.5K
# Testcase Example:  '[[1,5,9],[10,11,13],[12,13,15]]\n8'
#
# Given a n x n matrix where each of the rows and columns are sorted in
# ascending order, find the kth smallest element in the matrix.
# 
# 
# Note that it is the kth smallest element in the sorted order, not the kth
# distinct element.
# 
# 
# Example:
# 
# matrix = [
# ⁠  [ 1,  5,  9],
# ⁠  [10, 11, 13],
# ⁠  [12, 13, 15]
# ],
# k = 8,
# 
# return 13.
# 
# 
# 
# Note: 
# You may assume k is always valid, 1 ≤ k ≤ n^2.
#

# @lc code=start
# from heapq import * 

class Solution(object):

    def kthSmallest(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """

        # min_heap = []
        # for i in range(min(k, len(matrix))):
        #     heappush(min_heap, (matrix[i][0], 0, matrix[i]))

        # count = 0
        # while min_heap:
        #     num, col, row_num = heappop(min_heap)
        #     count += 1
        #     if count == k:
        #         break   
        #     if col < len(row_num)-1:
        #         heappush(min_heap, (row_num[col+1], col+1, row_num))
            
        # return num

        # TypeError: '<' not supported between instances of 'int' and 'tuple'

        # from queue import PriorityQueue
        # queue = PriorityQueue()

        # for i in range(min(k, len(matrix))):
        #     queue.put((matrix[i][0], 0, matrix[i]))
        # count = 0
        # while queue:
        #     num, col, row_num = queue.get()
        #     count += 1
        #     if count == k:
        #         break
        #     if col < len(row_num) -1:
        #         queue.put(row_num[col+1], col+1, row_num)

        # return num

        rows, cols = len(matrix), len(matrix[0])
        left, right = matrix[0][0], matrix[rows-1][cols-1]

        while left <= right:
            mid = (right+left) // 2
            count = 0
            for i in range(rows):    
                for j in range(cols):
                    if matrix[i][j] <= mid:
                        count += 1
                    else:
                        break
            # 最后 left==right
            #  the number lo found by binary search find is exactly the element which has k number of elements in the matrix that are <= lo
            if count < k:
                left = mid + 1
            else:
                right = mid - 1
        return left



# @lc code=end
sol = Solution()
matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
]
# matrix = [[1,2],[1,3]]

print(sol.kthSmallest(matrix, k=2))