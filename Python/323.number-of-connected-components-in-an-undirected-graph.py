#
# @lc app=leetcode id=323 lang=python3
#
# [323] Number of Connected Components in an Undirected Graph
#
# https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/description/
#
# algorithms
# Medium (62.85%)
# Likes:    2662
# Dislikes: 101
# Total Accepted:    408.5K
# Total Submissions: 648.5K
# Testcase Example:  '5\n[[0,1],[1,2],[3,4]]'
#
# You have a graph of n nodes. You are given an integer n and an array edges
# where edges[i] = [ai, bi] indicates that there is an edge between ai and bi
# in the graph.
# 
# Return the number of connected components in the graph.
# 
# 
# Example 1:
# 
# 
# Input: n = 5, edges = [[0,1],[1,2],[3,4]]
# Output: 2
# 
# 
# Example 2:
# 
# 
# Input: n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
# Output: 1
# 
# 
# 
# Constraints:
# 
# 
# 1 <= n <= 2000
# 1 <= edges.length <= 5000
# edges[i].length == 2
# 0 <= ai <= bi < n
# ai != bi
# There are no repeated edges.
# 
# 
#

# @lc code=start
class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        ans = n

        root = [i for i in range(n)]
        for e in edges:
            p1 = self.findRoot(root, e[0])
            p2 = self.findRoot(root, e[1])
            if p1 != p2:
                root[p1] = p2
                ans -= 1
        return ans
        
    
    def findRoot(self, root, i):
        while root[i] != i:
            root[i] = root[root[i]]
            i = root[i]
        return i
# @lc code=end

