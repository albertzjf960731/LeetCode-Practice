/*
 * @lc app=leetcode id=1293 lang=cpp
 *
 * [1293] Shortest Path in a Grid with Obstacles Elimination
 */

// @lc code=start
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dirs{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        vector<vector<int>> visited(n, vector<int>(m, -1)); 
        visited[0][0] = k;
        
        // vector<vector<bool>> visited(n, vector<bool>(m, false));
        // visited[0][0] = true;
        
        queue<vector<int>> q;
        q.push({0, 0, k});
        
        int ans = 0;
        while (!q.empty()) {
            int q_size = q.size();
            while (q_size --) {
                auto cur = q.front(); q.pop();
                
                if (cur[0] == n-1 && cur[1] == m-1) return ans;
                for (vector<int>& d : dirs) {
                    int x = cur[0] + d[0], y = cur[1] + d[1];
                    if (x < 0 || x >= n || y < 0 || y >= m) continue;
                    
                    int k2 = cur[2] - grid[x][y];
                    // if (k2 < 0 || visited[x][y]) continue;
                    
                    if (k2 < 0 || k2 <= visited[x][y]) continue;
                    visited[x][y] = k2;;
                    q.push({x, y, k2});
                }
            }
            ++ans;
        }
        return -1;
    }
};
// @lc code=end

