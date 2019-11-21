#
# @lc app=leetcode id=188 lang=python
#
# [188] Best Time to Buy and Sell Stock IV
#
# https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
#
# algorithms
# Hard (27.06%)
# Likes:    1002
# Dislikes: 61
# Total Accepted:    104.3K
# Total Submissions: 384.6K
# Testcase Example:  '2\n[2,4,1]'
#
# Say you have an array for which the i-th element is the price of a given
# stock on day i.
# 
# Design an algorithm to find the maximum profit. You may complete at most k
# transactions.
# 
# Note:
# You may not engage in multiple transactions at the same time (ie, you must
# sell the stock before you buy again).
# 
# Example 1:
# 
# 
# Input: [2,4,1], k = 2
# Output: 2
# Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit =
# 4-2 = 2.
# 
# 
# Example 2:
# 
# 
# Input: [3,2,6,5,0,3], k = 2
# Output: 7
# Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit =
# 6-2 = 4.
# Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 =
# 3.
# 
# 
#

# @lc code=start
class Solution(object):
    def maxProfit(self, k, prices):
        """
        :type k: int
        :type prices: List[int]
        :rtype: int
        """
        # dp[k, i] = max(dp[k, i-1], prices[i] - prices[j] + dp[k-1, j-1]), j=[0..i-1]

        n = len(prices)
        if n<=1:
            return 0
        
        if k >= n//2:
            max_profit = 0
            for i in range(1, n):
                if prices[i] > prices[i-1]:
                    max_profit += prices[i]-prices[i-1]
            return max_profit
        

        dp = [[0 for _ in range(n)] for _ in range(k+1)]
        
        for i in range(1, k+1):
            cur_min = prices[0]
            for j in range(1, n):
                cur_min = min(cur_min, prices[j]-dp[i-1][j-1])
                dp[i][j] = max(dp[i][j-1], prices[j]-cur_min)
        return dp[-1][-1]


        # # buy[i]  = max(sell[i-1]-price, buy[i-1]) 
        # # sell[i] = max(buy[i-1]+price, sell[i-1])

        # if len(prices) < 2:
        #     return 0
        # sell, buy, prev_sell, prev_buy = 0, -prices[0], 0, 0
        # for price in prices:
        #     prev_buy = buy
        #     prev_sell = sell

        #     buy = max(prev_sell - price, prev_buy)
        #     sell = max(prev_buy + price, prev_sell)
        # return sell



# @lc code=end

