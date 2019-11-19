#
# @lc app=leetcode id=402 lang=python
#
# [402] Remove K Digits
#
# https://leetcode.com/problems/remove-k-digits/description/
#
# algorithms
# Medium (27.13%)
# Likes:    1204
# Dislikes: 71
# Total Accepted:    77.2K
# Total Submissions: 284.2K
# Testcase Example:  '"1432219"\n3'
#
# Given a non-negative integer num represented as a string, remove k digits
# from the number so that the new number is the smallest possible.
# 
# 
# Note:
# 
# The length of num is less than 10002 and will be ≥ k.
# The given num does not contain any leading zero.
# 
# 
# 
# 
# Example 1:
# 
# Input: num = "1432219", k = 3
# Output: "1219"
# Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219
# which is the smallest.
# 
# 
# 
# Example 2:
# 
# Input: num = "10200", k = 1
# Output: "200"
# Explanation: Remove the leading 1 and the number is 200. Note that the output
# must not contain leading zeroes.
# 
# 
# 
# Example 3:
# 
# Input: num = "10", k = 2
# Output: "0"
# Explanation: Remove all the digits from the number and it is left with
# nothing which is 0.
# 
# 
#

# @lc code=start
class Solution(object):
    def removeKdigits(self, num, k):
        """
        :type num: str
        :type k: int
        :rtype: str
        """

        count = k
        stack = ['0']
        for c in num:
            while stack and count and c < stack[-1]:
                stack.pop()
                count -= 1
                # if count == k:
                #     return ''.join(stack)
            stack.append(c)

        for _ in range(count):
            stack.pop()
        
        # return str(int(''.join(stack)))
        return ''.join(stack).lstrip('0') or '0'

# @lc code=end

sol = Solution()
num = '9'
k = 1
print(sol.removeKdigits(num, k))