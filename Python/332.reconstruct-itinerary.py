#
# @lc app=leetcode id=332 lang=python3
#
# [332] Reconstruct Itinerary
#
# https://leetcode.com/problems/reconstruct-itinerary/description/
#
# algorithms
# Hard (43.27%)
# Likes:    5901
# Dislikes: 1873
# Total Accepted:    442.6K
# Total Submissions: 1M
# Testcase Example:  '[["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]'
#
# You are given a list of airline tickets where tickets[i] = [fromi, toi]
# represent the departure and the arrival airports of one flight. Reconstruct
# the itinerary in order and return it.
# 
# All of the tickets belong to a man who departs from "JFK", thus, the
# itinerary must begin with "JFK". If there are multiple valid itineraries, you
# should return the itinerary that has the smallest lexical order when read as
# a single string.
# 
# 
# For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than
# ["JFK", "LGB"].
# 
# 
# You may assume all tickets form at least one valid itinerary. You must use
# all the tickets once and only once.
# 
# 
# Example 1:
# 
# 
# Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
# Output: ["JFK","MUC","LHR","SFO","SJC"]
# 
# 
# Example 2:
# 
# 
# Input: tickets =
# [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
# Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
# Explanation: Another possible reconstruction is
# ["JFK","SFO","ATL","JFK","ATL","SFO"] but it is larger in lexical order.
# 
# 
# 
# Constraints:
# 
# 
# 1 <= tickets.length <= 300
# tickets[i].length == 2
# fromi.length == 3
# toi.length == 3
# fromi and toi consist of uppercase English letters.
# fromi != toi
# 
# 
#

# @lc code=start
class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        # 1. Construct the graph
        graph = collections.defaultdict(list)
        for u, v in tickets:
            graph[u].append(v)        
        for u in graph:
            graph[u].sort(reverse=True)
        
        # 2. DFS with stack
        ans = []
        stack = ["JFK"]
        while stack:
            cur = stack[-1]
            while graph[cur]:
                cur = graph[cur].pop()
                stack.append(cur)
            ans.append(stack.pop())
        return ans[::-1]
# @lc code=end

