#
# @lc app=leetcode id=358 lang=python3
#
# [358] Rearrange String k Distance Apart
#
# https://leetcode.com/problems/rearrange-string-k-distance-apart/description/
#
# algorithms
# Hard (38.74%)
# Likes:    960
# Dislikes: 38
# Total Accepted:    65.3K
# Total Submissions: 167.9K
# Testcase Example:  '"aabbcc"\n3'
#
# Given a string s and an integer k, rearrange s such that the same characters
# are at least distance k from each other. If it is not possible to rearrange
# the string, return an empty string "".
# 
# 
# Example 1:
# 
# 
# Input: s = "aabbcc", k = 3
# Output: "abcabc"
# Explanation: The same letters are at least a distance of 3 from each other.
# 
# 
# Example 2:
# 
# 
# Input: s = "aaabc", k = 3
# Output: ""
# Explanation: It is not possible to rearrange the string.
# 
# 
# Example 3:
# 
# 
# Input: s = "aaadbbcc", k = 2
# Output: "abacabcd"
# Explanation: The same letters are at least a distance of 2 from each
# other.
# 
# 
# 
# Constraints:
# 
# 
# 1 <= s.length <= 3 * 10^5
# s consists of only lowercase English letters.
# 0 <= k <= s.length
# 
# 
#

# @lc code=start
class Solution:
    def rearrangeString(self, s: str, k: int) -> str:
        if k <= 1:
            return s
            
        cnts = collections.Counter(s)
        pq = []
        for ch, cnt in cnts.items():
            heapq.heappush(pq, (-cnt, ch))
        
        ans = ""
        last_idx = {}
        while pq:
            tmp = []
            for i in range(k):
                if not pq:
                    break
                cnt, ch = heapq.heappop(pq)
                if ch in last_idx and len(ans) - last_idx[ch] + 1 <= k:
                    return ""
                ans += ch
                last_idx[ch] = len(ans) - 1
                if cnt + 1 < 0:
                    tmp.append((cnt + 1, ch))
            for item in tmp:
                heapq.heappush(pq, item)
        return ans        
# @lc code=end

