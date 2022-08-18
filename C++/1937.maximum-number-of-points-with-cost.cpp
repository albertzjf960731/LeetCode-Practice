/*
 * @lc app=leetcode id=1937 lang=cpp
 *
 * [1937] Maximum Number of Points with Cost
 *
 * https://leetcode.com/problems/maximum-number-of-points-with-cost/description/
 *
 * algorithms
 * Medium (35.59%)
 * Likes:    1762
 * Dislikes: 107
 * Total Accepted:    46.7K
 * Total Submissions: 129.8K
 * Testcase Example:  '[[1,2,3],[1,5,1],[3,1,1]]'
 *
 * You are given an m x n integer matrix points (0-indexed). Starting with 0
 * points, you want to maximize the number of points you can get from the
 * matrix.
 * 
 * To gain points, you must pick one cell in each row. Picking the cell at
 * coordinates (r, c) will add points[r][c] to your score.
 * 
 * However, you will lose points if you pick a cell too far from the cell that
 * you picked in the previous row. For every two adjacent rows r and r + 1
 * (where 0 <= r < m - 1), picking cells at coordinates (r, c1) and (r + 1, c2)
 * will subtract abs(c1 - c2) from your score.
 * 
 * Return the maximum number of points you can achieve.
 * 
 * abs(x) is defined as:
 * 
 * 
 * x for x >= 0.
 * -x for x < 0.
 * 
 * 
 * 
 * Example 1: 
 * 
 * 
 * Input: points = [[1,2,3],[1,5,1],[3,1,1]]
 * Output: 9
 * Explanation:
 * The blue cells denote the optimal cells to pick, which have coordinates (0,
 * 2), (1, 1), and (2, 0).
 * You add 3 + 5 + 3 = 11 to your score.
 * However, you must subtract abs(2 - 1) + abs(1 - 0) = 2 from your score.
 * Your final score is 11 - 2 = 9.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: points = [[1,5],[2,3],[4,2]]
 * Output: 11
 * Explanation:
 * The blue cells denote the optimal cells to pick, which have coordinates (0,
 * 1), (1, 1), and (2, 0).
 * You add 5 + 3 + 4 = 12 to your score.
 * However, you must subtract abs(1 - 1) + abs(1 - 0) = 1 from your score.
 * Your final score is 12 - 1 = 11.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == points.length
 * n == points[r].length
 * 1 <= m, n <= 10^5
 * 1 <= m * n <= 10^5
 * 0 <= points[r][c] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = nums.size(), m = nums[0].size();
        vector<vector<long long>> dp(n, vector<long long>(m, -1));
        for (int i=0; i<m; ++i) dp[0][i] = nums[0][i];

        for (int i=1; i<n; ++i) {
            
            vector<long long> left(m, 0), right(m, 0);
            
            left[0] = dp[i-1][0];
            for (int j=1; j<m; ++j) 
                left[j] = max(left[j-1], dp[i-1][j]+j);
            
            right[m-1] = dp[i-1][m-1] - m + 1;
            for (int j=m-2; j>=0; --j) 
                right[j] = max(right[j+1], dp[i-1][j]-j);
            
            
            for (int j=0; j<m; ++j) 
                dp[i][j] = nums[i][j] + max(left[j]-j, right[j]+j);
            
        }

        long long ans = 0;
        for (int i=0; i<m; ++i) ans = max(ans, dp[n-1][i]);
        return ans;
    }
};
// @lc code=end

