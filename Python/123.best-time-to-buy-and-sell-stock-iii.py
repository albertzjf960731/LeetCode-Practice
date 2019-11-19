#
# @lc app=leetcode id=123 lang=python
#
# [123] Best Time to Buy and Sell Stock III
#
# https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
#
# algorithms
# Hard (35.21%)
# Likes:    1443
# Dislikes: 59
# Total Accepted:    173.9K
# Total Submissions: 493.3K
# Testcase Example:  '[3,3,5,0,0,3,1,4]'
#
# Say you have an array for which the i^th element is the price of a given
# stock on day i.
# 
# Design an algorithm to find the maximum profit. You may complete at most two
# transactions.
# 
# Note: You may not engage in multiple transactions at the same time (i.e., you
# must sell the stock before you buy again).
# 
# Example 1:
# 
# 
# Input: [3,3,5,0,0,3,1,4]
# Output: 6
# Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit =
# 3-0 = 3.
# Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 =
# 3.
# 
# Example 2:
# 
# 
# Input: [1,2,3,4,5]
# Output: 4
# Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit =
# 5-1 = 4.
# Note that you cannot buy on day 1, buy on day 2 and sell them later, as you
# are
# engaging multiple transactions at the same time. You must sell before buying
# again.
# 
# 
# Example 3:
# 
# 
# Input: [7,6,4,3,1]
# Output: 0
# Explanation: In this case, no transaction is done, i.e. max profit = 0.
# 
#

# @lc code=start
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """

        # profit = []
        # i, j = 0, 0
        # while i<len(prices)-1 and j<len(prices)-1:
        #     while j<len(prices)-1 and prices[j] <= prices[j+1]:
        #         j += 1

        #     profit.append(prices[j]-prices[i])
            
        #     i, j = j+1, j+1
        
        # if len(profit)<=2:
        #     return sum(profit)
        # else:
        #     profit.sort()
        #     return sum(profit[-2:])


        # dp[k, i] = max(dp[k, i-1], prices[i] - prices[j] + dp[k-1, j-1]), j=[0..i-1]
        # dp = [0 for _ in range(3)]
        # cur_min = [0 for _ in range(3)]
        if not prices:
            return 0
        dp = [[0 for _ in range(len(prices))] for _ in range(3)]
        for k in range(1, 3):
            cur_min = prices[0]
            for i in range(1, len(prices)):
                cur_min = min(cur_min, prices[i]-dp[k-1][i-1])
                dp[k][i] = max(dp[k][i-1], prices[i]-cur_min)
        return dp[2][-1]


        # if not prices:
        #     return 0
        # s0 = 0
        # # s1 = -prices[0]
        # s1 = float('-inf')
        # s2 = float('-inf')
        # s3 = float('-inf')
        # s4 = float('-inf')
        # for i in range(len(prices)):
        #     s1 = max(s1, s0-prices[i])
        #     s2 = max(s2, s1+prices[i])
        #     s3 = max(s3, s2-prices[i])
        #     s4 = max(s4, s3+prices[i])
            # buy1 = min(buy1, prices[i])
            # sell1 = max(sell1, prices[i]-buy1)
            # buy2 = min(buy2, prices[i-sell1)
            # sell2 = max(sell2, prices[i]-buy2)
        # return max(0, s4)
        
        # if not prices:
        #     return 0
            
        # profits = []
        # max_profit = 0
        # cur_min = prices[0] 
        # for price in prices:
        #     cur_min = min(cur_min, price)
        #     max_profit = max(max_profit, price-cur_min)
        #     profits.append(max_profit)
        
        # total_max = 0
        # max_profit = 0
        # cur_max = prices[-1]
        # for i in range(len(prices)-1, -1, -1):
        #     cur_max = max(cur_max, prices[i])
        #     max_profit = max(max_profit, cur_max-prices[i])
        #     total_max = max(total_max, max_profit+profits[i])
        # return total_max

# @lc code=end

sol = Solution()
prices = [1,2,3,4,5]
print(sol.maxProfit(prices))