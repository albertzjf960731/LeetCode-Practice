/*
 * @lc app=leetcode id=1770 lang=cpp
 *
 * [1770] Maximum Score from Performing Multiplication Operations
 *
 * https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/description/
 *
 * algorithms
 * Medium (35.68%)
 * Likes:    844
 * Dislikes: 215
 * Total Accepted:    39.3K
 * Total Submissions: 112.6K
 * Testcase Example:  '[1,2,3]\n[3,2,1]'
 *
 * You are given two integer arrays nums and multipliers of size n and m
 * respectively, where n >= m. The arrays are 1-indexed.
 * 
 * You begin with a score of 0. You want to perform exactly m operations. On
 * the i^th operation (1-indexed), you will:
 * 
 * 
 * Choose one integer x from either the start or the end of the array nums.
 * Add multipliers[i] * x to your score.
 * Remove x from the array nums.
 * 
 * 
 * Return the maximum score after performing m operations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3], multipliers = [3,2,1]
 * Output: 14
 * Explanation: An optimal solution is as follows:
 * - Choose from the end, [1,2,3], adding 3 * 3 = 9 to the score.
 * - Choose from the end, [1,2], adding 2 * 2 = 4 to the score.
 * - Choose from the end, [1], adding 1 * 1 = 1 to the score.
 * The total score is 9 + 4 + 1 = 14.
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [-5,-3,-3,-2,7,1], multipliers = [-10,-5,3,4,6]
 * Output: 102
 * Explanation: An optimal solution is as follows:
 * - Choose from the start, [-5,-3,-3,-2,7,1], adding -5 * -10 = 50 to the
 * score.
 * - Choose from the start, [-3,-3,-2,7,1], adding -3 * -5 = 15 to the score.
 * - Choose from the start, [-3,-2,7,1], adding -3 * 3 = -9 to the score.
 * - Choose from the end, [-2,7,1], adding 1 * 4 = 4 to the score.
 * - Choose from the end, [-2,7], adding 7 * 6 = 42 to the score. 
 * The total score is 50 + 15 - 9 + 4 + 42 = 102.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == nums.length
 * m == multipliers.length
 * 1 <= m <= 10^3
 * m <= n <= 10^5 
 * -1000 <= nums[i], multipliers[i] <= 1000
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size(), m = muls.size();
        int ans = INT_MIN;
        
        vector<vector<int>> dp(m+1, vector<int>(m+1, 0));
        for(int k=1; k<=m; ++k){
            for(int l=0; l<=k; l++){
                int r = k - l;
                
                if(l==0) {
                    dp[l][r] = dp[l][r-1] + nums[n-r]*muls[k-1];
                }
                else if(r==0) {
                    dp[l][r] = dp[l-1][r] + nums[l-1]*muls[k-1];
                }
                else {
                    dp[l][r] = max(
                        dp[l][r-1] + nums[n-r] * muls[k-1], 
                        dp[l-1][r] + nums[l-1] * muls[k-1]
                    );
                }
                if(k==m) ans = max(ans, dp[l][r]);
            }
        }
        return ans;
    }
};
// @lc code=end

