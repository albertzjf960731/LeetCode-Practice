#
# @lc app=leetcode id=1653 lang=python3
#
# [1653] Minimum Deletions to Make String Balanced
#
# https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description/
#
# algorithms
# Medium (58.74%)
# Likes:    1474
# Dislikes: 45
# Total Accepted:    62.5K
# Total Submissions: 102K
# Testcase Example:  '"aababbab"'
#
# You are given a string s consisting only of characters 'a' and 'b'​​​​.
# 
# You can delete any number of characters in s to make s balanced. s is
# balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b'
# and s[j]= 'a'.
# 
# Return the minimum number of deletions needed to make s balanced.
# 
# 
# Example 1:
# 
# 
# Input: s = "aababbab"
# Output: 2
# Explanation: You can either:
# Delete the characters at 0-indexed positions 2 and 6 ("aababbab" ->
# "aaabbb"), or
# Delete the characters at 0-indexed positions 3 and 6 ("aababbab" ->
# "aabbbb").
# 
# 
# Example 2:
# 
# 
# Input: s = "bbaaaaabb"
# Output: 2
# Explanation: The only solution is to delete the first two characters.
# 
# 
# 
# Constraints:
# 
# 
# 1 <= s.length <= 10^5
# s[i] is 'a' or 'b'​​.
# 
# 
#

# @lc code=start
class Solution:
    def minimumDeletions(self, s: str) -> int:
        n = len(s)
        count_a = [0] * (n + 1)
        count_b = [0] * (n + 1)
        for i in range(1, n + 1):
            count_a[i] = count_a[i - 1] + (s[i - 1] == 'a')
        for i in range(n - 1, -1, -1):
            count_b[i] = count_b[i + 1] + (s[i] == 'b')

        ans = float('inf')
        for i in range(n + 1):
            ans = min(ans, count_b[i] + count_a[i])
        return ans
    
        stack = []
        ans = 0
        for c in s:
            if stack and c == 'a' and stack[-1] == 'b':
                stack.pop()
                ans += 1
            else:
                stack.append(c)
        return ans
# @lc code=end

