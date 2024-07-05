#
# @lc app=leetcode id=261 lang=python3
#
# [261] Graph Valid Tree
#
# https://leetcode.com/problems/graph-valid-tree/description/
#
# algorithms
# Medium (48.16%)
# Likes:    3266
# Dislikes: 103
# Total Accepted:    409K
# Total Submissions: 846.9K
# Testcase Example:  '5\n[[0,1],[0,2],[0,3],[1,4]]'
#
# You have a graph of n nodes labeled from 0 to n - 1. You are given an integer
# n and a list of edges where edges[i] = [ai, bi] indicates that there is an
# undirected edge between nodes ai and bi in the graph.
# 
# Return true if the edges of the given graph make up a valid tree, and false
# otherwise.
# 
# 
# Example 1:
# 
# 
# Input: n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]
# Output: true
# 
# 
# Example 2:
# 
# 
# Input: n = 5, edges = [[0,1],[1,2],[2,3],[1,3],[1,4]]
# Output: false
# 
# 
# 
# Constraints:
# 
# 
# 1 <= n <= 2000
# 0 <= edges.length <= 5000
# edges[i].length == 2
# 0 <= ai, bi < n
# ai != bi
# There are no self-loops or repeated edges.
# 
# 
#

# @lc code=start
class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        root = [i for i in range(n)]
        for e in edges:
            p1 = self.findRoot(root, e[0])
            p2 = self.findRoot(root, e[1])
            if p1 == p2:
                return False
            root[p1] = p2
        return len(edges) == n-1
    
    def findRoot(self, root, i):
        while root[i] != i:
            root[i] = root[root[i]]
            i = root[i]
        return i
# @lc code=end

