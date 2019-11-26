#
# @lc app=leetcode id=546 lang=python
#
# [546] Remove Boxes
#
# https://leetcode.com/problems/remove-boxes/description/
#
# algorithms
# Hard (39.67%)
# Likes:    449
# Dislikes: 42
# Total Accepted:    11.3K
# Total Submissions: 28.3K
# Testcase Example:  '[1,3,2,2,2,3,4,3,1]'
#
# Given several boxes with different colors represented by different positive
# numbers. 
# You may experience several rounds to remove boxes until there is no box left.
# Each time you can choose some continuous boxes with the same color (composed
# of k boxes, k >= 1), remove them and get k*k points.
# Find the maximum points you can get.
# 
# 
# Example 1:
# Input: 
# 
# [1, 3, 2, 2, 2, 3, 4, 3, 1]
# 
# Output:
# 
# 23
# 
# Explanation: 
# 
# [1, 3, 2, 2, 2, 3, 4, 3, 1] 
# ----> [1, 3, 3, 4, 3, 1] (3*3=9 points) 
# ----> [1, 3, 3, 3, 1] (1*1=1 points) 
# ----> [1, 1] (3*3=9 points) 
# ----> [] (2*2=4 points)
# 
# 
# 
# Note:
# The number of boxes n would not exceed 100.
# 
# 
#

# @lc code=start
class Solution(object):
    def removeBoxes(self, boxes):
        """
        :type boxes: List[int]
        :rtype: int
        """
        n = len(boxes)
        dp = [[[0 for _ in range(n)] for _ in range(n)] for _ in range(n)]
        return self.dfs(boxes, 0, n-1, 0, dp)
    
    def dfs(self, boxes, i, j, k, dp):
        if i>j:
            return 0
        if dp[i][j][k] > 0:
            return dp[i][j][k]
        
        res = (k+1)*(k+1) + self.dfs(boxes, i+1, j, 0, dp)
        
        for m in range(i+1, j+1):
            if boxes[i] == boxes[m]:
                res = max(res, self.dfs(boxes, i+1, m-1, 0, dp)+self.dfs(boxes, m, j, k+1, dp))
        dp[i][j][k] = res
        return res
    
# @lc code=end

