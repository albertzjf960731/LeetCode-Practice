/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 *
 * https://leetcode.com/problems/pacific-atlantic-water-flow/description/
 *
 * algorithms
 * Medium (39.30%)
 * Likes:    950
 * Dislikes: 176
 * Total Accepted:    61K
 * Total Submissions: 155.1K
 * Testcase Example:  '[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]'
 *
 * Given an m x n matrix of non-negative integers representing the height of
 * each unit cell in a continent, the "Pacific ocean" touches the left and top
 * edges of the matrix and the "Atlantic ocean" touches the right and bottom
 * edges.
 * 
 * Water can only flow in four directions (up, down, left, or right) from a
 * cell to another one with height equal or lower.
 * 
 * Find the list of grid coordinates where water can flow to both the Pacific
 * and Atlantic ocean.
 * 
 * Note:
 * 
 * 
 * The order of returned grid coordinates does not matter.
 * Both m and n are less than 150.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Given the following 5x5 matrix:
 * 
 * ⁠ Pacific ~   ~   ~   ~   ~ 
 * ⁠      ~  1   2   2   3  (5) *
 * ⁠      ~  3   2   3  (4) (4) *
 * ⁠      ~  2   4  (5)  3   1  *
 * ⁠      ~ (6) (7)  1   4   5  *
 * ⁠      ~ (5)  1   1   2   4  *
 * ⁠         *   *   *   *   * Atlantic
 * 
 * Return:
 * 
 * [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with
 * parentheses in above matrix).
 * 
 * 
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        if (matrix.empty()) return res;

        int rows=matrix.size(), cols=matrix[0].size();
        vector<vector<bool>> p_visited(rows, vector<bool>(cols, false));
        vector<vector<bool>> a_visited(rows, vector<bool>(cols, false));

        for (int i=0; i<rows; i++) {
            DFS(matrix, i, 0, p_visited);
            DFS(matrix, i, cols-1, a_visited);
        }
        for (int j=0; j<cols; j++) {
            DFS(matrix, 0, j, p_visited);
            DFS(matrix, rows-1, 0, a_visited);
        }

        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                if (p_visited[i][j] && a_visited[i][j])
                    res.push_back(vector<int>{{i, j}});
            }
        }
        return res;
    }
    
    void DFS(vector<vector<int>>& matrix, int i, int j, vector<vector<bool>>& visited) {
        vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        visited[i][j] = true;
        for (auto d: directions) {
            int x=i+d[0], y=j+d[1];
            if (x<0 || x==matrix.size() || y<0 || y==matrix[0].size() || visited[x][y] || matrix[x][y]<matrix[i][j])
                continue;
            DFS(matrix, x, y, visited);
        }
    }
};
// @lc code=end

