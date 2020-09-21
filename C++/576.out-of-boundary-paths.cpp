/*
 * @lc app=leetcode id=576 lang=cpp
 *
 * [576] Out of Boundary Paths
 *
 * https://leetcode.com/problems/out-of-boundary-paths/description/
 *
 * algorithms
 * Medium (35.20%)
 * Likes:    582
 * Dislikes: 136
 * Total Accepted:    30K
 * Total Submissions: 85K
 * Testcase Example:  '2\n2\n2\n0\n0'
 *
 * There is an m by n grid with a ball. Given the start coordinate (i,j) of the
 * ball, you can move the ball to adjacent cell or cross the grid boundary in
 * four directions (up, down, left, right). However, you can at most move N
 * times. Find out the number of paths to move the ball out of grid boundary.
 * The answer may be very large, return it after mod 10^9 + 7.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: m = 2, n = 2, N = 2, i = 0, j = 0
 * Output: 6
 * Explanation:
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: m = 1, n = 3, N = 3, i = 0, j = 1
 * Output: 12
 * Explanation:
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * Once you move the ball out of boundary, you cannot move it back.
 * The length and height of the grid is in range [1,50].
 * N is in range [0,50].
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> dp(N+1, 
                                       vector<vector<int>>(m, vector<int>(n, 0)));
        
        for (int k=1; k<=N; ++k) {
            for (int x=0; x<m; ++x) {
                for (int y = 0; y < n; ++y) {
                    long long v1 = (x==0) ? 1 : dp[k-1][x-1][y];
                    long long v2 = (x==m-1) ? 1 : dp[k-1][x+1][y];
                    long long v3 = (y==0) ? 1 : dp[k-1][x][y-1];
                    long long v4 = (y==n-1) ? 1 : dp[k-1][x][y+1];
                    dp[k][x][y] = (v1+v2+v3+v4) % 1000000007;
                }
            }
        } 
        return dp[N][i][j];
    }
};
// @lc code=end

