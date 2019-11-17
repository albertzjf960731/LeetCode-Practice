#
# @lc app=leetcode id=57 lang=python
#
# [57] Insert Interval
#
# https://leetcode.com/problems/insert-interval/description/
#
# algorithms
# Hard (32.02%)
# Likes:    1087
# Dislikes: 135
# Total Accepted:    203.1K
# Total Submissions: 634.2K
# Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
#
# Given a set of non-overlapping intervals, insert a new interval into the
# intervals (merge if necessary).
# 
# You may assume that the intervals were initially sorted according to their
# start times.
# 
# Example 1:
# 
# 
# Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
# Output: [[1,5],[6,9]]
# 
# 
# Example 2:
# 
# 
# Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
# Output: [[1,2],[3,10],[12,16]]
# Explanation: Because the new interval [4,8] overlaps with
# [3,5],[6,7],[8,10].
# 
# NOTE: input types have been changed on April 15, 2019. Please reset to
# default code definition to get new method signature.
# 
#

# @lc code=start
class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[List[int]]
        :type newInterval: List[int]
        :rtype: List[List[int]]
        """
        
        # intervals.append(newInterval)
        
        # intervals.sort()
        
        # i = 0
        # while i < len(intervals)-1:
        # # for i in range(len(intervals)-1):

        #     if intervals[i][1] >= intervals[i+1][0] and intervals[i][1] < intervals[i+1][1]:
        #         intervals[i+1][0] = intervals[i][0]
        #         intervals.pop(i)
        #     elif intervals[i][1] >= intervals[i+1][1]:
        #         intervals[i+1] = intervals[i]
        #         intervals.pop(i)
        #     else:
        #         i += 1
        # return intervals

        s, e = newInterval[0], newInterval[1]
        left = [i for i in intervals if i[1] < newInterval[0]]
        right = [i for i in intervals if i[0] > newInterval[1]]

        if left + right != intervals:
            s = min(newInterval[0], intervals[len(left)][0])
            e = max(newInterval[1], intervals[~len(right)][1])

        return left + [[s, e]] + right
# @lc code=end

sol = Solution()
intervals = [[1, 3], [6, 9]]
newInterval = [2, 5]
sol.insert(intervals, newInterval)