/*
 * @lc app=leetcode id=1329 lang=cpp
 *
 * [1329] Sort the Matrix Diagonally
 *
 * https://leetcode.com/problems/sort-the-matrix-diagonally/description/
 *
 * algorithms
 * Medium (81.43%)
 * Likes:    2523
 * Dislikes: 199
 * Total Accepted:    119.7K
 * Total Submissions: 143.8K
 * Testcase Example:  '[[3,3,1,1],[2,2,1,2],[1,1,1,2]]'
 *
 * A matrix diagonal is a diagonal line of cells starting from some cell in
 * either the topmost row or leftmost column and going in the bottom-right
 * direction until reaching the matrix's end. For example, the matrix diagonal
 * starting from mat[2][0], where mat is a 6 x 3 matrix, includes cells
 * mat[2][0], mat[3][1], and mat[4][2].
 * 
 * Given an m x n matrix mat of integers, sort each matrix diagonal in
 * ascending order and return the resulting matrix.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
 * Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: mat =
 * [[11,25,66,1,69,7],[23,55,17,45,15,52],[75,31,36,44,58,8],[22,27,33,25,68,4],[84,28,14,11,5,50]]
 * Output:
 * [[5,17,4,1,52,7],[11,11,25,45,8,69],[14,23,25,44,58,15],[22,27,31,36,50,66],[84,28,75,33,55,68]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 100
 * 1 <= mat[i][j] <= 100
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        
        vector<vector<int>> tmp(n+m-1);
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j)
                tmp[i-j+m-1].push_back(mat[i][j]);
        }
        
        for (int i=0; i<tmp.size(); ++i) 
            sort(tmp[i].begin(), tmp[i].end());
        
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i=n-1; i>=0; --i) {
            for (int j=m-1; j>=0; --j) {
                ans[i][j] = tmp[i-j+m-1].back();
                tmp[i-j+m-1].pop_back();
            }
        }
        return ans;


        int m = mat.size(), n = mat[0].size();
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> hmap; 
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                hmap[i-j].push(mat[i][j]);
            }
        }
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                mat[i][j] = hmap[i-j].top(); 
                hmap[i-j].pop();
            }
        }
        return mat;
    }
};
// @lc code=end

