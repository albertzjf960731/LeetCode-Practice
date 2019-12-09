#
# @lc app=leetcode id=207 lang=python
#
# [207] Course Schedule
#
# https://leetcode.com/problems/course-schedule/description/
#
# algorithms
# Medium (39.76%)
# Likes:    2435
# Dislikes: 123
# Total Accepted:    284K
# Total Submissions: 711.4K
# Testcase Example:  '2\n[[1,0]]'
#
# There are a total of n courses you have to take, labeled from 0 to n-1.
# 
# Some courses may have prerequisites, for example to take course 0 you have to
# first take course 1, which is expressed as a pair: [0,1]
# 
# Given the total number of courses and a list of prerequisite pairs, is it
# possible for you to finish all courses?
# 
# Example 1:
# 
# 
# Input: 2, [[1,0]] 
# Output: true
# Explanation: There are a total of 2 courses to take. 
# To take course 1 you should have finished course 0. So it is possible.
# 
# Example 2:
# 
# 
# Input: 2, [[1,0],[0,1]]
# Output: false
# Explanation: There are a total of 2 courses to take. 
# To take course 1 you should have finished course 0, and to take course 0 you
# should
# also have finished course 1. So it is impossible.
# 
# 
# Note:
# 
# 
# The input prerequisites is a graph represented by a list of edges, not
# adjacency matrices. Read more about how a graph is represented.
# You may assume that there are no duplicate edges in the input prerequisites.
# 
# 
#

# @lc code=start
class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """

    #     graph = [[] for _ in range(numCourses)]
    #     visited = [0 for _ in range(numCourses)]

    #     for x, y in prerequisites:
    #         graph[x].append(y)
        
    #     for i in range(numCourses):
    #         if not self.dfs(i, graph, visited):
    #             return False
    #     return True
    
    # def dfs(self, vertex, graph, visited):
    #     # is being visited,
    #     if visited[vertex] == -1:
    #         return False
    #     # has been visited
    #     if visited[vertex] == 1:
    #         return True
    #     visited[vertex] = -1
    #     for neigh in graph[vertex]:
    #         if not self.dfs(neigh, graph, visited):
    #             return False
    #     visited[vertex] = 1
    #     return True

        graph = [[] for _ in range(numCourses)]
        indeg = [0 for _ in range(numCourses)]

        for x, y in prerequisites:
            graph[y].append(x)
            indeg[x] += 1
    
        queue = [vertex for vertex in range(numCourses) if not indeg[vertex]]
        
        # visiting =  set(queue) 
        # for vertex in queue:
        #     for neigh in graph[vertex]:
        #         if neigh in visiting: 
        #             return False
        #         indeg[neigh] -= 1
        #         if not indeg[neigh]:
        #             visiting.add(neigh)
        #             queue.append(neigh),
        # return len(visiting) == numCourses

        count = 0
        while queue:
            vertex = queue.popleft()
            count += 1
            for neigh in graph[vertex]:
                indeg[neigh] -= 1
                if indeg[neigh]==0:
                    queue.append(neigh)
        return count == numCourses

# @lc code=end

