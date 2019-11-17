#
# @lc app=leetcode id=22 lang=python
#
# [22] Generate Parentheses
#
# https://leetcode.com/problems/generate-parentheses/description/
#
# algorithms
# Medium (57.74%)
# Likes:    3503
# Dislikes: 206
# Total Accepted:    414K
# Total Submissions: 716.1K
# Testcase Example:  '3'
#
# 
# Given n pairs of parentheses, write a function to generate all combinations
# of well-formed parentheses.
# 
# 
# 
# For example, given n = 3, a solution set is:
# 
# 
# [
# ⁠ "((()))",
# ⁠ "(()())",
# ⁠ "(())()",
# ⁠ "()(())",
# ⁠ "()()()"
# ]
# 
#

# @lc code=start
class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """

        # res = []
        # if n == 0:
        #     res.append('')
        # else:
        #     for i in range(n):
        #         left = self.generateParenthesis(i)
        #         right = self.generateParenthesis(n-1-i)
        #         for l in left:
        #             for r in right:
        #                 res.append('('+l+')'+ r)
        # return res


        # 回溯
        res = []
        self.helper(n, n, res, '')
        return res
    def helper(self, left, right, res, path):
        if left:
            self.helper(left-1, right, res, path+'(')
        if right>left:
            self.helper(left, right-1, res, path+')')
        if not right:
            res.append(path) 
        return res

# @lc code=end

sol = Solution()
n = 3
print(sol.generateParenthesis(3))
