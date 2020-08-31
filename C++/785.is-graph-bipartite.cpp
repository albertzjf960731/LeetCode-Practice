/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 */

// @lc code=start
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colors(graph.size(), 0);
        
        
        for (int i=0; i<graph.size(); ++i) {
            if (colors[i] != 0) continue;
            colors[i] = 1;
            
            queue<int> q{{i}};
            while (!q.empty()) {
                int node = q.front(); 
                q.pop();
                for (auto nei : graph[node]) {
                    if (colors[nei]==colors[node]) 
                        return false;
                    if (colors[nei] == 0) {
                        colors[nei] = -1 * colors[node];
                        q.push(nei);
                    }
                }
            }
        }
        return true;   
    }
};
// @lc code=end

