#
# @lc app=leetcode id=337 lang=python
#
# [337] House Robber III
#
# https://leetcode.com/problems/house-robber-iii/description/
#
# algorithms
# Medium (49.13%)
# Likes:    1886
# Dislikes: 38
# Total Accepted:    123.3K
# Total Submissions: 250.5K
# Testcase Example:  '[3,2,3,null,3,null,1]'
#
# The thief has found himself a new place for his thievery again. There is only
# one entrance to this area, called the "root." Besides the root, each house
# has one and only one parent house. After a tour, the smart thief realized
# that "all houses in this place forms a binary tree". It will automatically
# contact the police if two directly-linked houses were broken into on the same
# night.
# 
# Determine the maximum amount of money the thief can rob tonight without
# alerting the police.
# 
# Example 1:
# 
# 
# Input: [3,2,3,null,3,null,1]
# 
# ⁠    3
# ⁠   / \
# ⁠  2   3
# ⁠   \   \ 
# ⁠    3   1
# 
# Output: 7 
# Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
# 
# Example 2:
# 
# 
# Input: [3,4,5,1,3,null,1]
# 
# 3
# ⁠   / \
# ⁠  4   5
# ⁠ / \   \ 
# ⁠1   3   1
# 
# Output: 9
# Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
# 
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def rob(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        # if not root:
        #     return 0 
        # val1 = root.val 
        # if root.left:
        #     val1 += self.rob(root.left.left) + self.rob(root.left.right)
        # if root.right:
        #     val1 += self.rob(root.right.left) + self.rob(root.right.right)
        
        # val2 = self.rob(root.left) + self.rob(root.right)
        
        # return max(val1, val2)

        # In step I, we only considered the aspect of "optimal substructure", but think little about the possibilities of overlapping of the subproblems. For example, to obtain rob(root), we need rob(root.left), rob(root.right), rob(root.left.left), rob(root.left.right), rob(root.right.left), rob(root.right.right); but to get rob(root.left), we also need rob(root.left.left), rob(root.left.right), similarly for rob(root.right). The naive solution above computed these subproblems repeatedly, which resulted in bad time performance. Now if you recall the two conditions for dynamic programming (DP): "optimal substructure" + "overlapping of subproblems", we actually have a DP problem. A naive way to implement DP here is to use a hash map to record the results for visited subtrees.

        # 动态规划
    #     self.hash_dict = {}
    #     return self.dfs(root)
    # def dfs(self, root):
    #     if not root:
    #         return 0 
    #     if root in self.hash_dict:
    #         return hash_dict[root]

    #     val1 = root.val 
    #     if root.left:
    #         val1 += self.rob(root.left.left) + self.rob(root.left.right)
    #     if root.right:
    #         val1 += self.rob(root.right.left) + self.rob(root.right.right)
        
    #     val2 = self.rob(root.left) + self.rob(root.right)
        
    #     val = max(val1, val2)
    #     self.hash_dict[root] = val
    #     return val


        # Now let's take one step back and ask why we have overlapping subproblems. If you trace all the way back to the beginning, you'll find the answer lies in the way how we have defined rob(root). As I mentioned, for each tree root, there are two scenarios: it is robbed or is not. rob(root) does not distinguish between these two cases, so "information is lost as the recursion goes deeper and deeper", which results in repeated subproblems.

        # Redefine rob(root) as a new function which will return an array of two elements, the first element of which denotes the maximum amount of money that can be robbed if root is not robbed, while the second element signifies the maximum amount of money robbed if it is robbed.

        return max(self.dfs(root))

    def dfs(self, root):
        if not root:
            return (0, 0)
            
        left = self.dfs(root.left)
        right = self.dfs(root.right)

        ans1 = root.val + left[1] + right[1]
        ans2 = max(left[0], left[1]) + max(right[0], right[1])
        return (ans1, ans2)
        
# @lc code=end

