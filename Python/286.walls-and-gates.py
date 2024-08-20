#
# @lc app=leetcode id=286 lang=python3
#
# [286] Walls and Gates
#
# https://leetcode.com/problems/walls-and-gates/description/
#
# algorithms
# Medium (61.67%)
# Likes:    3132
# Dislikes: 65
# Total Accepted:    327.5K
# Total Submissions: 531K
# Testcase Example:  '[[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]'
#
# You are given an m x n grid rooms initialized with these three possible
# values.
# 
# 
# -1 A wall or an obstacle.
# 0 A gate.
# INF Infinity means an empty room. We use the value 2^31 - 1 = 2147483647 to
# represent INF as you may assume that the distance to a gate is less than
# 2147483647.
# 
# 
# Fill each empty room with the distance to its nearest gate. If it is
# impossible to reach a gate, it should be filled with INF.
# 
# 
# Example 1:
# 
# 
# Input: rooms =
# [[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
# Output: [[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]]
# 
# 
# Example 2:
# 
# 
# Input: rooms = [[-1]]
# Output: [[-1]]
# 
# 
# 
# Constraints:
# 
# 
# m == rooms.length
# n == rooms[i].length
# 1 <= m, n <= 250
# rooms[i][j] is -1, 0, or 2^31 - 1.
# 
# 
#

# @lc code=start
class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        """
        Do not return anything, modify rooms in-place instead.
        """
        if not rooms:
            return
        m, n = len(rooms), len(rooms[0])
        queue = deque()
        for i in range(m):
            for j in range(n):
                if rooms[i][j] == 0:
                    queue.append((i, j))
        while queue:
            i, j = queue.popleft()
            for d in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                x, y = i + d[0], j + d[1]
                if x < 0 or x >= m or y < 0 or y >= n:
                    continue
                if rooms[x][y] == 2147483647:
                    rooms[x][y] = rooms[i][j] + 1
                    queue.append((x, y))

        
# @lc code=end

