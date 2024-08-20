#
# @lc app=leetcode id=1631 lang=python3
#
# [1631] Path With Minimum Effort
#
# https://leetcode.com/problems/path-with-minimum-effort/description/
#
# algorithms
# Medium (59.91%)
# Likes:    5908
# Dislikes: 204
# Total Accepted:    274.1K
# Total Submissions: 456.7K
# Testcase Example:  '[[1,2,2],[3,8,2],[5,3,5]]'
#
# You are a hiker preparing for an upcoming hike. You are given heights, a 2D
# array of size rows x columns, where heights[row][col] represents the height
# of cell (row, col). You are situated in the top-left cell, (0, 0), and you
# hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e.,
# 0-indexed). You can move up, down, left, or right, and you wish to find a
# route that requires the minimum effort.
# 
# A route's effort is the maximum absolute difference in heights between two
# consecutive cells of the route.
# 
# Return the minimum effort required to travel from the top-left cell to the
# bottom-right cell.
# 
# 
# Example 1:
# 
# 
# 
# 
# Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
# Output: 2
# Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2
# in consecutive cells.
# This is better than the route of [1,2,2,2,5], where the maximum absolute
# difference is 3.
# 
# 
# Example 2:
# 
# 
# 
# 
# Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
# Output: 1
# Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1
# in consecutive cells, which is better than route [1,3,5,3,5].
# 
# 
# Example 3:
# 
# 
# Input: heights =
# [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
# Output: 0
# Explanation: This route does not require any effort.
# 
# 
# 
# Constraints:
# 
# 
# rows == heights.length
# columns == heights[i].length
# 1 <= rows, columns <= 100
# 1 <= heights[i][j] <= 10^6
# 
# 
#

# @lc code=start
class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        m, n = len(heights), len(heights[0])

        pq = [(0, 0, 0)]
        efforts = [[float('inf')] * n for _ in range(m)]

        ans = 0
        while pq:
            e, i, j = heapq.heappop(pq)
            ans = max(ans, e)

            if i == m - 1 and j == n - 1:
                break

            for d in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
                x, y = i + d[0], j + d[1]
                if x < 0 or x >= m or y < 0 or y >= n:
                    continue
                
                diff = abs(heights[x][y] - heights[i][j])
                if diff < efforts[x][y]:
                    efforts[x][y] = diff
                    heapq.heappush(pq, (diff, x, y))

        return ans

        
# @lc code=end

