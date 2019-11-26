#
# @lc app=leetcode.cn id=344 lang=python
#
# [344] Reverse String
#

# @lc code=start
class Solution(object):
    def reverseString(self, s):
        """
        :type s: List[str]
        :rtype: None Do not return anything, modify s in-place instead.
        """
        l, r = 0, len(s)-1
        while l<r:
            s[l], s[r] = s[r], s[l]
            
            l+=1
            r-=1
            
# @lc code=end

