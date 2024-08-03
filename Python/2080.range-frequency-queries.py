#
# @lc app=leetcode id=2080 lang=python3
#
# [2080] Range Frequency Queries
#
# https://leetcode.com/problems/range-frequency-queries/description/
#
# algorithms
# Medium (40.17%)
# Likes:    656
# Dislikes: 27
# Total Accepted:    21.8K
# Total Submissions: 54K
# Testcase Example:  '["RangeFreqQuery","query","query"]\n' +
#   '[[[12,33,4,56,22,2,34,33,22,12,34,56]],[1,2,4],[0,11,33]]'
#
# Design a data structure to find the frequency of a given value in a given
# subarray.
# 
# The frequency of a value in a subarray is the number of occurrences of that
# value in the subarray.
# 
# Implement the RangeFreqQuery class:
# 
# 
# RangeFreqQuery(int[] arr) Constructs an instance of the class with the given
# 0-indexed integer array arr.
# int query(int left, int right, int value) Returns the frequency of value in
# the subarray arr[left...right].
# 
# 
# A subarray is a contiguous sequence of elements within an array.
# arr[left...right] denotes the subarray that contains the elements of nums
# between indices left and right (inclusive).
# 
# 
# Example 1:
# 
# 
# Input
# ["RangeFreqQuery", "query", "query"]
# [[[12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56]], [1, 2, 4], [0, 11, 33]]
# Output
# [null, 1, 2]
# 
# Explanation
# RangeFreqQuery rangeFreqQuery = new RangeFreqQuery([12, 33, 4, 56, 22, 2, 34,
# 33, 22, 12, 34, 56]);
# rangeFreqQuery.query(1, 2, 4); // return 1. The value 4 occurs 1 time in the
# subarray [33, 4]
# rangeFreqQuery.query(0, 11, 33); // return 2. The value 33 occurs 2 times in
# the whole array.
# 
# 
# 
# Constraints:
# 
# 
# 1 <= arr.length <= 10^5
# 1 <= arr[i], value <= 10^4
# 0 <= left <= right < arr.length
# At most 10^5 calls will be made to query
# 
# 
#
import bisect
from collections import defaultdict

# @lc code=start
class RangeFreqQuery:

    def __init__(self, arr: List[int]):
        self.num2idx = defaultdict(list)
        for i, num in enumerate(arr):
            self.num2idx[num].append(i)

    def query(self, left: int, right: int, value: int) -> int:
        if value not in self.num2idx:
            return 0
        idxs = self.num2idx[value]
        # left_idx = bisect_left(idxs, left)
        # right_idx = bisect_right(idxs, right)
        
        l, r = 0, len(idxs) - 1
        while l < r:
            mid = l + (r - l) // 2
            if idxs[mid] < left:
                l = mid + 1
            else:
                r = mid
        left_idx = l
        if idxs[left_idx] < left:
            return 0
        
        # idxs[i] 
        l, r = 0, len(idxs) - 1
        while l < r:
            mid = r - (r - l) // 2
            if idxs[mid] <= right:
                l = mid
            else:
                r = mid - 1
        right_idx = r
        if idxs[right_idx] > right:
            return 0
        return right_idx - left_idx + 1


# Your RangeFreqQuery object will be instantiated and called as such:
# obj = RangeFreqQuery(arr)
# param_1 = obj.query(left,right,value)
# @lc code=end

