#
# @lc app=leetcode id=121 lang=python
#
# [121] Best Time to Buy and Sell Stock
#
# https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
#
# algorithms
# Easy (48.58%)
# Likes:    3357
# Dislikes: 151
# Total Accepted:    629.5K
# Total Submissions: 1.3M
# Testcase Example:  '[7,1,5,3,6,4]'
#
# Say you have an array for which the i^th element is the price of a given
# stock on day i.
# 
# If you were only permitted to complete at most one transaction (i.e., buy one
# and sell one share of the stock), design an algorithm to find the maximum
# profit.
# 
# Note that you cannot sell a stock before you buy one.
# 
# Example 1:
# 
# 
# Input: [7,1,5,3,6,4]
# Output: 5
# Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit =
# 6-1 = 5.
# Not 7-1 = 6, as selling price needs to be larger than buying price.
# 
# 
# Example 2:
# 
# 
# Input: [7,6,4,3,1]
# Output: 0
# Explanation: In this case, no transaction is done, i.e. max profit = 0.
# 
# 
#

# @lc code=start
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        # if not prices or len(prices)==1:
        #     return 0 

        # profit = [prices[i+1]-prices[i] for i in range(len(prices)-1)]

        # return max(self.max_subarray(profit), 0)

    # def max_subarray(self, nums):
    #     s, m = nums[0], nums[0]
    #     for num in nums[1:]:
    #         if s < 0:
    #             s = num
    #         else:
    #             s = s + num
    #         m = max(m, s)
    #     return m

        # if not prices or len(prices)==1:
        #     return 0 
            
        # sofar_min = prices[0]
        # max_profit = 0
        # for i in range(1, len(prices)):
        #     if sofar_min > prices[i]:
        #         sofar_min = prices[i]
        #     else:
        #         max_profit = max(max_profit, prices[i] - sofar_min)
        # return max_profit


        if not prices:
            return 0
            
        profits = []
        max_profit = 0
        cur_min = prices[0] 
        for price in prices:
            cur_min = min(cur_min, price)
            max_profit = max(max_profit, price-cur_min)
            # profits.append(max_profit)
        return max_profit

        # if not prices:
        #     return 0
        # s1 = -prices[0]
        # s2 = float('-inf')

        # for i in range(len(prices)):
        #     s1 = max(s1, -prices[i])
        #     s2 = max(s2, s1+prices[i])
        # return max(0, s2)
        
# @lc code=end

