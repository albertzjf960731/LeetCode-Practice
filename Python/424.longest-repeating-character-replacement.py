#
# @lc app=leetcode id=424 lang=python3
#
# [424] Longest Repeating Character Replacement
#
# https://leetcode.com/problems/longest-repeating-character-replacement/description/
#
# algorithms
# Medium (54.00%)
# Likes:    10591
# Dislikes: 516
# Total Accepted:    774.8K
# Total Submissions: 1.4M
# Testcase Example:  '"ABAB"\n2'
#
# You are given a string s and an integer k. You can choose any character of
# the string and change it to any other uppercase English character. You can
# perform this operation at most k times.
# 
# Return the length of the longest substring containing the same letter you can
# get after performing the above operations.
# 
# 
# Example 1:
# 
# 
# Input: s = "ABAB", k = 2
# Output: 4
# Explanation: Replace the two 'A's with two 'B's or vice versa.
# 
# 
# Example 2:
# 
# 
# Input: s = "AABABBA", k = 1
# Output: 4
# Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
# The substring "BBBB" has the longest repeating letters, which is 4.
# There may exists other ways to achieve this answer too.
# 
# 
# Constraints:
# 
# 
# 1 <= s.length <= 10^5
# s consists of only uppercase English letters.
# 0 <= k <= s.length
# 
# 
#

# @lc code=start
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        left, right = 0, 0
        hmap = dict()
        ans = 0
        while right < len(s):
            hmap[s[right]] = hmap.get(s[right], 0) + 1
            
            while right - left + 1 - max(hmap.values()) > k:
                hmap[s[left]] -= 1
                left += 1
            
            ans = max(ans, right - left + 1)
            right += 1
        return ans
# @lc code=end

