#
# @lc app=leetcode id=198 lang=python
#
# [198] House Robber
#
# https://leetcode.com/problems/house-robber/description/
#
# algorithms
# Easy (41.42%)
# Likes:    3253
# Dislikes: 112
# Total Accepted:    394.5K
# Total Submissions: 951.9K
# Testcase Example:  '[1,2,3,1]'
#
# You are a professional robber planning to rob houses along a street. Each
# house has a certain amount of money stashed, the only constraint stopping you
# from robbing each of them is that adjacent houses have security system
# connected and it will automatically contact the police if two adjacent houses
# were broken into on the same night.
# 
# Given a list of non-negative integers representing the amount of money of
# each house, determine the maximum amount of money you can rob tonight without
# alerting the police.
# 
# Example 1:
# 
# 
# Input: [1,2,3,1]
# Output: 4
# Explanation: Rob house 1 (money = 1) and then rob house 3 (money =
# 3).
# Total amount you can rob = 1 + 3 = 4.
# 
# Example 2:
# 
# 
# Input: [2,7,9,3,1]
# Output: 12
# Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5
# (money = 1).
# Total amount you can rob = 2 + 9 + 1 = 12.
# 
# 
#

# @lc code=start
class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # dp 
        # last, now = 0, 0
        # for num in nums: 
        #     last, now = now, max(last +num, now)   
        # return now

        # 个人感觉和前面的Best Time to Buy and Sell Stock是同一类型的题目，都是在每个时间步有两种不同的状态，区别在于Stock题目两种状态之间必须相互转移，而Robber这道题状态转移不一定发生在两种状态之间。

        cur = 0
        pre1, pre2 = 0, 0 
        for num in nums:
            cur = max(pre2 + num, pre1)
            pre2, pre1 = pre1, cur
        return cur

# @lc code=end

sol = Solution()
nums = []
print(sol.rob(nums))