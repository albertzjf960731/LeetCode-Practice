#
# @lc app=leetcode id=1208 lang=python3
#
# [1208] Get Equal Substrings Within Budget
#
# https://leetcode.com/problems/get-equal-substrings-within-budget/description/
#
# algorithms
# Medium (51.28%)
# Likes:    1499
# Dislikes: 107
# Total Accepted:    102.3K
# Total Submissions: 183.2K
# Testcase Example:  '"abcd"\n"bcdf"\n3'
#
# You are given two strings s and t of the same length and an integer maxCost.
# 
# You want to change s to t. Changing the i^th character of s to i^th character
# of t costs |s[i] - t[i]| (i.e., the absolute difference between the ASCII
# values of the characters).
# 
# Return the maximum length of a substring of s that can be changed to be the
# same as the corresponding substring of t with a cost less than or equal to
# maxCost. If there is no substring from s that can be changed to its
# corresponding substring from t, return 0.
# 
# 
# Example 1:
# 
# 
# Input: s = "abcd", t = "bcdf", maxCost = 3
# Output: 3
# Explanation: "abc" of s can change to "bcd".
# That costs 3, so the maximum length is 3.
# 
# 
# Example 2:
# 
# 
# Input: s = "abcd", t = "cdef", maxCost = 3
# Output: 1
# Explanation: Each character in s costs 2 to change to character in t,  so the
# maximum length is 1.
# 
# 
# Example 3:
# 
# 
# Input: s = "abcd", t = "acde", maxCost = 0
# Output: 1
# Explanation: You cannot make any change, so the maximum length is 1.
# 
# 
# 
# Constraints:
# 
# 
# 1 <= s.length <= 10^5
# t.length == s.length
# 0 <= maxCost <= 10^6
# s and t consist of only lowercase English letters.
# 
# 
#

# @lc code=start
class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:    
        nums = [abs(ord(s[i]) - ord(t[i])) for i in range(len(s))]

        left, right = 0, 0
        cost = 0
        ans = 0
        while right < len(s):
            cost += nums[right]
            while cost > maxCost:
                cost -= nums[left]
                left += 1
            ans = max(ans, right - left + 1)
            right += 1
        return ans


        
# @lc code=end

