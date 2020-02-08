/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (33.41%)
 * Likes:    2932
 * Dislikes: 99
 * Total Accepted:    310.5K
 * Total Submissions: 929K
 * Testcase Example:  '[1,2,5]\n11'
 *
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 * 
 * Example 1:
 * 
 * 
 * Input: coins = [1, 2, 5], amount = 11
 * Output: 3 
 * Explanation: 11 = 5 + 5 + 1
 * 
 * Example 2:
 * 
 * 
 * Input: coins = [2], amount = 3
 * Output: -1
 * 
 * 
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 因为硬币可以重复使用，因此这是一个完全背包问题。完全背包只需要将 0-1 背包的逆序遍历 dp 数组改为正序遍历。

        // if (amount==0) return 0;
        
        // vector<int> dp(amount+1, 0);
        // for (int coin: coins) {
        //     for (int i=coin; i<=amount; i++) {
        //         if (i==coin) 
        //             dp[i] = 1;
        //         else if(dp[i]==0 && dp[i-coin]!=0)
        //             dp[i] = dp[i-coin] + 1;
        //         else if (dp[i-coin]!=0)
        //             dp[i] = min(dp[i], dp[i-coin]+1);
        //     }
        // }
        // return dp[amount]==0? -1: dp[amount];
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;

        // 顺序无关，内层遍历约束
        // for (int i=1; i<=amount; i++) {
        //     for (int coin: coins)
        //         if (coin<=i)
        for (int coin: coins) {
            for (int i=coin; i<=amount; i++) 
                dp[i] = min(dp[i], dp[i-coin]+1);
        }
        return dp[amount]==amount+1 ? -1: dp[amount];

        // combination
        // DFS 条件设置的合适，更快
        sort(coins.begin(), coins.end(), greater<int>());
        int ans = INT_MAX;
        DFS(coins, 0, amount, 0, ans);
        return ans==INT_MAX ? -1 : ans;
    }
    void DFS(vector<int>& coins, int start, int target, int cnt, int& ans) {
        if (cnt>=ans) return;
        if (target==0 && cnt<ans) {
            ans = cnt;
            return;
        }
        for (int i=start; i<coins.size(); i++) {
            if (target>=coins[i] && target/coins[i]<(ans-cnt))
                DFS(coins, i, target-coins[i], cnt+1, ans); 
        }
    }
};
// @lc code=end

