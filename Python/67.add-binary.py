#
# @lc app=leetcode id=67 lang=python
#
# [67] Add Binary
#
# https://leetcode.com/problems/add-binary/description/
#
# algorithms
# Easy (41.11%)
# Likes:    1229
# Dislikes: 229
# Total Accepted:    356.5K
# Total Submissions: 865.6K
# Testcase Example:  '"11"\n"1"'
#
# Given two binary strings, return their sum (also a binary string).
# 
# The input strings are both non-empty and contains only characters 1 or 0.
# 
# Example 1:
# 
# 
# Input: a = "11", b = "1"
# Output: "100"
# 
# Example 2:
# 
# 
# Input: a = "1010", b = "1011"
# Output: "10101"
# 
#

# @lc code=start
class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        
        carry = 0
        i = len(a) - 1
        j = len(b) - 1
        c = []
        while i >=0 or j>=0 or carry:
            s = carry 
            if i>=0:
                s += int(a[i])
            if j>=0:
                s += int(b[j])
            # s = int(a[i]) + int(b[j]) + carry
            carry = s // 2
            s = s % 2

            c.insert(0, str(s))

            i -= 1
            j -= 1
        # while i >= 0:
        #     s = int(a[i]) + carry
        #     carry = s // 2
        #     s = s % 2

        #     c.insert(0, str(s))

        #     i -= 1
        
        # while j >= 0:
        #     s = int(b[j]) + carry
        #     carry = s // 2
        #     s = s % 2

        #     c.insert(0, str(s))

        #     j -= 1
        # if carry:
        #     c.insert(0, str(carry))


        return ''.join(c)
        
# @lc code=end

sol = Solution()
a = '11'
b = '1'
print(sol.addBinary(a, b))