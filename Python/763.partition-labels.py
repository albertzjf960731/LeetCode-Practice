#
# @lc app=leetcode id=763 lang=python
#
# [763] Partition Labels
#
# https://leetcode.com/problems/partition-labels/description/
#
# algorithms
# Medium (72.66%)
# Likes:    1389
# Dislikes: 76
# Total Accepted:    77.6K
# Total Submissions: 106.5K
# Testcase Example:  '"ababcbacadefegdehijhklij"'
#
# 
# A string S of lowercase letters is given.  We want to partition this string
# into as many parts as possible so that each letter appears in at most one
# part, and return a list of integers representing the size of these parts.
# 
# 
# Example 1:
# 
# Input: S = "ababcbacadefegdehijhklij"
# Output: [9,7,8]
# Explanation:
# The partition is "ababcbaca", "defegde", "hijhklij".
# This is a partition so that each letter appears in at most one part.
# A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it
# splits S into less parts.
# 
# 
# 
# Note:
# S will have length in range [1, 500].
# S will consist of lowercase letters ('a' to 'z') only.
# 
#

# @lc code=start
class Solution(object):
    def partitionLabels(self, s):
        """
        :type S: str
        :rtype: List[int]
        """
        # bucket = [i for i in range(len(s))]
        # hash_dict = dict()
        # for i in range(len(s)):
        #     if s[i] not in hash_dict:
        #         hash_dict[s[i]] = len(hash_dict)
        #     else:
                

        # for i in range(len) 要比 enumerate 快 
        
        res = []
        count = 0

        max_pos = dict()
        # for i, ch in enumerate(s):
        for i in range(len(s)):
            max_pos[s[i]] = i
        # max_pos = {c: i for i, c in enumerate(s)}

        pos = 0
        # for i, ch in enumerate(s):
        for i in range(len(s)):
            pos = max(pos, max_pos[s[i]])
            count += 1

            if i == pos:
                res.append(count)
                count = 0
        return res

        # res = []
        # while s:
        #     i = 1
        #     while set(s[:i]) & set(s[i:]):
        #         i += 1
        #     res.append(i)
        #     s = s[i:]
        # return res

# @lc code=end

