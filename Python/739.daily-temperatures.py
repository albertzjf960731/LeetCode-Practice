#
# @lc app=leetcode id=739 lang=python
#
# [739] Daily Temperatures
#
# https://leetcode.com/problems/daily-temperatures/description/
#
# algorithms
# Medium (61.03%)
# Likes:    1763
# Dislikes: 54
# Total Accepted:    102K
# Total Submissions: 166.7K
# Testcase Example:  '[73,74,75,71,69,72,76,73]'
#
# 
# Given a list of daily temperatures T, return a list such that, for each day
# in the input, tells you how many days you would have to wait until a warmer
# temperature.  If there is no future day for which this is possible, put 0
# instead.
# 
# For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76,
# 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].
# 
# 
# Note:
# The length of temperatures will be in the range [1, 30000].
# Each temperature will be an integer in the range [30, 100].
# 
#

# @lc code=start
class Solution(object):
    def dailyTemperatures(self, nums):
        """
        :type T: List[int]
        :rtype: List[int]
        """
        # res = []
        # for i in range(len(T)):
        #     j = i
        #     while j < len(T) and T[j] <= T[i]:
        #         j += 1
        #     res.append(j-i if j < len(T) else 0)
                    
        # return res         

        ans = [0] * len(nums)
        stack = []
        for i in range(len(nums)):
            while(stack and nums[i]>nums[stack[-1]]):
                idx = stack.pop()
                ans[idx] = i - idx
            stack.append(i)
        return ans

# @lc code=end

sol = Solution()
T = [73, 74, 75, 71, 69, 72, 76, 73]
print(sol.dailyTemperatures(T))