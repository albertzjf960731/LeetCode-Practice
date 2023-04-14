/*
 * @lc app=leetcode id=1857 lang=cpp
 *
 * [1857] Largest Color Value in a Directed Graph
 *
 * https://leetcode.com/problems/largest-color-value-in-a-directed-graph/description/
 *
 * algorithms
 * Hard (40.76%)
 * Likes:    1176
 * Dislikes: 41
 * Total Accepted:    29.9K
 * Total Submissions: 63.5K
 * Testcase Example:  '"abaca"\n[[0,1],[0,2],[2,3],[3,4]]'
 *
 * There is a directed graph of n colored nodes and m edges. The nodes are
 * numbered from 0 to n - 1.
 * 
 * You are given a string colors where colors[i] is a lowercase English letter
 * representing the color of the i^th node in this graph (0-indexed). You are
 * also given a 2D array edges where edges[j] = [aj, bj] indicates that there
 * is a directed edge from node aj to node bj.
 * 
 * A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk
 * such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The
 * color value of the path is the number of nodes that are colored the most
 * frequently occurring color along that path.
 * 
 * Return the largest color value of any valid path in the given graph, or -1
 * if the graph contains a cycle.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
 * Output: 3
 * Explanation: The path 0 -> 2 -> 3 -> 4 contains 3 nodes that are colored "a"
 * (red in the above image).
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: colors = "a", edges = [[0,0]]
 * Output: -1
 * Explanation: There is a cycle from 0 to 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == colors.length
 * m == edges.length
 * 1 <= n <= 10^5
 * 0 <= m <= 10^5
 * colors consists of lowercase English letters.
 * 0 <= aj, bj < n
 * 
 */

// @lc code=start
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();

        vector<vector<int>> graph(n);
        vector<int> indeg(n, 0);
        for (auto& e: edges) {
            graph[e[0]].push_back(e[1]);
            indeg[e[1]] += 1;
        }

        queue<int> q;
        for (int i=0; i<n; ++i) {
            if (indeg[i] == 0) q.push(i);
        }
        
        int ans = 0, visited = 0;
        vector<vector<int>> cnts(n, vector<int>(26, 0));
        while (!q.empty()) {

            int cur = q.front(); q.pop();
            visited += 1;

            cnts[cur][colors[cur]-'a'] += 1;
            ans = max(ans, cnts[cur][colors[cur]-'a']);

            for (int nei: graph[cur]) {
                for (int i=0; i<26; ++i) {
                    cnts[nei][i] = max(cnts[nei][i], cnts[cur][i]);
                }

                indeg[nei] -= 1;
                if (indeg[nei] == 0) q.push(nei);
            }
        }
        return visited==n ? ans : -1;
    }
};
// @lc code=end

