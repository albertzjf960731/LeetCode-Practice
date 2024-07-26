#
# @lc app=leetcode id=475 lang=python3
#
# [475] Heaters
#
# https://leetcode.com/problems/heaters/description/
#
# algorithms
# Medium (38.21%)
# Likes:    2101
# Dislikes: 1164
# Total Accepted:    121.4K
# Total Submissions: 317.8K
# Testcase Example:  '[1,2,3]\n[2]'
#
# Winter is coming! During the contest, your first job is to design a standard
# heater with a fixed warm radius to warm all the houses.
# 
# Every house can be warmed, as long as the house is within the heater's warm
# radius range. 
# 
# Given the positions of houses and heaters on a horizontal line, return the
# minimum radius standard of heaters so that those heaters could cover all
# houses.
# 
# Notice that all the heaters follow your radius standard, and the warm radius
# will the same.
# 
# 
# Example 1:
# 
# 
# Input: houses = [1,2,3], heaters = [2]
# Output: 1
# Explanation: The only heater was placed in the position 2, and if we use the
# radius 1 standard, then all the houses can be warmed.
# 
# 
# Example 2:
# 
# 
# Input: houses = [1,2,3,4], heaters = [1,4]
# Output: 1
# Explanation: The two heaters were placed at positions 1 and 4. We need to use
# a radius 1 standard, then all the houses can be warmed.
# 
# 
# Example 3:
# 
# 
# Input: houses = [1,5], heaters = [2]
# Output: 3
# 
# 
# 
# Constraints:
# 
# 
# 1 <= houses.length, heaters.length <= 3 * 10^4
# 1 <= houses[i], heaters[i] <= 10^9
# 
# 
#

# @lc code=start
class Solution:
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        houses.sort()
        heaters.sort()

        dp = [float('inf')] * len(houses)
        idx1, idx2 = 0, 0
        while idx1 < len(houses) and idx2 < len(heaters):
            if houses[idx1] <= heaters[idx2]:
                dp[idx1] = heaters[idx2] - houses[idx1]
                idx1 += 1
            else:
                idx2 += 1
        idx1, idx2 = len(houses)-1, len(heaters)-1
        while idx1 >=0 and idx2 >= 0:
            if houses[idx1] >= heaters[idx2]:
                dp[idx1] = min(dp[idx1], houses[idx1] - heaters[idx2])
                idx1 -= 1
            else:
                idx2 -= 1
        return max(dp)

        ans = 0
        idx = 0
        for h in houses:
            while idx+1 < len(heaters) and abs(heaters[idx] - h) >= abs(heaters[idx+1] - h):
                idx += 1
            ans = max(ans, abs(heaters[idx] - h))
        return ans
# @lc code=end

