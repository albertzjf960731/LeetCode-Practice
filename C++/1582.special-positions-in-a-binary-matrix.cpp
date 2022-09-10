/*
 * @lc app=leetcode id=1582 lang=cpp
 *
 * [1582] Special Positions in a Binary Matrix
 *
 * https://leetcode.com/problems/special-positions-in-a-binary-matrix/description/
 *
 * algorithms
 * Easy (65.29%)
 * Likes:    503
 * Dislikes: 19
 * Total Accepted:    34.5K
 * Total Submissions: 52.8K
 * Testcase Example:  '[[1,0,0],[0,0,1],[1,0,0]]'
 *
 * Given an m x n binary matrix mat, return the number of special positions in
 * mat.
 * 
 * A position (i, j) is called special if mat[i][j] == 1 and all other elements
 * in row i and column j are 0 (rows and columns are 0-indexed).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: mat = [[1,0,0],[0,0,1],[1,0,0]]
 * Output: 1
 * Explanation: (1, 2) is a special position because mat[1][2] == 1 and all
 * other elements in row 1 and column 2 are 0.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: mat = [[1,0,0],[0,1,0],[0,0,1]]
 * Output: 3
 * Explanation: (0, 0), (1, 1) and (2, 2) are special positions.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 100
 * mat[i][j] is either 0 or 1.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> row_sum(n, 0), col_sum(m, 0);
        
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                row_sum[i] += mat[i][j];
                col_sum[j] += mat[i][j];
            }
        }
        
        int ans = 0;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (mat[i][j]==1 && row_sum[i]==1 && col_sum[j]==1)
                    ans += 1;
            }
        }
        return ans;
    }
};
// @lc code=end

