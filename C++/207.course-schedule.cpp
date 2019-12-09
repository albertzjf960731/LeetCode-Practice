/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (40.11%)
 * Likes:    2508
 * Dislikes: 126
 * Total Accepted:    292K
 * Total Submissions: 728K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 * 
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 * 
 * Example 1:
 * 
 * 
 * Input: 2, [[1,0]] 
 * Output: true
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0. So it is possible.
 * 
 * Example 2:
 * 
 * 
 * Input: 2, [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should
 * also have finished course 1. So it is impossible.
 * 
 * 
 * Note:
 * 
 * 
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 * 
 * 
 */
#include<vector>
#include<queue>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indeg(numCourses, 0);

        for(auto item: prerequisites) {            
            graph[item[1]].push_back(item[0]);
            indeg[item[0]] += 1;
        }

        queue<int> q;
        for (int vertex=0; vertex<numCourses; vertex++){
            if (indeg[vertex] == 0)
                q.push(vertex);
        }

        int count = 0;
        while (!q.empty()) {
            int vertex = q.front();
            q.pop();

            count++;
            for (int neigh: graph[vertex]) {
                indeg[neigh]--;
                if (indeg[neigh]==0)
                    q.push(neigh);
            }
        }
        return (count==numCourses);
    }
    //     vector<vector<int>> graph(numCourses);
    //     vector<int> visited(numCourses, 0);

    //     for(auto item: prerequisites) {            
    //         graph[item[1]].push_back(item[0]);
    //     }

    //     for (int vertex=0; vertex<numCourses; vertex++) {
    //         if (!DFS(vertex, graph, visited))
    //             return false;
    //     }
    //     return true;
    // }

    // bool DFS(int vertex, vector<vector<int>>& graph, vector<int>& visited) {
    //     if (visited[vertex]==-1)
    //         return false;
    //     if (visited[vertex]==1)
    //         return true;
    //     visited[vertex] = -1;
    //     for (int neigh:graph[vertex]) {
    //         if (!DFS(neigh, graph, visited))
    //             return false;
    //     }
    //     visited[vertex] = 1;
    //     return true; 
    // }
};
// @lc code=end

