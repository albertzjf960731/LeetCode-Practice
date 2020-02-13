/*
 * @lc app=leetcode id=1254 lang=cpp
 *
 * [1254] Number of Closed Islands
 *
 * https://leetcode.com/problems/number-of-closed-islands/description/
 *
 * algorithms
 * Medium (59.69%)
 * Likes:    168
 * Dislikes: 10
 * Total Accepted:    9.5K
 * Total Submissions: 15.9K
 * Testcase Example:  '[[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]'
 *
 * Given a 2D grid consists of 0s (land) and 1s (water).  An island is a
 * maximal 4-directionally connected group of 0s and a closed island is an
 * island totally (all left, top, right, bottom) surrounded by 1s.
 * 
 * Return the number of closed islands.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: grid =
 * [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
 * Output: 2
 * Explanation: 
 * Islands in gray are closed because they are completely surrounded by water
 * (group of 1s).
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: grid = [[1,1,1,1,1,1,1],
 * [1,0,0,0,0,0,1],
 * [1,0,1,1,1,0,1],
 * [1,0,1,0,1,0,1],
 * [1,0,1,1,1,0,1],
 * [1,0,0,0,0,0,1],
 * ⁠              [1,1,1,1,1,1,1]]
 * Output: 2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= grid.length, grid[0].length <= 100
 * 0 <= grid[i][j] <=1
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        int rows=grid.size(), cols=grid[0].size();
        for (int i=0; i<rows; i++) {
            if (grid[i][0]==0)
                DFS(grid, i, 0);
            if (grid[i][cols-1]==0)
                DFS(grid, i, cols-1);
        }
        for (int j=0; j<cols; j++) {
            if (grid[0][j]==0)
                DFS(grid, 0, j);
            if (grid[rows-1][j]==0) {
                DFS(grid, rows-1, j);
            }
        }

        int ans = 0;  
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (grid[i][j]==0) {
                DFS(grid, i, j);
                    ans ++;
                }
            }
        }
        return ans;
    }
    
    void DFS(vector<vector<int>>& grid, int i, int j) {
        if (i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]!=0) 
            return;
        grid[i][j] = -1;
        DFS(grid, i-1, j);
        DFS(grid, i+1, j);
        DFS(grid, i, j-1);
        DFS(grid, i, j+1);
    }
};
// @lc code=end

