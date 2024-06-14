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

        ans = []
        self.dfs("", n, n, ans)
        return ans
        
    def dfs(cur, left, right, ans):
        if left == 0 and right == 0:
            ans.append(cur)
            return

        if left > 0:
            self.dfs(cur+'(', left-1, right, ans)

        if right>0 and right>left:
            self.dfs(cur+')', left, right-1, ans)

# @lc code=end

sol = Solution()
n = 3
print(sol.generateParenthesis(3))
