#
# @lc app=leetcode id=17 lang=python
#
# [17] Letter Combinations of a Phone Number
#
# https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
#
# algorithms
# Medium (43.48%)
# Likes:    2740
# Dislikes: 345
# Total Accepted:    468.8K
# Total Submissions: 1.1M
# Testcase Example:  '"23"'
#
# Given a string containing digits from 2-9 inclusive, return all possible
# letter combinations that the number could represent.
# 
# A mapping of digit to letters (just like on the telephone buttons) is given
# below. Note that 1 does not map to any letters.
# 
# 
# 
# Example:
# 
# 
# Input: "23"
# Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
# 
# 
# Note:
# 
# Although the above answer is in lexicographical order, your answer could be
# in any order you want.
# 
#

# @lc code=start
class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        
        # digit2char = {
        #     '2': 'abc',
        #     '3': 'def',
        #     '4': 'ghi',
        #     '5': 'jkl',
        #     '6': 'mno',
        #     '7': 'pqrs',
        #     '8': 'tuv',
        #     '9': 'wxyz'
        # }

        # if len(digits) == 0:
        #     return []
        # if len(digits) == 1:
        #     return list(digit2char[digits[0]])
        
        # prev = self.letterCombinations(digits[:-1])
        # addintional = digit2char[digits[-1]]
        # return [s+c for s in prev for c in addintional]

        ans = []
        if not digits:
            return ans

        mapping = ["0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        ans.append('')
        for i in range(len(digits)):
            x = int(digits[i])
            while len(ans[0]) == i:
                t = ans.pop(0)
                for s in mapping[x]:
                    ans.append(t+s)
        return ans
# @lc code=end

sol = Solution()
digits = '23'
print(sol.letterCombinations(digits))