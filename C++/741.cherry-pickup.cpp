/*
 * @lc app=leetcode id=741 lang=cpp
 *
 * [741] Cherry Pickup
 *
 * https://leetcode.com/problems/cherry-pickup/description/
 *
 * algorithms
 * Hard (32.89%)
 * Likes:    719
 * Dislikes: 54
 * Total Accepted:    18.8K
 * Total Submissions: 57.2K
 * Testcase Example:  '[[0,1,-1],[1,0,-1],[1,1,1]]'
 *
 * In a N x N grid representing a field of cherries, each cell is one of three
 * possible integers.
 * 
 * 
 * 
 * 
 * 0 means the cell is empty, so you can pass through;
 * 1 means the cell contains a cherry, that you can pick up and pass
 * through;
 * -1 means the cell contains a thorn that blocks your way.
 * 
 * 
 * 
 * 
 * Your task is to collect maximum number of cherries possible by following the
 * rules below:
 * 
 * 
 * 
 * 
 * Starting at the position (0, 0) and reaching (N-1, N-1) by moving right or
 * down through valid path cells (cells with value 0 or 1);
 * After reaching (N-1, N-1), returning to (0, 0) by moving left or up through
 * valid path cells;
 * When passing through a path cell containing a cherry, you pick it up and the
 * cell becomes an empty cell (0);
 * If there is no valid path between (0, 0) and (N-1, N-1), then no cherries
 * can be collected.
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid =
 * [[0, 1, -1],
 * ⁠[1, 0, -1],
 * ⁠[1, 1,  1]]
 * Output: 5
 * Explanation: 
 * The player started at (0, 0) and went down, down, right right to reach (2,
 * 2).
 * 4 cherries were picked up during this single trip, and the matrix becomes
 * [[0,1,-1],[0,0,-1],[0,0,0]].
 * Then, the player went left, up, up, left to return home, picking up one more
 * cherry.
 * The total number of cherries picked up is 5, and this is the maximum
 * possible.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * grid is an N by N 2D array, with 1 <= N <= 50.
 * Each grid[i][j] is an integer in the set {-1, 0, 1}.
 * It is guaranteed that grid[0][0] and grid[N-1][N-1] are not
 * -1.
 * 
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
    int cherryPickup(vector<vector<int>>& grid) {

        // Case 1: (0, 0) ==> (i-1, j) ==> (i, j); (p, q) ==> (p-1, q) ==> (0, 0)
        // Case 2: (0, 0) ==> (i-1, j) ==> (i, j); (p, q) ==> (p, q-1) ==> (0, 0)
        // Case 3: (0, 0) ==> (i, j-1) ==> (i, j); (p, q) ==> (p-1, q) ==> (0, 0)
        // Case 4: (0, 0) ==> (i, j-1) ==> (i, j); (p, q) ==> (p, q-1) ==> (0, 0)

        // Case 1 is equivalent to T(i-1, j, p-1, q) + grid[i][j] + grid[p][q];
        // Case 2 is equivalent to T(i-1, j, p, q-1) + grid[i][j] + grid[p][q];
        // Case 3 is equivalent to T(i, j-1, p-1, q) + grid[i][j] + grid[p][q];
        // Case 4 is equivalent to T(i, j-1, p, q-1) + grid[i][j] + grid[p][q];

        // T(i, j, p, q) = grid[i][j] + grid[p][q] + max{T(i-1, j, p-1, q), T(i-1, j, p, q-1), T(i, j-1, p-1, q), T(i, j-1, p, q-1)}

        // i<p && j>q || i==p && j==q || i>p && j<q

        // k = i + j = p + q, 其中k为从起点开始走的步数

        // T(k, i, p) = grid[i][k-i] + grid[p][k-p] + max{T(k-1, i-1, p-1), T(k-1, i-1, p), T(k-1, i, p-1), T(k-1, i, p)}.

       int n=grid.size(), m= 2*(n-1);

        vector<vector<int>> dp(n, vector<int>(n));
        dp[0][0] = grid[0][0];

        for (int k=1; k<=m; ++k) {
            for (int i=n-1; i>=0; --i) {
                for (int p=n-1; p>=0; --p) {

                    int j=k-i, q=k-p;
                    if (j<0 || j>=n || q<0 || q>=n || grid[i][j]<0 || grid[p][q]<0) {
                        dp[i][p] = -1;
                        continue;
                    }

                    if (i>0) 
                        dp[i][p] = max(dp[i][p], dp[i-1][p]);
                    if (p>0) 
                        dp[i][p] = max(dp[i][p], dp[i][p-1]);
                    if (i>0 && p>0) 
                        dp[i][p] = max(dp[i][p], dp[i-1][p-1]);
                    if (dp[i][p] >= 0) 
                        dp[i][p] += grid[i][j] + (i!=p ? grid[p][q]: 0);
                }
            }
        }
        return max(dp[n-1][n-1], 0);
    }
};
// @lc code=end

