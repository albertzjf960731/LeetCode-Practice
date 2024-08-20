#
# @lc app=leetcode id=1584 lang=python3
#
# [1584] Min Cost to Connect All Points
#
# https://leetcode.com/problems/min-cost-to-connect-all-points/description/
#
# algorithms
# Medium (67.18%)
# Likes:    5058
# Dislikes: 129
# Total Accepted:    304.6K
# Total Submissions: 452.7K
# Testcase Example:  '[[0,0],[2,2],[3,10],[5,2],[7,0]]'
#
# You are given an array points representing integer coordinates of some points
# on a 2D-plane, where points[i] = [xi, yi].
# 
# The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan
# distance between them: |xi - xj| + |yi - yj|, where |val| denotes the
# absolute value of val.
# 
# Return the minimum cost to make all points connected. All points are
# connected if there is exactly one simple path between any two points.
# 
# 
# Example 1:
# 
# 
# Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
# Output: 20
# Explanation: 
# 
# We can connect the points as shown above to get the minimum cost of 20.
# Notice that there is a unique path between every pair of points.
# 
# 
# Example 2:
# 
# 
# Input: points = [[3,12],[-2,5],[-4,1]]
# Output: 18
# 
# 
# 
# Constraints:
# 
# 
# 1 <= points.length <= 1000
# -10^6 <= xi, yi <= 10^6
# All pairs (xi, yi) are distinct.
# 
# 
#

# @lc code=start
class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        # Prim's algorithm
        n = len(points)
        edges = [[] for _ in range(n)]
        for i in range(n):
            for j in range(i+1, n):
                cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])
                edges[i].append((j, cost))
                edges[j].append((i, cost))

        pq = []
        for j, cost in edges[0]:
            heapq.heappush(pq, (cost, j))
        visited = set([0])
        ans = 0
        while len(visited) < n:
            cost, i = heapq.heappop(pq)
            if i in visited:
                continue
            visited.add(i)
            ans += cost
            for j, cost in edges[i]:
                if j not in visited:
                    heapq.heappush(pq, (cost, j))
        return ans
    
        # Kruskal's algorithm
        n = len(points)
        edges = []
        for i in range(n):
            for j in range(i+1, n):
                cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])
                edges.append((cost, i, j))
        edges.sort()

        roots = [i for i in range(n)]
        def findRoot(i):
            while roots[i] != i:
                roots[i] = roots[roots[i]]
                i = roots[i]
            return i
        
        ans = 0
        for cost, i, j in edges:
            p1 = findRoot(i)
            p2 = findRoot(j)
            if p1 != p2:
                ans += cost
                roots[p1] = p2
        return ans
# @lc code=end

