/*
 * @lc app=leetcode id=1039 lang=cpp
 *
 * [1039] Minimum Score Triangulation of Polygon
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int minScoreTriangulation(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int len=3; len<=n; len++) {
            for (int i=0; i<n-len+1; i++) {
                int j = i+len-1;
                
                dp[i][j] = INT_MAX;
                for (int k=i+1; k<j; k++) {
                    dp[i][j] = min(dp[i][j], 
                                   dp[i][k] + dp[k][j] + nums[i]*nums[k]*nums[j]);
                }
            }
        }
        return dp[0][n-1];

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        helper(nums, 0, n-1, dp);
        
        return dp[0][n-1];
    }

    int helper(vector<int>& nums, int i, int j, vector<vector<int>>& dp) {
        if (dp[i][j] != 0) return dp[i][j];
        
        for (int k=i+1; k<j; ++k) {
            dp[i][j] = min(dp[i][j]==0?INT_MAX: dp[i][j], 
                helper(nums, i, k, dp) + nums[i]*nums[k]*nums[j] + helper(nums, k, j, dp));
        }
        return dp[i][j];
    }
};
// @lc code=end

