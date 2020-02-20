/*
 * @lc app=leetcode id=1091 lang=cpp
 *
 * [1091] Shortest Path in Binary Matrix
 *
 * https://leetcode.com/problems/shortest-path-in-binary-matrix/description/
 *
 * algorithms
 * Medium (37.29%)
 * Likes:    233
 * Dislikes: 31
 * Total Accepted:    18.6K
 * Total Submissions: 49.9K
 * Testcase Example:  '[[0,1],[1,0]]'
 *
 * In an N by N square grid, each cell is either empty (0) or blocked (1).
 * 
 * A clear path from top-left to bottom-right has length k if and only if it is
 * composed of cells C_1, C_2, ..., C_k such that:
 * 
 * 
 * Adjacent cells C_i and C_{i+1} are connected 8-directionally (ie., they are
 * different and share an edge or corner)
 * C_1 is at location (0, 0) (ie. has value grid[0][0])
 * C_k is at location (N-1, N-1) (ie. has value grid[N-1][N-1])
 * If C_i is located at (r, c), then grid[r][c] is empty (ie. grid[r][c] ==
 * 0).
 * 
 * 
 * Return the length of the shortest such clear path from top-left to
 * bottom-right.  If such a path does not exist, return -1.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[0,1],[1,0]]
 * 
 * 
 * Output: 2
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[0,0,0],[1,1,0],[1,1,0]]
 * 
 * 
 * Output: 4
 * 
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= grid.length == grid[0].length <= 100
 * grid[r][c] is 0 or 1
 * 
 * 
 */
#include<vector>
#include<queue>
using namespace std;
// @lc code=start
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {                
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1)
            return -1;
                
        int ans = 0;
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        while(!q.empty()) {
            ans ++;
            
            int q_size = q.size();
            while (q_size--) {
                auto item = q.front();
                q.pop();

                int i=item.first, j=item.second;
                if (i==n-1 && j==n-1)
                    return ans;
                
                for (int a=-1; a<=1; a++) {
                    for (int b=-1; b<=1; b++) {
                        if (a==0 && b==0) continue;
                        
                        int x=i+a, y=j+b;
                        if (x>=0 && x<n && y>=0 && y<n && grid[x][y]==0) {
                            grid[x][y] = 1;
                            q.push(make_pair(x, y));
                        }
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end

