#
# @lc app=leetcode id=120 lang=python
#
# [120] Triangle
#
# https://leetcode.com/problems/triangle/description/
#
# algorithms
# Medium (41.22%)
# Likes:    1409
# Dislikes: 164
# Total Accepted:    208.4K
# Total Submissions: 504K
# Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
#
# Given a triangle, find the minimum path sum from top to bottom. Each step you
# may move to adjacent numbers on the row below.
# 
# For example, given the following triangle
# 
# 
# [
# ⁠    [2],
# ⁠   [3,4],
# ⁠  [6,5,7],
# ⁠ [4,1,8,3]
# ]
# 
# 
# The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
# 
# Note:
# 
# Bonus point if you are able to do this using only O(n) extra space, where n
# is the total number of rows in the triangle.
# 
#

# @lc code=start
class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        if not triangle:
            return 0

        dp = [0 for _ in range(len(triangle[-1]))]
        dp[0] = triangle[0][0]

        for i in range(1, len(triangle)):
            for j in range(i, -1, -1):
                if j == 0:
                    dp[j] = triangle[i][j] + dp[j]
                elif j == i:
                    dp[j] = triangle[i][j] + dp[j-1]
                else :
                    dp[j] = triangle[i][j] + min(dp[j-1], dp[j])
        return min(dp)
# @lc code=end

sol = Solution()
triangle = [
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
print(sol.minimumTotal(triangle))
