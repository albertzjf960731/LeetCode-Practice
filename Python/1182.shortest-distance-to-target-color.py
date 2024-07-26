#
# @lc app=leetcode id=1182 lang=python3
#
# [1182] Shortest Distance to Target Color
#
# https://leetcode.com/problems/shortest-distance-to-target-color/description/
#
# algorithms
# Medium (55.41%)
# Likes:    515
# Dislikes: 22
# Total Accepted:    35.9K
# Total Submissions: 64.8K
# Testcase Example:  '[1,1,2,1,3,2,2,3,3]\n[[1,3],[2,2],[6,1]]'
#
# You are given an array colors, in which there are three colors: 1, 2 and 3.
# 
# You are also given some queries. Each query consists of two integers i and c,
# return the shortest distance between the given index i and the target color
# c. If there is no solution return -1.
# 
# 
# Example 1:
# 
# 
# Input: colors = [1,1,2,1,3,2,2,3,3], queries = [[1,3],[2,2],[6,1]]
# Output: [3,0,3]
# Explanation: 
# The nearest 3 from index 1 is at index 4 (3 steps away).
# The nearest 2 from index 2 is at index 2 itself (0 steps away).
# The nearest 1 from index 6 is at index 3 (3 steps away).
# 
# 
# Example 2:
# 
# 
# Input: colors = [1,2], queries = [[0,3]]
# Output: [-1]
# Explanation: There is no 3 in the array.
# 
# 
# 
# Constraints:
# 
# 
# 1 <= colors.length <= 5*10^4
# 1 <= colors[i] <= 3
# 1 <= queries.length <= 5*10^4
# queries[i].length == 2
# 0 <= queries[i][0] < colors.length
# 1 <= queries[i][1] <= 3
# 
# 
#

# @lc code=start
class Solution:
    def shortestDistanceColor(self, colors: List[int], queries: List[List[int]]) -> List[int]:
        n = len(colors)
        dp = [[float('inf') for _ in range(4)] for _ in range(len(colors))]

        dp[0][colors[0]] = 0
        for i in range(1, n):
            dp[i][colors[i]] = 0
            dp[i][1] = min(dp[i][1], dp[i-1][1] + 1)
            dp[i][2] = min(dp[i][2], dp[i-1][2] + 1)
            dp[i][3] = min(dp[i][3], dp[i-1][3] + 1)
        dp[n-1][colors[n-1]] = 0
        for i in range(n-2, -1, -1):
            dp[i][colors[i]] = 0
            dp[i][1] = min(dp[i][1], dp[i+1][1] + 1)
            dp[i][2] = min(dp[i][2], dp[i+1][2] + 1)
            dp[i][3] = min(dp[i][3], dp[i+1][3] + 1)
        
        ans = []
        for i, c in queries:
            ans.append(dp[i][c] if dp[i][c] != float('inf') else -1)
        return ans
# @lc code=end

