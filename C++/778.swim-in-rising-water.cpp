/*
 * @lc app=leetcode id=778 lang=cpp
 *
 * [778] Swim in Rising Water
 *
 * https://leetcode.com/problems/swim-in-rising-water/description/
 *
 * algorithms
 * Hard (49.88%)
 * Likes:    397
 * Dislikes: 33
 * Total Accepted:    16.9K
 * Total Submissions: 33.8K
 * Testcase Example:  '[[0,2],[1,3]]'
 *
 * On an N x N grid, each square grid[i][j] represents the elevation at that
 * point (i,j).
 * 
 * Now rain starts to fall. At time t, the depth of the water everywhere is t.
 * You can swim from a square to another 4-directionally adjacent square if and
 * only if the elevation of both squares individually are at most t. You can
 * swim infinite distance in zero time. Of course, you must stay within the
 * boundaries of the grid during your swim.
 * 
 * You start at the top left square (0, 0). What is the least time until you
 * can reach the bottom right square (N-1, N-1)?
 * 
 * Example 1:
 * 
 * 
 * Input: [[0,2],[1,3]]
 * Output: 3
 * Explanation:
 * At time 0, you are in grid location (0, 0).
 * You cannot go anywhere else because 4-directionally adjacent neighbors have
 * a higher elevation than t = 0.
 * 
 * You cannot reach point (1, 1) until time 3.
 * When the depth of water is 3, we can swim anywhere inside the grid.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
 * Output: 16
 * Explanation:
 * ⁠0  1  2  3  4
 * 24 23 22 21  5
 * 12 13 14 15 16
 * 11 17 18 19 20
 * 10  9  8  7  6
 * 
 * The final route is marked in bold.
 * We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
 * 
 * 
 * Note:
 * 
 * 
 * 2 <= N <= 50.
 * grid[i][j] is a permutation of [0, ..., N*N - 1].
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        unordered_set<int> visited;
        
        // auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
        //     return a.first > b.first;
        // };
        // priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp) > pq(cmp);

        priority_queue<pair<int, int>, 
                        vector<pair<int, int>>, 
                        greater<pair<int, int>>> pq;
                
        pq.push({grid[0][0], 0});
        visited.insert(0);
        int ans = 0;
        while (!pq.empty()) {
            int i = pq.top().second / n, j = pq.top().second % n; 
            pq.pop();
            
            ans = max(ans, grid[i][j]);
            if (i == n-1 && j == n-1) break;
            
            for (auto d: dirs) {
                int x = i+d[0], y = j+d[1];
                if (x < 0 || x >= n || y < 0 || y >= n) continue;
                if (visited.count(x*n+y)) continue;
                
                visited.insert(x*n+y);
                pq.push({grid[x][y], x * n + y});
            }
        }
        return ans;
    }
};
// @lc code=end

