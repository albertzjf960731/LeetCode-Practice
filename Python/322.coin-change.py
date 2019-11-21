#
# @lc app=leetcode id=322 lang=python
#
# [322] Coin Change
#
# https://leetcode.com/problems/coin-change/description/
#
# algorithms
# Medium (32.33%)
# Likes:    2497
# Dislikes: 89
# Total Accepted:    272.5K
# Total Submissions: 837.4K
# Testcase Example:  '[1,2,5]\n11'
#
# You are given coins of different denominations and a total amount of money
# amount. Write a function to compute the fewest number of coins that you need
# to make up that amount. If that amount of money cannot be made up by any
# combination of the coins, return -1.
# 
# Example 1:
# 
# 
# Input: coins = [1, 2, 5], amount = 11
# Output: 3 
# Explanation: 11 = 5 + 5 + 1
# 
# Example 2:
# 
# 
# Input: coins = [2], amount = 3
# Output: -1
# 
# 
# Note:
# You may assume that you have an infinite number of each kind of coin.
# 
#

# @lc code=start
class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        # 因为硬币可以重复使用，因此这是一个完全背包问题。完全背包只需要将 0-1 背包的逆序遍历 dp 数组改为正序遍历即可。

        # if not amount:
        #     return 0

        # dp = [-1 for _ in range(amount+1)]
        # for coin in coins:
        #     for i in range(coin, amount+1):
        #         if i == coin:
        #             dp[i] = 1
        #         elif dp[i] == -1 and dp[i-coin] != -1:
        #             dp[i] = dp[i-coin] +1
        #         elif dp[i-coin] != -1:
        #             dp[i] = min(dp[i], dp[i-coin]+1)
        # return dp[-1]

        self.ans = float('inf')
        coins.sort(reverse=True)
        self.dfs(coins, 0, amount, 0)

        return self.ans if self.ans!=float('inf') else -1

    def dfs(self, coins, index, target, count):
        if count >= self.ans:
            return
        if target == 0 and count < self.ans:
            self.ans = count
            return

        for i in range(index, len(coins)):
            if coins[i] <= target < (self.ans-count)*coins[i]:
                self.dfs(coins, i, target-coins[i], count+1)
 


# @lc code=end

sol = Solution()
# coins = [186,419,83,408]
# amount = 6249
coins = [2]
amount = 3
print(sol.coinChange(coins, amount))