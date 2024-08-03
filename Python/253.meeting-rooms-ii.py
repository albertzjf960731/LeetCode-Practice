#
# @lc app=leetcode id=253 lang=python3
#
# [253] Meeting Rooms II
#
# https://leetcode.com/problems/meeting-rooms-ii/description/
#
# algorithms
# Medium (51.31%)
# Likes:    6934
# Dislikes: 159
# Total Accepted:    907.8K
# Total Submissions: 1.8M
# Testcase Example:  '[[0,30],[5,10],[15,20]]'
#
# Given an array of meeting time intervals intervals where intervals[i] =
# [starti, endi], return the minimum number of conference rooms required.
# 
# 
# Example 1:
# Input: intervals = [[0,30],[5,10],[15,20]]
# Output: 2
# Example 2:
# Input: intervals = [[7,10],[2,4]]
# Output: 1
# 
# 
# Constraints:
# 
# 
# 1 <= intervals.length <= 10^4
# 0 <= starti < endi <= 10^6
# 
# 
#

# @lc code=start
class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        # sweep line
        # add events to a list rather than updating the events array in place
        events = []
        for start, end in intervals:
            events.append((start, 1))
            events.append((end, -1))
        events.sort()

        ans = 0
        cnt = 0
        for _, delta in events:
            cnt += delta
            ans = max(ans, cnt)
        return ans
# @lc code=end

