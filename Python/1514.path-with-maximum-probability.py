#
# @lc app=leetcode id=1514 lang=python3
#
# [1514] Path with Maximum Probability
#
# https://leetcode.com/problems/path-with-maximum-probability/description/
#
# algorithms
# Medium (54.77%)
# Likes:    3129
# Dislikes: 74
# Total Accepted:    145.2K
# Total Submissions: 262.4K
# Testcase Example:  '3\n[[0,1],[1,2],[0,2]]\n[0.5,0.5,0.2]\n0\n2'
#
# You are given an undirected weighted graph of n nodes (0-indexed),
# represented by an edge list where edges[i] = [a, b] is an undirected edge
# connecting the nodes a and b with a probability of success of traversing that
# edge succProb[i].
# 
# Given two nodes start and end, find the path with the maximum probability of
# success to go from start to end and return its success probability.
# 
# If there is no path from start to end, return 0. Your answer will be accepted
# if it differs from the correct answer by at most 1e-5.
# 
# 
# Example 1:
# 
# 
# 
# 
# Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start =
# 0, end = 2
# Output: 0.25000
# Explanation: There are two paths from start to end, one having a probability
# of success = 0.2 and the other has 0.5 * 0.5 = 0.25.
# 
# 
# Example 2:
# 
# 
# 
# 
# Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start =
# 0, end = 2
# Output: 0.30000
# 
# 
# Example 3:
# 
# 
# 
# 
# Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
# Output: 0.00000
# Explanation: There is no path between 0 and 2.
# 
# 
# 
# Constraints:
# 
# 
# 2 <= n <= 10^4
# 0 <= start, end < n
# start != end
# 0 <= a, b < n
# a != b
# 0 <= succProb.length == edges.length <= 2*10^4
# 0 <= succProb[i] <= 1
# There is at most one edge between every two nodes.
# 
# 
#

# @lc code=start
class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start_node: int, end_node: int) -> float:
        # Dijkstra
        adj = collections.defaultdict(list)
        for i, (u, v) in enumerate(edges):
            w = succProb[i]
            adj[u].append((v, w))
            adj[v].append((u, w))

        q = [(-1, start_node)]
        dists = {}
        while q:
            dist, node = heapq.heappop(q)
            if node not in dists:
                dists[node] = -dist
                for v, w in adj[node]:
                    heapq.heappush(q, (dist*w, v))
        return dists.get(end_node, 0)
    
        # Bellman-Ford
        dists = [0] * n
        dists[start_node] = 1
        for _ in range(n):
            changed = False
            for (u, v), w in zip(edges, succProb):
                if dists[u] * w > dists[v]:
                    dists[v] = dists[u]*w
                    changed = True
                if dists[v] * w > dists[u]:
                    dists[u] = dists[v] * w
                    changed = True
            if not changed:
                break
        return dists[end_node]

    
# @lc code=end

