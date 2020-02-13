/*
 * @lc app=leetcode id=934 lang=cpp
 *
 * [934] Shortest Bridge
 *
 * https://leetcode.com/problems/shortest-bridge/description/
 *
 * algorithms
 * Medium (45.95%)
 * Likes:    483
 * Dislikes: 39
 * Total Accepted:    18.4K
 * Total Submissions: 39.9K
 * Testcase Example:  '[[0,1],[1,0]]'
 *
 * In a given 2D binary array A, there are two islands.  (An island is a
 * 4-directionally connected group of 1s not connected to any other 1s.)
 * 
 * Now, we may change 0s to 1s so as to connect the two islands together to
 * form 1 island.
 * 
 * Return the smallest number of 0s that must be flipped.  (It is guaranteed
 * that the answer is at least 1.)
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[0,1],[1,0]]
 * Output: 1
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[0,1,0],[0,0,0],[0,0,1]]
 * Output: 2
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
 * Output: 1
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length = A[0].length <= 100
 * A[i][j] == 0 or A[i][j] == 1
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */
#include<vector>
#include<queue>
using namespace std;

// @lc code=start
class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int rows=grid.size(), cols=grid[0].size();
        bool found = false;
        queue<pair<int, int>> q;;

        for(int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                if (grid[i][j] && !found) {
                    DFS(grid, i, j);
                    found = true;
                }
                else if (found && grid[i][j]==1) {
                    q.push(make_pair(i, j));
                }
            }
        }
        
        int ans = 0;
        vector<vector<int>> ds{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        while(!q.empty()) {

            int q_size = q.size();
            while (q_size--) {
                pair<int, int> idx = q.front();
                q.pop();
                for (auto d: ds) {
                    int x = idx.first + d[0];
                    int y = idx.second + d[1];
                    
                    if (x<0 || x==grid.size() || y<0 || y==grid[0].size())
                        continue;
                    if (grid[x][y]==2) 
                        return ans;
                    else if (grid[x][y]==1)
                        continue;
                    else if (grid[x][y]==0) {
                        grid[x][y] = 1;
                        q.push(make_pair(x, y));
                    }
                }
            }
            ans++;    
        }
        return -1;
        
    }
    
    void DFS(vector<vector<int>>& grid, int i, int j) {
        if (i<0 || i==grid.size() || j<0 || j==grid[0].size() || grid[i][j]!=1)
            return;
        grid[i][j] = 2;
        DFS(grid, i-1, j);
        DFS(grid, i+1, j);
        DFS(grid, i, j-1);
        DFS(grid, i, j+1);
    }
};
// @lc code=end

