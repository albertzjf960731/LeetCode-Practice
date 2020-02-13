/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (44.61%)
 * Likes:    4075
 * Dislikes: 148
 * Total Accepted:    541.6K
 * Total Submissions: 1.2M
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * Output: 3
 * 
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        if (grid.empty()) return ans;
        
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (grid[i][j]=='1') {
                    DFS(grid, i, j);
                    ans ++;
                }
            }
        }
        return ans;
    }
    
    void DFS(vector<vector<char>>& grid, int i, int j) {
        if (i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]!='1') 
            return;
        grid[i][j] = '0';
        DFS(grid, i-1, j);
        DFS(grid, i+1, j);
        DFS(grid, i, j-1);
        DFS(grid, i, j+1);
    }

};
// @lc code=end

