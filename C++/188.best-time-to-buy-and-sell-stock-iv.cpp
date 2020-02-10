/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
 *
 * algorithms
 * Hard (27.37%)
 * Likes:    1104
 * Dislikes: 67
 * Total Accepted:    110.6K
 * Total Submissions: 404.2K
 * Testcase Example:  '2\n[2,4,1]'
 *
 * Say you have an array for which the i-th element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete at most k
 * transactions.
 * 
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must
 * sell the stock before you buy again).
 * 
 * Example 1:
 * 
 * 
 * Input: [2,4,1], k = 2
 * Output: 2
 * Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit
 * = 4-2 = 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,6,5,0,3], k = 2
 * Output: 7
 * Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit
 * = 6-2 = 4.
 * Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 =
 * 3.
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n<=1) return 0;

        if (k>=n/2) {
            int ans = 0;
            for (int i=1; i<prices.size(); i++)
                ans += max(0, prices[i]-prices[i-1]);
            return ans;
        }

        // dp[k, i] represents the max profit up until prices[i] using at most k transactions. 
        // dp[k, i] = max(dp[k, i-1], prices[i]-prices[j]+dp[k-1, j-1]), j=[0..i-1]
        vector<vector<int>> dp(k+1, vector<int>(n));
        for (int i=1; i<=k; i++) {
            int cur_min = prices[0];
            for (int j=1; j<n; j++) {

                // int cur_min = prices[0];
                // for (int p = 1; p <= i; p++)
                //     cur_min = min(cur_min, prices[p]-dp[i-1][p-1]);

                cur_min = min(cur_min, prices[j]-dp[i-1][j-1]);
                dp[i][j] = max(dp[i][j-1], prices[j]-cur_min);
            }
        }
        return dp[k][n-1];    
    }
};
// @lc code=end

