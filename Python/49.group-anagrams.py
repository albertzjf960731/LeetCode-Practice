#
# @lc app=leetcode id=49 lang=python
#
# [49] Group Anagrams
#
# https://leetcode.com/problems/group-anagrams/description/
#
# algorithms
# Medium (50.36%)
# Likes:    2176
# Dislikes: 134
# Total Accepted:    427.4K
# Total Submissions: 847K
# Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
#
# Given an array of strings, group anagrams together.
# 
# Example:
# 
# 
# Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
# Output:
# [
# ⁠ ["ate","eat","tea"],
# ⁠ ["nat","tan"],
# ⁠ ["bat"]
# ]
# 
# Note:
# 
# 
# All inputs will be in lowercase.
# The order of your output does not matter.
# 
# 
#

# @lc code=start
class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        dic = dict()

        for s in strs:
            s_sort = ''.join(
                (lambda x: (x.sort(), x)[1])
                (list(s))
                )
            if s_sort not in dic:
                dic[s_sort] = []
            dic[s_sort].append(s)
            
        return [ v for _, v in dic.items()]
        
# @lc code=end

sol = Solution()
strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
print(sol.groupAnagrams(strs))