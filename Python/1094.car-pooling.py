#
# @lc app=leetcode id=1094 lang=python3
#
# [1094] Car Pooling
#
# https://leetcode.com/problems/car-pooling/description/
#
# algorithms
# Medium (56.07%)
# Likes:    4438
# Dislikes: 99
# Total Accepted:    224.2K
# Total Submissions: 400.4K
# Testcase Example:  '[[2,1,5],[3,3,7]]\n4'
#
# There is a car with capacity empty seats. The vehicle only drives east (i.e.,
# it cannot turn around and drive west).
# 
# You are given the integer capacity and an array trips where trips[i] =
# [numPassengersi, fromi, toi] indicates that the i^th trip has numPassengersi
# passengers and the locations to pick them up and drop them off are fromi and
# toi respectively. The locations are given as the number of kilometers due
# east from the car's initial location.
# 
# Return true if it is possible to pick up and drop off all passengers for all
# the given trips, or false otherwise.
# 
# 
# Example 1:
# 
# 
# Input: trips = [[2,1,5],[3,3,7]], capacity = 4
# Output: false
# 
# 
# Example 2:
# 
# 
# Input: trips = [[2,1,5],[3,3,7]], capacity = 5
# Output: true
# 
# 
# 
# Constraints:
# 
# 
# 1 <= trips.length <= 1000
# trips[i].length == 3
# 1 <= numPassengersi <= 100
# 0 <= fromi < toi <= 1000
# 1 <= capacity <= 10^5
# 
# 
#

# @lc code=start
class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        # sweep line
        events = [0] * 1001
        for num, start, end in trips:
            events[start] += num
            events[end] -= num
        cnt = 0
        for num in events:
            cnt += num
            if cnt > capacity:
                return False
        return True
# @lc code=end

