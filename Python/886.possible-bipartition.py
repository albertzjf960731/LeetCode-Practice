#
# @lc app=leetcode id=886 lang=python3
#
# [886] Possible Bipartition
#
# https://leetcode.com/problems/possible-bipartition/description/
#
# algorithms
# Medium (50.71%)
# Likes:    4669
# Dislikes: 111
# Total Accepted:    213.6K
# Total Submissions: 421.2K
# Testcase Example:  '4\n[[1,2],[1,3],[2,4]]'
#
# We want to split a group of n people (labeled from 1 to n) into two groups of
# any size. Each person may dislike some other people, and they should not go
# into the same group.
# 
# Given the integer n and the array dislikes where dislikes[i] = [ai, bi]
# indicates that the person labeled ai does not like the person labeled bi,
# return true if it is possible to split everyone into two groups in this
# way.
# 
# 
# Example 1:
# 
# 
# Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
# Output: true
# Explanation: The first group has [1,4], and the second group has [2,3].
# 
# 
# Example 2:
# 
# 
# Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
# Output: false
# Explanation: We need at least 3 groups to divide them. We cannot put them in
# two groups.
# 
# 
# 
# Constraints:
# 
# 
# 1 <= n <= 2000
# 0 <= dislikes.length <= 10^4
# dislikes[i].length == 2
# 1 <= ai < bi <= n
# All the pairs of dislikes are unique.
# 
# 
#

# @lc code=start
class Solution:
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        graph = [[] for _ in range(n)]
        for u, v in dislikes:
            graph[u-1].append(v-1)
            graph[v-1].append(u-1)
        
        colors = [0] * n
        queue = deque()
        for i in range(n):
            if colors[i] != 0:
                continue
            queue.append(i)
            colors[i] = 1
            
            while queue:
                node = queue.popleft()
                for nei in graph[node]:
                    if colors[nei] == colors[node]:
                        return False
                    if colors[nei] == 0:
                        colors[nei] = -colors[node]
                        queue.append(nei)
        return True
        
# @lc code=end

