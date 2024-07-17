#
# @lc app=leetcode id=76 lang=python
#
# [76] Minimum Window Substring
#
# https://leetcode.com/problems/minimum-window-substring/description/
#
# algorithms
# Hard (32.34%)
# Likes:    2978
# Dislikes: 213
# Total Accepted:    292.5K
# Total Submissions: 904.2K
# Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
#
# Given a string S and a string T, find the minimum window in S which will
# contain all the characters in T in complexity O(n).
# 
# Example:
# 
# 
# Input: S = "ADOBECODEBANC", T = "ABC"
# Output: "BANC"
# 
# 
# Note:
# 
# 
# If there is no such window in S that covers all characters in T, return the
# empty string "".
# If there is such window, you are guaranteed that there will always be only
# one unique minimum window in S.
# 
# 
#

# @lc code=start
class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """

        t_cnts = collections.Counter(t) 
        needed = len(t)

        min_len = float('inf')
        min_str = ""

        left, right = 0, 0
        while right < len(s):
            if t_cnts[s[right]] > 0:
                needed -= 1
            t_cnts[s[right]] -= 1 # t_cnts[s[right]] < 0 means s[right] is not needed

            while needed == 0:
                if right - left + 1 < min_len:
                    min_len = right - left + 1
                    min_str = s[left: right+1]
                    
                t_cnts[s[left]] += 1
                if t_cnts[s[left]] > 0:
                    needed += 1
                left += 1
            right += 1

        return min_str

# @lc code=end
sol = Solution()
# s = 'ADOBECODEBANC'
# t = 'ABC'
s = 'a' 
t = 'a'
print(sol.minWindow(s, t))
