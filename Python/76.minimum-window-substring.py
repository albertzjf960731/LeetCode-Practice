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
        
        from collections import Counter
        count_t = Counter(t)

        ans_l, ans_r = 0, -1
        ans_len = len(s)+1
        missing = len(t)

        l, r = 0, 0
        while r<len(s):
            c_r = s[r]

            missing -= count_t[c_r] > 0
            count_t[c_r] -= 1

            while missing == 0:

                temp_len = r-l+1
                if temp_len < ans_len:
                    ans_l, ans_r = l, r
                    ans_len = temp_len

                c_l = s[l]
                count_t[c_l] += 1
                if count_t[c_l] > 0:
                    missing += 1   
                l += 1
                
            r += 1
        return s[ans_l: ans_r+1]


# @lc code=end
sol = Solution()
# s = 'ADOBECODEBANC'
# t = 'ABC'
s = 'a' 
t = 'a'
print(sol.minWindow(s, t))
