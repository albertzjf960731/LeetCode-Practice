#
# @lc app=leetcode id=38 lang=python
#
# [38] Count and Say
#
# https://leetcode.com/problems/count-and-say/description/
#
# algorithms
# Easy (42.12%)
# Likes:    939
# Dislikes: 7501
# Total Accepted:    328.4K
# Total Submissions: 778.9K
# Testcase Example:  '1'
#
# The count-and-say sequence is the sequence of integers with the first five
# terms as following:
# 
# 
# 1.     1
# 2.     11
# 3.     21
# 4.     1211
# 5.     111221
# 
# 
# 1 is read off as "one 1" or 11.
# 11 is read off as "two 1s" or 21.
# 21 is read off as "one 2, then one 1" or 1211.
# 
# Given an integer n where 1 ≤ n ≤ 30, generate the n^th term of the
# count-and-say sequence.
# 
# Note: Each term of the sequence of integers will be represented as a
# string.
# 
# 
# 
# Example 1:
# 
# 
# Input: 1
# Output: "1"
# 
# 
# Example 2:
# 
# 
# Input: 4
# Output: "1211"
# 
#

# @lc code=start
class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """


    #     res = '1'
    #     while n>1:
    #         res = self.helper(res)
    #         n -= 1
    #     return res 

    # def helper(self, s):
    #     # s = str(n)
    #     i = 0
    #     res = ''
    #     while i < len(s):
    #         if i < len(s)-1 and s[i] == s[i+1]:
    #             if s[i] == '1':
    #                 res += '21'
    #             else:
    #                 res += '22'
    #             i += 2
    #         else:
    #             if s[i] == '1':
    #                 res += '11'
    #             else:
    #                 res += '12'
    #             i += 1

    #     return res 
        res = '1'
        while n > 1:
            temp = ''
            i = 0
            while i < len(res):
                num = self.helper(res[i:])
                temp = temp + str(num) + '' + res[i]
                i = i + num
            n -= 1
            res = temp
        return res
    def helper(self, s):
        count = 1
        for i in range(1, len(s)):
            if s[i] == s[0]:
                count += 1
            else:
                break
        return count
# @lc code=end

sol = Solution()
print(sol.countAndSay(5))