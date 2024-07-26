#
# @lc app=leetcode id=684 lang=python3
#
# [684] Redundant Connection
#
# https://leetcode.com/problems/redundant-connection/description/
#
# algorithms
# Medium (62.91%)
# Likes:    6161
# Dislikes: 399
# Total Accepted:    369.8K
# Total Submissions: 585.9K
# Testcase Example:  '[[1,2],[1,3],[2,3]]'
#
# In this problem, a tree is an undirected graph that is connected and has no
# cycles.
# 
# You are given a graph that started as a tree with n nodes labeled from 1 to
# n, with one additional edge added. The added edge has two different vertices
# chosen from 1 to n, and was not an edge that already existed. The graph is
# represented as an array edges of length n where edges[i] = [ai, bi] indicates
# that there is an edge between nodes ai and bi in the graph.
# 
# Return an edge that can be removed so that the resulting graph is a tree of n
# nodes. If there are multiple answers, return the answer that occurs last in
# the input.
# 
# 
# Example 1:
# 
# 
# Input: edges = [[1,2],[1,3],[2,3]]
# Output: [2,3]
# 
# 
# Example 2:
# 
# 
# Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
# Output: [1,4]
# 
# 
# 
# Constraints:
# 
# 
# n == edges.length
# 3 <= n <= 1000
# edges[i].length == 2
# 1 <= ai < bi <= edges.length
# ai != bi
# There are no repeated edges.
# The given graph is connected.
# 
# 
#

# @lc code=start
class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        root = [i for i in range(len(edges)+1)]
        for e in edges:
            p1 = self.findRoot(root, e[0])
            p2 = self.findRoot(root, e[1])
            if p1 != p2:
                root[p1] = p2
            else:
                return e
        return [-1, -1]

    def findRoot(self, root, i):
        while root[i] != i:
            root[i] = root[root[i]]
            i = root[i]
        return i
# @lc code=end

