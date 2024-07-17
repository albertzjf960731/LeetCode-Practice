#
# @lc app=leetcode id=743 lang=python
#
# [743] Network Delay Time
#
# https://leetcode.com/problems/network-delay-time/description/
#
# algorithms
# Medium (44.95%)
# Likes:    938
# Dislikes: 194
# Total Accepted:    60.6K
# Total Submissions: 134.7K
# Testcase Example:  '[[2,1,1],[2,3,1],[3,4,1]]\n4\n2'
#
# There are N network nodes, labelled 1 to N.
# 
# Given times, a list of travel times as directed edges times[i] = (u, v, w),
# where u is the source node, v is the target node, and w is the time it takes
# for a signal to travel from source to target.
# 
# Now, we send a signal from a certain node K. How long will it take for all
# nodes to receive the signal? If it is impossible, return -1.
# 
# 
# 
# Example 1:
# 
# 
# 
# 
# Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
# Output: 2
# 
# 
# 
# 
# Note:
# 
# 
# N will be in the range [1, 100].
# K will be in the range [1, N].
# The length of times will be in the range [1, 6000].
# All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 0 <= w <= 100.
# 
# 
#
import collections
import heapq

# @lc code=start
class Solution(object):
    def networkDelayTime(self, times, N, K):
        """
        :type times: List[List[int]]
        :type N: int
        :type K: int
        :rtype: int
        """
        # # Dijkstra with heap
        # adj = collections.defaultdict(list)
        # for u, v, w in times:
        #     adj[u].append((v, w))

        # q = [(0, K)]
        # dists = {}
        # while q:
        #     dist, node = heapq.heappop(q)
            
        #     if node not in dists:
        #         dists[node] = dist
        #         for v, w in adj[node]:
        #             heapq.heappush(q, (dist+w, v))
        # return max(dists.values()) if len(dists)==N else -1 

        adj = collections.defaultdict(list)
        for u, v, w in times:
            adj[u].append((v, w))
        
        q = collections.deque([(0, K)])
        dists = [0] + [float('inf')] * N
        while q:
            dist, node = q.popleft()
            if dist < dists[node]:
                dists[node] = dist
                for v, w in adj[node]:
                    q.append((dist+w, v))
        ans = max(dists)
        return ans if ans < float('inf') else -1 
    
        # Bellman-Ford
        dists = [0] + [float('inf')] * n
        dists[k] = 0
        for _ in range(n):
            for u, v, w in times:
                if dists[u] + w < dists[v]:
                    dists[v] = dists[u] + w
        ans = max(dists)
        return ans if ans < float('inf') else -1
# @lc code=end

sol = Solution()
times = [[2,1,1],[2,3,1],[3,4,1]]
N = 4
K = 2
sol.networkDelayTime(times, N, K)
