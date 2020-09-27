/*
 * @lc app=leetcode id=1162 lang=cpp
 *
 * [1162] As Far from Land as Possible
 *
 * https://leetcode.com/problems/as-far-from-land-as-possible/description/
 *
 * algorithms
 * Medium (43.51%)
 * Likes:    540
 * Dislikes: 29
 * Total Accepted:    22.3K
 * Total Submissions: 50.9K
 * Testcase Example:  '[[1,0,1],[0,0,0],[1,0,1]]'
 *
 * Given an N x N grid containing only values 0 and 1, where 0 represents water
 * and 1 represents land, find a water cell such that its distance to the
 * nearest land cell is maximized and return the distance.
 * 
 * The distance used in this problem is the Manhattan distance: the distance
 * between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.
 * 
 * If no land or water exists in the grid, return -1.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: [[1,0,1],[0,0,0],[1,0,1]]
 * Output: 2
 * Explanation: 
 * The cell (1, 1) is as far as possible from all the land with distance 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: [[1,0,0],[0,0,0],[0,0,0]]
 * Output: 4
 * Explanation: 
 * The cell (2, 2) is as far as possible from all the land with distance
 * 4.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= grid.length == grid[0].length <= 100
 * grid[i][j] is 0 or 1
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dp(n, vector<int>(n));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                dp[i][j] = (grid[i][j]==1 ? 0 : 2*n);
            }
        }

        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j]==1) continue;
                if (i-1>=0) dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
                if (j-1>=0) dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
            }
        }

        for (int i=n-1; i>=0; --i) {
            for (int j=n-1; j>=0; --j) {
                if (grid[i][j]==1) continue;
                if (i+1<n) dp[i][j] = min(dp[i][j], dp[i+1][j]+1);
                if (j+1<n) dp[i][j] = min(dp[i][j], dp[i][j+1]+1);
            }
        }

        int ans = -1;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j]==0) {
                    ans = max(ans, dp[i][j]);
                }
            }
        }

        if (ans == 2*n) return -1;
        else return ans;
    }
    //     for (int i=0; i<g.size(); ++i) {
    //         for (int j=0; j<g[i].size(); ++j) {
    //             if (g[i][j]==1) {
    //                 g[i][j] = 0;
    //                 DFS(g, i, j);
    //             }
    //         }
    //     }
        
    //     int ans = 0;
    //     for (int i=0; i<g.size(); ++i) {
    //         for (int j=0; j<g[i].size(); ++j) {
    //             if (g[i][j] > 1) {
    //                 ans = max(ans, g[i][j]);
    //             }
    //         }
    //     }
    //     return ans-1;
    // }

    // void DFS(vector<vector<int>>& g, int i, int j, int dist=1) {
    //     if (i<0 || j<0 || i>=g.size() || j>=g[i].size() || (g[i][j]!=0 && g[i][j]<=dist)) 
    //         return;
        
    //     g[i][j] = dist;
    //     DFS(g, i-1, j, dist+1);
    //     DFS(g, i+1, j, dist+1);
    //     DFS(g, i, j-1, dist+1);
    //     DFS(g, i, j+1, dist+1);
    // }
};
// @lc code=end

