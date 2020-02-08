/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change 2
 *
 * https://leetcode.com/problems/coin-change-2/description/
 *
 * algorithms
 * Medium (46.06%)
 * Likes:    1197
 * Dislikes: 46
 * Total Accepted:    72.5K
 * Total Submissions: 157.3K
 * Testcase Example:  '5\n[1,2,5]'
 *
 * You are given coins of different denominations and a total amount of money.
 * Write a function to compute the number of combinations that make up that
 * amount. You may assume that you have infinite number of each kind of
 * coin.
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: amount = 5, coins = [1, 2, 5]
 * Output: 4
 * Explanation: there are four ways to make up the amount:
 * 5=5
 * 5=2+2+1
 * 5=2+1+1+1
 * 5=1+1+1+1+1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: amount = 3, coins = [2]
 * Output: 0
 * Explanation: the amount of 3 cannot be made up just with coins of 2.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: amount = 10, coins = [10] 
 * Output: 1
 * 
 * 
 * 
 * 
 * Note:
 * 
 * You can assume that
 * 
 * 
 * 0 <= amount <= 5000
 * 1 <= coin <= 5000
 * the number of coins is less than 500
 * the answer is guaranteed to fit into signed 32-bit integer
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins) {

        // inner loop: when we create an amount array from 0...Amount, if we iterate over all the coins a solution can be added twice. For example to create 7:

        // When amount is 2 and the coin value is 5, it would be counted as 1 way.
        // When amount is 5 and the coin value is 2, the number of ways become 2.
        
        vector<int> dp(amount+1, 0);
        dp[0] = 1;

        //  顺序无关
        // In the steps problem, the order matters: (1,2) is not the same as (2,1). With the coin problem, only the number of each type of coin used matters.
        
        for (int coin: coins) {
            for (int i=coin; i<=amount; i++) 
                dp[i] += dp[i-coin];
        }
        return dp[amount];
    }
};
// @lc code=end

