#
# @lc app=leetcode id=451 lang=python
#
# [451] Sort Characters By Frequency
#
# https://leetcode.com/problems/sort-characters-by-frequency/description/
#
# algorithms
# Medium (57.69%)
# Likes:    894
# Dislikes: 82
# Total Accepted:    115.6K
# Total Submissions: 200K
# Testcase Example:  '"tree"'
#
# Given a string, sort it in decreasing order based on the frequency of
# characters.
# 
# Example 1:
# 
# Input:
# "tree"
# 
# Output:
# "eert"
# 
# Explanation:
# 'e' appears twice while 'r' and 't' both appear once.
# So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid
# answer.
# 
# 
# 
# Example 2:
# 
# Input:
# "cccaaa"
# 
# Output:
# "cccaaa"
# 
# Explanation:
# Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
# Note that "cacaca" is incorrect, as the same characters must be together.
# 
# 
# 
# Example 3:
# 
# Input:
# "Aabb"
# 
# Output:
# "bbAa"
# 
# Explanation:
# "bbaA" is also a valid answer, but "Aabb" is incorrect.
# Note that 'A' and 'a' are treated as two different characters.
# 
# 
#

# @lc code=start
class Solution(object):
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        num2counnt = dict()
        for c in s:
            if c not in num2counnt:
                num2counnt[c] = 0
            num2counnt[c] += 1
        
        count2num = dict()
        for num, count in num2counnt.items():
            if count not in count2num:
                count2num[count] = ''
            count2num[count] += num

        res = ''
        for count in range(len(s), -1, -1):
            if count in count2num:
                for num in count2num[count]:
                    res += num * count
        return res
        

        
# @lc code=end

sol = Solution()
s = 'tree'  
print(sol.frequencySort(s))