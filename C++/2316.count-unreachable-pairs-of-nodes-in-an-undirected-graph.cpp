/*
 * @lc app=leetcode id=2316 lang=cpp
 *
 * [2316] Count Unreachable Pairs of Nodes in an Undirected Graph
 *
 * https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/
 *
 * algorithms
 * Medium (38.83%)
 * Likes:    818
 * Dislikes: 23
 * Total Accepted:    30.3K
 * Total Submissions: 70.4K
 * Testcase Example:  '3\n[[0,1],[0,2],[1,2]]'
 *
 * You are given an integer n. There is an undirected graph with n nodes,
 * numbered from 0 to n - 1. You are given a 2D integer array edges where
 * edges[i] = [ai, bi] denotes that there exists an undirected edge connecting
 * nodes ai and bi.
 * 
 * Return the number of pairs of different nodes that are unreachable from each
 * other.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3, edges = [[0,1],[0,2],[1,2]]
 * Output: 0
 * Explanation: There are no pairs of nodes that are unreachable from each
 * other. Therefore, we return 0.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
 * Output: 14
 * Explanation: There are 14 pairs of nodes that are unreachable from each
 * other:
 * 
 * [[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]].
 * Therefore, we return 14.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^5
 * 0 <= edges.length <= 2 * 10^5
 * edges[i].length == 2
 * 0 <= ai, bi < n
 * ai != bi
 * There are no repeated edges.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
    long long countPairs(int n, vector<vector<int>>& edges) {        
        vector<vector<int>> graph(n);
        for (vector<int>& e: edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n, false);
        long long ans = (long long)n * (n-1) / 2;

        for (int i=0; i<n; ++i) {
            if (!visited[i]) {
                long long cnt = 0;
                DFS(graph, visited, i, cnt);
                ans -= cnt * (cnt - 1) / 2;
            }
        }
        return ans;
    }

    void DFS(vector<vector<int>>& graph, vector<bool>& visited, int cur, long long& cnt) {
        cnt += 1;
        visited[cur] = true;
        for (int nei: graph[cur]) {
            if (visited[nei]) continue;
            DFS(graph, visited, nei, cnt);
        }
    }

};
// @lc code=end

