#
# @lc app=leetcode id=871 lang=python3
#
# [871] Minimum Number of Refueling Stops
#
# https://leetcode.com/problems/minimum-number-of-refueling-stops/description/
#
# algorithms
# Hard (40.07%)
# Likes:    4664
# Dislikes: 89
# Total Accepted:    139.2K
# Total Submissions: 347.4K
# Testcase Example:  '1\n1\n[]'
#
# A car travels from a starting position to a destination which is target miles
# east of the starting position.
# 
# There are gas stations along the way. The gas stations are represented as an
# array stations where stations[i] = [positioni, fueli] indicates that the i^th
# gas station is positioni miles east of the starting position and has fueli
# liters of gas.
# 
# The car starts with an infinite tank of gas, which initially has startFuel
# liters of fuel in it. It uses one liter of gas per one mile that it drives.
# When the car reaches a gas station, it may stop and refuel, transferring all
# the gas from the station into the car.
# 
# Return the minimum number of refueling stops the car must make in order to
# reach its destination. If it cannot reach the destination, return -1.
# 
# Note that if the car reaches a gas station with 0 fuel left, the car can
# still refuel there. If the car reaches the destination with 0 fuel left, it
# is still considered to have arrived.
# 
# 
# Example 1:
# 
# 
# Input: target = 1, startFuel = 1, stations = []
# Output: 0
# Explanation: We can reach the target without refueling.
# 
# 
# Example 2:
# 
# 
# Input: target = 100, startFuel = 1, stations = [[10,100]]
# Output: -1
# Explanation: We can not reach the target (or even the first gas station).
# 
# 
# Example 3:
# 
# 
# Input: target = 100, startFuel = 10, stations =
# [[10,60],[20,30],[30,30],[60,40]]
# Output: 2
# Explanation: We start with 10 liters of fuel.
# We drive to position 10, expending 10 liters of fuel.  We refuel from 0
# liters to 60 liters of gas.
# Then, we drive from position 10 to position 60 (expending 50 liters of fuel),
# and refuel from 10 liters to 50 liters of gas.  We then drive to and reach
# the target.
# We made 2 refueling stops along the way, so we return 2.
# 
# 
# 
# Constraints:
# 
# 
# 1 <= target, startFuel <= 10^9
# 0 <= stations.length <= 500
# 1 <= positioni < positioni+1 < target
# 1 <= fueli < 10^9
# 
# 
#

# @lc code=start
class Solution:
    def minRefuelStops(self, target: int, startFuel: int, stations: List[List[int]]) -> int:
        pq = []

        fuel = startFuel
        idx = 0
        ans = 0
        while fuel < target:
            while idx < len(stations) and fuel >= stations[idx][0]:
                heapq.heappush(pq, -(stations[idx][1]))
                idx += 1
            
            if not pq:
                return -1
            fuel += (-heapq.heappop(pq))
            ans += 1
        return ans

        fuel = startFuel
        ans = 0
        pq = []
        for stop in stations:
            if (fuel >= target):
                break
            while pq and fuel < stop[0]:
                fuel += (-heapq.heappop(pq))
                ans += 1
            if fuel < stop[0]:
                return -1
            heapq.heappush(pq, -stop[1])
        
        while fuel < target:
            if not pq:
                return -1
            fuel += (-heapq.heappop(pq))
            ans += 1
        return ans if fuel >= target else -1

# @lc code=end

