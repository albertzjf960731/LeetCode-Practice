/*
 * @lc app=leetcode id=1139 lang=cpp
 *
 * [1139] Largest 1-Bordered Square
 *
 * https://leetcode.com/problems/largest-1-bordered-square/description/
 *
 * algorithms
 * Medium (50.06%)
 * Likes:    616
 * Dislikes: 93
 * Total Accepted:    21.7K
 * Total Submissions: 43.2K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given a 2D grid of 0s and 1s, return the number of elements in the largest
 * square subgrid that has all 1s on its border, or 0 if such a subgrid doesn't
 * exist in the grid.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
 * Output: 9
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[1,1,0,0]]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= grid.length <= 100
 * 1 <= grid[0].length <= 100
 * grid[i][j] is 0 or 1
 * 
 */

// @lc code=start
class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> left(n, vector<int>(m, 0)), up(n, vector<int>(m, 0));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (grid[i][j] == 1) {
                    left[i][j] = j==0 ? 1 : left[i][j-1] + 1;
                    up[i][j] = i==0 ? 1 : up[i-1][j] + 1;
                }
            }
        }

        for (int l=min(n, m); l>=1; --l)
            for (int i=0; i<n-l+1; ++i)
                for (int j=0; j<m-l+1; ++j)
                    if (up[i+l-1][j] >= l && up[i+l-1][j+l-1] >= l &&
                        left[i][j+l-1] >= l && left[i+l-1][j+l-1] >= l)
                        return l * l;
        return 0;
    }
};
// @lc code=end

