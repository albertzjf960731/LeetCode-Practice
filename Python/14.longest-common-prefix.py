#
# @lc app=leetcode id=14 lang=python
#
# [14] Longest Common Prefix
#
# https://leetcode.com/problems/longest-common-prefix/description/
#
# algorithms
# Easy (34.28%)
# Likes:    1684
# Dislikes: 1520
# Total Accepted:    569.1K
# Total Submissions: 1.7M
# Testcase Example:  '["flower","flow","flight"]'
#
# Write a function to find the longest common prefix string amongst an array of
# strings.
# 
# If there is no common prefix, return an empty string "".
# 
# Example 1:
# 
# 
# Input: ["flower","flow","flight"]
# Output: "fl"
# 
# 
# Example 2:
# 
# 
# Input: ["dog","racecar","car"]
# Output: ""
# Explanation: There is no common prefix among the input strings.
# 
# 
# Note:
# 
# All given inputs are in lowercase letters a-z.
# 
#

# @lc code=start
class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """

        # sz = zip(*strs)
        # res = ''
        # for c in sz:
        #     if len(set(c)) > 1: 
        #          break
        #     res += c[0]
        # return res

        if len(strs) == 0:
            return ''

        min_len = float('inf')
        for string in strs:
            if len(string) < min_len:
                min_len = len(string)

        long_common_prefix = ''
        for i in range(min_len):
            if self.str_equ(strs, i):
                long_common_prefix += strs[0][i] 
            else:
                break
        return long_common_prefix
    
    def str_equ(self, strs, index):
        temp = strs[0][index]

        for string in strs[1:]:
            if string[index] != temp:
                return False
        return True


# @lc code=end

strs = ["aa","a"]
s = Solution()
s.longestCommonPrefix(strs)