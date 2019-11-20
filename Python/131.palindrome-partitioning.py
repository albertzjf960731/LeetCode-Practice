#
# @lc app=leetcode id=131 lang=python
#
# [131] Palindrome Partitioning
#
# https://leetcode.com/problems/palindrome-partitioning/description/
#
# algorithms
# Medium (43.30%)
# Likes:    1221
# Dislikes: 49
# Total Accepted:    188.2K
# Total Submissions: 433.7K
# Testcase Example:  '"aab"'
#
# Given a string s, partition s such that every substring of the partition is a
# palindrome.
# 
# Return all possible palindrome partitioning of s.
# 
# Example:
# 
# 
# Input: "aab"
# Output:
# [
# ⁠ ["aa","b"],
# ⁠ ["a","a","b"]
# ]
# 
# 
#

# @lc code=start
class Solution(object):
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        res = []
        self.dfs(s, [], res)
        return res
    
    def dfs(self, s, path, res):
        if not s:
            res.append(path)
            return 

        for i in range(1, len(s)+1):
            if self.is_palindrome(s[:i]):     
                self.dfs(s[i:], path+[s[:i]], res)
    
    def is_palindrome(self, s):
        return s==s[::-1]
        

# @lc code=end

sol = Solution()
s = 'aba'
print(sol.partition(s))
