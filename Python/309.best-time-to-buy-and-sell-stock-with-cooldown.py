#
# @lc app=leetcode id=309 lang=python
#
# [309] Best Time to Buy and Sell Stock with Cooldown
#
# https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
#
# algorithms
# Medium (45.05%)
# Likes:    1698
# Dislikes: 64
# Total Accepted:    110.7K
# Total Submissions: 245.2K
# Testcase Example:  '[1,2,3,0,2]'
#
# Say you have an array for which the i^th element is the price of a given
# stock on day i.
# 
# Design an algorithm to find the maximum profit. You may complete as many
# transactions as you like (ie, buy one and sell one share of the stock
# multiple times) with the following restrictions:
# 
# 
# You may not engage in multiple transactions at the same time (ie, you must
# sell the stock before you buy again).
# After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1
# day)
# 
# 
# Example:
# 
# 
# Input: [1,2,3,0,2]
# Output: 3 
# Explanation: transactions = [buy, sell, cooldown, buy, sell]
# 
#

# @lc code=start
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        # buy[i] means before day i what is the maxProfit for any sequence end with buy.

        # sell[i] means before day i what is the maxProfit for any sequence end with sell.

        # rest[i] means before day i what is the maxProfit for any sequence end with rest.

        # buy[i]  = max(rest[i-1]-price, buy[i-1]) 
        # sell[i] = max(buy[i-1]+price, sell[i-1])
        # rest[i] = max(sell[i-1], buy[i-1], rest[i-1])

        rest[i] = sell[i-1]
        buy[i] = max(sell[i-2]-price, buy[i-1])
        sell[i] = max(buy[i-1]+price, sell[i-1])

        # if len(prices) < 2:
        #     return 0
        # sell, buy, prev_sell, prev_buy = 0, -prices[0], 0, 0
        # for price in prices:
        #     prev_buy = buy
        #     buy = max(prev_sell - price, prev_buy)
        #     prev_sell = sell
        #     sell = max(prev_buy + price, prev_sell)
        # return sell

        # n = len(prices)
        # if (n <= 1):
        #     return 0

        # buy = [0] * n
        # sell = [0] * n
        # buy[0] = -prices[0]
        # for i in range(1, n):
        #     buy[i] = max(sell[max(i-2, 0)]-prices[i], buy[i-1])
        #     sell[i] = max(buy[i-1]+prices[i], sell[i-1])
        # return sell[-1]


        n = len(prices)
        if n < 2:
            return 0
        buy = [0 for _ in range(n)]
        hold = [0 for _ in range(n)]
        sell = [0 for _ in range(n)]
        rest = [0 for _ in range(n)]

        hold[0] = buy[0] = -prices[0]
        for i in range(1, n):
            buy[i] = rest[i-1] - prices[i]
            hold[i] = max(buy[i-1], hold[i-1])
            sell[i] = max(buy[i-1], hold[i-1]) + prices[i]
            rest[i] = max(rest[i-1], sell[i-1])
        return max(sell[-1], rest[-1])

# @lc code=end

