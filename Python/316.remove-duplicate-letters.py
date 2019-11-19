#
# @lc app=leetcode id=316 lang=python
#
# [316] Remove Duplicate Letters
#
# https://leetcode.com/problems/remove-duplicate-letters/description/
#
# algorithms
# Hard (33.69%)
# Likes:    933
# Dislikes: 87
# Total Accepted:    65K
# Total Submissions: 192.9K
# Testcase Example:  '"bcabc"'
#
# Given a string which contains only lowercase letters, remove duplicate
# letters so that every letter appears once and only once. You must make sure
# your result is the smallest in lexicographical order among all possible
# results.
# 
# Example 1:
# 
# 
# Input: "bcabc"
# Output: "abc"
# 
# 
# Example 2:
# 
# 
# Input: "cbacdcbc"
# Output: "acdb"
# 
# 
#

# @lc code=start
from heapq import *
class Solution(object):
    def removeDuplicateLetters(self, s):
        """
        :type s: str
        :rtype: str
        """
        # min_heap = []
        # for c in s:
        #     # item = (ord(c)-97, c)
        #     if c not in min_heap:
        #         heappush(min_heap, c)
            
        #         # heappush(min_heap, (matrix[i][0], 0, matrix[i]))
        # res = ''
        # while min_heap:
        #     res += heappop(min_heap)
        # return res 

        # keep the relative positiion 
        pos = {c: i for i, c in enumerate(s)}
        stack = []
        for i, c in enumerate(s):
            if c not in stack:
                while stack and c < stack[-1] and i < pos[stack[-1]]:
                    stack.pop()
                stack.append(c)
        return ''.join(stack)

        # 厉害啊 [-1] -> [-1:]
        # rindex = {c: i for i, c in enumerate(s)}
        # result = ''
        # for i, c in enumerate(s):
        #     if c not in result:
        #         while c < result[-1:] and i < rindex[result[-1]]:
        #             result = result[:-1]
        #         result += c
        # return result

# @lc code=end

sol = Solution()
s = 'cbacdcbc'
print(sol.removeDuplicateLetters(s))