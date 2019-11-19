#
# @lc app=leetcode id=56 lang=python
#
# [56] Merge Intervals
#
# https://leetcode.com/problems/merge-intervals/description/
#
# algorithms
# Medium (37.07%)
# Likes:    2734
# Dislikes: 217
# Total Accepted:    436.9K
# Total Submissions: 1.2M
# Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
#
# Given a collection of intervals, merge all overlapping intervals.
# 
# Example 1:
# 
# 
# Input: [[1,3],[2,6],[8,10],[15,18]]
# Output: [[1,6],[8,10],[15,18]]
# Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
# [1,6].
# 
# 
# Example 2:
# 
# 
# Input: [[1,4],[4,5]]
# Output: [[1,5]]
# Explanation: Intervals [1,4] and [4,5] are considered overlapping.
# 
# NOTE: input types have been changed on April 15, 2019. Please reset to
# default code definition to get new method signature.
# 
#

# @lc code=start
class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """

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

        res = []
        intervals.sort()

        for item in intervals:
            if res and item[0] <= res[-1][1]:
                res[-1][1] = max(res[-1][1], item[1])
            else:
                res.append(item)
                
        return res 
# @lc code=end

sol = Solution()
intervals = [[1, 4], [0, 1]]
print(sol.merge(intervals))