/*
 * @lc app=leetcode id=1000 lang=cpp
 *
 * [1000] Minimum Cost to Merge Stones
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int mergeStones(vector<int>& nums, int k) {
        int n = nums.size();
        if ((n-1) % (k-1) != 0) return -1;
        
        vector<int> sums(n+1);
        for (int i=1; i<n+1; ++i) sums[i] = sums[i-1] + nums[i-1];
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len=k; len<=n; ++len) {
            for (int i=0; i<n-len+1; ++i) {
                int j = i + len -1;
                
                dp[i][j] = INT_MAX;
                for (int t=i; t<j; t += k-1) {
                    dp[i][j] = min(dp[i][j], dp[i][t] + dp[t+1][j]);
                }
                if ((j-i) % (k-1) == 0)
                    dp[i][j] += sums[j+1] - sums[i];
            }
        }
        return dp[0][n-1];
    }
};
// @lc code=end

