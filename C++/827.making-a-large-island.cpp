/*
 * @lc app=leetcode id=827 lang=cpp
 *
 * [827] Making A Large Island
 *
 * https://leetcode.com/problems/making-a-large-island/description/
 *
 * algorithms
 * Hard (44.54%)
 * Likes:    344
 * Dislikes: 12
 * Total Accepted:    13.4K
 * Total Submissions: 30.1K
 * Testcase Example:  '[[1,0],[0,1]]'
 *
 * In a 2D grid of 0s and 1s, we change at most one 0 to a 1.
 * 
 * After, what is the size of the largest island? (An island is a
 * 4-directionally connected group of 1s).
 * 
 * Example 1:
 * 
 * 
 * Input: [[1, 0], [0, 1]]
 * Output: 3
 * Explanation: Change one 0 to 1 and connect two 1s, then we get an island
 * with area = 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1, 1], [1, 0]]
 * Output: 4
 * Explanation: Change the 0 to 1 and make the island bigger, only one island
 * with area = 4.
 * 
 * Example 3:
 * 
 * 
 * Input: [[1, 1], [1, 1]]
 * Output: 4
 * Explanation: Can't change any 0 to 1, only one island with area = 4.
 * 
 * 
 * 
 * Notes:
 * 
 * 
 * 1 <= grid.length = grid[0].length <= 50.
 * 0 <= grid[i][j] <= 1.
 * 
 * 
 * 
 * 
 */
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    // int largestIsland(vector<vector<int>>& grid) {
    //     int ans = 0;

    //     bool hasZero = false;
    //     for (int i=0; i<grid.size(); ++i) {
    //         for (int j=0; j<grid[0].size(); ++j) {
    //             if (grid[i][j]==0) {
    //                 grid[i][j] = 1;
                    
    //                 vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    //                 ans = max(ans, DFS(grid, i, j, visited));
    //                 if (ans == grid[0].size() * grid[0].size()) 
    //                     return ans;
    //                 grid[i][j] = 0;
    //                 hasZero = true; 
    //             }
    //         }
    //     }
    //     return hasZero ? ans :grid[0].size() * grid[0].size();
    // }

    // int DFS(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
    //     if (i<0 || i==grid.size() || j<0 || j==grid[0].size() || grid[i][j]==0 || visited[i][j]) 
    //         return 0;

    //     visited[i][j] = true;
    //     return 1 + DFS(grid, i-1, j , visited) + DFS(grid, i+1, j , visited) + DFS(grid, i, j-1, visited) + DFS(grid, i, j+1, visited);
    // }
    

    int largestIsland(vector<vector<int>>& grid) {
        int ans = 0;
        unordered_map <int, int> area_map;

        int pixel=2;
        for (int i=0; i<grid.size(); ++i) {
            for (int j=0; j<grid[0].size(); ++j) {
                if (grid[i][j]==1) {
                    int area = DFS(grid, i, j, pixel);
                    ans = max(ans, area);
                    area_map[pixel++] = area;
                }
            }
        }

        vector<vector<int>> ds{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int i=0; i<grid.size(); ++i) {
            for (int j=0; j<grid[0].size(); ++j) {
                if (grid[i][j]==0) {
                    unordered_set<int> visited = {};
                    int cur_area = 1;

                    for (vector<int> d: ds) {
                        int x=i+d[0], y=j+d[1];
                        if (x<0 || x==grid.size() || y<0 || y==grid[0].size())
                            continue;
                        pixel = grid[x][y];
                        if (pixel>1 && !visited.count(pixel)) {
                            cur_area += area_map[pixel];
                            visited.insert(pixel);
                        }
                    }
                    ans = max(ans, cur_area);
                }
            }
        }   
        return ans;
    }

    int DFS(vector<vector<int>>& grid, int i, int j, int pixel) {
        if (i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]!=1)
            return 0;
        
        grid[i][j] = pixel;
        return 1 + DFS(grid, i-1, j, pixel) + DFS(grid, i+1, j, pixel) + DFS(grid, i, j-1, pixel) + DFS(grid, i, j+1, pixel);
    }
};
// @lc code=end

