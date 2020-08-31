/*
 * @lc app=leetcode id=886 lang=cpp
 *
 * [886] Possible Bipartition
 */

// @lc code=start
class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(N + 1);
        for (auto dislike : dislikes) {
            graph[dislike[0]].push_back(dislike[1]);
            graph[dislike[1]].push_back(dislike[0]);
        }
        
        vector<int> colors(N + 1);
        for (int i=1; i<=N; ++i) {
            if (colors[i] != 0) continue;
            colors[i] = 1;
            queue<int> q{{i}};
            
            while (!q.empty()) {
                int node = q.front(); 
                q.pop();
                for (int nei : graph[node]) {
                    if (colors[nei] == colors[node]) 
                        return false;
                    if (colors[nei] == 0) {
                        colors[nei] = -colors[node];
                        q.push(nei);
                    }
                }
            }
        }
        return true;
   
    }
};
// @lc code=end

