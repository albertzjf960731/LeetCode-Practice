#
# @lc app=leetcode id=32 lang=python
#
# [32] Longest Valid Parentheses
#
# https://leetcode.com/problems/longest-valid-parentheses/description/
#
# algorithms
# Hard (26.61%)
# Likes:    2438
# Dislikes: 110
# Total Accepted:    225.7K
# Total Submissions: 848.1K
# Testcase Example:  '"(()"'
#
# Given a string containing just the characters '(' and ')', find the length of
# the longest valid (well-formed) parentheses substring.
# 
# Example 1:
# 
# 
# Input: "(()"
# Output: 2
# Explanation: The longest valid parentheses substring is "()"
# 
# 
# Example 2:
# 
# 
# Input: ")()())"
# Output: 4
# Explanation: The longest valid parentheses substring is "()()"
# 
# 
#

# @lc code=start
class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        ans = 0
        dp = [0 for _ in range(len(s))]
        for i in range(1, len(s)):
            if s[i] == ')':
                if s[i-1] == '(':
                    dp[i] = dp[i-2] + 2

                elif i - dp[i-1] > 0 and s[i-dp[i-1]-1]=='(':
                    dp[i] = dp[i-1] + dp[i-dp[i-1]-2] + 2
            ans = max(ans, dp[i])
        return ans

        # 栈顶保存当前扫描的时候，合法序列前的一个位置位置下标是多少
        # ans = 0
        # stack = []
        # stack.append(-1)
        # for i in range(len(s)):
        #     if s[i] == '(':
        #         stack.append(i)
        #     else:
        #         stack.pop()
        #         if not stack:
        #             stack.append(i)
        #         else:
        #             ans = max(ans, i-stack[-1])     
        # return ans
# @lc code=end

sol = Solution()
s = "())((())))"
sol.longestValidParentheses(s)