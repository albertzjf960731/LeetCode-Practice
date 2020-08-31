/*
 * @lc app=leetcode id=980 lang=cpp
 *
 * [980] Unique Paths III
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int x = -1, y = -1, n = 1;
        for (int i=0; i<grid.size(); ++i) {
            for (int j=0; j<grid[0].size(); ++j) {
                if (grid[i][j]==0) n++;
                if (grid[i][j]==1) {x = i; y = j;}
            }
        }
        int ans = 0;
        DFS(grid, x, y, n, ans);
        return ans;
    }
    void DFS(vector<vector<int>>& grid, int x, int y, int n, int& ans) {
        if (x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y]==-1)
            return ;
        if (grid[x][y]==2) {
            if (n==0) 
                ans += 1;
            return;
        };
        
        grid[x][y] = -1;
        DFS(grid, x-1, y, n-1, ans);
        DFS(grid, x+1, y, n-1, ans);
        DFS(grid, x, y-1, n-1, ans);
        DFS(grid, x, y+1, n-1, ans);
        grid[x][y] = 0;
        return;
    }
};
// @lc code=end

