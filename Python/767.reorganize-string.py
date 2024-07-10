#
# @lc app=leetcode id=767 lang=python3
#
# [767] Reorganize String
#
# https://leetcode.com/problems/reorganize-string/description/
#
# algorithms
# Medium (54.63%)
# Likes:    8472
# Dislikes: 253
# Total Accepted:    401.6K
# Total Submissions: 733.5K
# Testcase Example:  '"aab"'
#
# Given a string s, rearrange the characters of s so that any two adjacent
# characters are not the same.
# 
# Return any possible rearrangement of s or return "" if not possible.
# 
# 
# Example 1:
# Input: s = "aab"
# Output: "aba"
# Example 2:
# Input: s = "aaab"
# Output: ""
# 
# 
# Constraints:
# 
# 
# 1 <= s.length <= 500
# s consists of lowercase English letters.
# 
# 
#

import collections
import heapq

# @lc code=start
class Solution:
    def reorganizeString(self, s: str) -> str:
        cnts = collections.Counter(s)
        pq = []
        for c, v in cnts.items():
            if v > (len(s) + 1) // 2:
                return ""
            heapq.heappush(pq, (-v, c))
        
        ans = ""
        while len(pq) >= 2:
            v1, c1 = heapq.heappop(pq)
            v2, c2 = heapq.heappop(pq)
            ans = ans + c1 + c2

            if v1 + 1 < 0:
                heapq.heappush(pq, (v1 + 1, c1))
            if v2 + 1 < 0:
                heapq.heappush(pq, (v2 + 1, c2))
        while pq:
            v, c = heapq.heappop(pq)
            ans += c
        return ans

# @lc code=end

