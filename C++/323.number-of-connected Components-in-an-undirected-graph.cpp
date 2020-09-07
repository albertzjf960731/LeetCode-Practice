/*
 * @lc app=leetcode id=323 lang=cpp
 *
 * [323] Number of Connected Components in an Undirected Graph
 *
 * Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.
 * 
 * Example 1:
 * 
 *     0          3
 *
 *     |          |
 * 
 *     1 --- 2    4
 * 
 * 
 * Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.
 * 
 * Example 2:
 * 
 *    0           4
 *
 *    |           |
 *
 *    1 --- 2 --- 3
 * 
 * Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.
 * 
 * Note:
 * 
 * You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    // int countComponents(int n, vector<pair<int, int> >& edges) {
    //     int ans = 0;
    //     vector<vector<int>> adj(n);
    //     for (auto edge: edges) {
    //         adj[edge.first].push_back(edge.second);
    //         adj[edge.second].push_back(edge.first);
    //     }

    //     vector<bool> visited;
    //     for (int i=0; i<n; ++i) {
    //         if (!visited[i]) {
    //             DFS(adj, visited, i);
    //             ans ++;
    //         }
    //     }
    //     return ans;
    // }
    // void DFS(vector<vector<int>>& adj, vector<bool>& visited, int i) {
    //     if (visited[i]) return;
    //     visited[i] = true;
    //     for (int j=0; j<adj[i].size(); ++j) {
    //         DFS(adj, visited, adj[i][j]);
    //     }
    // }
    int countComponents(int n, vector<pair<int, int> >& edges) {
        int ans = n;
        vector<int> root(n, -1);
        // for (int i=0; i<n; ++i) root[i] = i;
        for (auto edge: edges) {
            int p1 = findRoot(root, edge.first);
            int p2 = findRoot(root, edge.second);
            if (p1 != p2) {
                root[p1] =  p2;
                ans --;
            }
        }
        return ans;
    }
    int findRoot(vector<int>& root, int i) {
        // while (root[i] != i) i = root[i];
        while (root[i] != -1) i = root[i];
        return i;
    }
};
// @lc code=end

