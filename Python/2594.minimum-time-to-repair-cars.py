#
# @lc app=leetcode id=2594 lang=python3
#
# [2594] Minimum Time to Repair Cars
#
# https://leetcode.com/problems/minimum-time-to-repair-cars/description/
#
# algorithms
# Medium (43.78%)
# Likes:    556
# Dislikes: 27
# Total Accepted:    15.9K
# Total Submissions: 36.2K
# Testcase Example:  '[4,2,3,1]\n10'
#
# You are given an integer array ranks representing the ranks of some
# mechanics. ranksi is the rank of the i^th mechanic. A mechanic with a rank r
# can repair n cars in r * n^2 minutes.
# 
# You are also given an integer cars representing the total number of cars
# waiting in the garage to be repaired.
# 
# Return the minimum time taken to repair all the cars.
# 
# Note: All the mechanics can repair the cars simultaneously.
# 
# 
# Example 1:
# 
# 
# Input: ranks = [4,2,3,1], cars = 10
# Output: 16
# Explanation: 
# - The first mechanic will repair two cars. The time required is 4 * 2 * 2 =
# 16 minutes.
# - The second mechanic will repair two cars. The time required is 2 * 2 * 2 =
# 8 minutes.
# - The third mechanic will repair two cars. The time required is 3 * 2 * 2 =
# 12 minutes.
# - The fourth mechanic will repair four cars. The time required is 1 * 4 * 4 =
# 16 minutes.
# It can be proved that the cars cannot be repaired in less than 16
# minutes.​​​​​
# 
# 
# Example 2:
# 
# 
# Input: ranks = [5,1,8], cars = 6
# Output: 16
# Explanation: 
# - The first mechanic will repair one car. The time required is 5 * 1 * 1 = 5
# minutes.
# - The second mechanic will repair four cars. The time required is 1 * 4 * 4 =
# 16 minutes.
# - The third mechanic will repair one car. The time required is 8 * 1 * 1 = 8
# minutes.
# It can be proved that the cars cannot be repaired in less than 16
# minutes.​​​​​
# 
# 
# 
# Constraints:
# 
# 
# 1 <= ranks.length <= 10^5
# 1 <= ranks[i] <= 100
# 1 <= cars <= 10^6
# 
# 
#

# @lc code=start
class Solution:
    def repairCars(self, ranks: List[int], cars: int) -> int:
        
        left, right = 1, max(ranks) * cars * cars
        while left < right:
            mid = (left + right) // 2
            cnt = 0
            for r in ranks:
                cnt += mid // r
            if cnt < cars:
                left = mid + 1
            else:
                right = mid
        return left
    
# @lc code=end

