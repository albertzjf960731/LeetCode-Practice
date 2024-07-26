#
# @lc app=leetcode id=95 lang=python
#
# [95] Unique Binary Search Trees II
#
# https://leetcode.com/problems/unique-binary-search-trees-ii/description/
#
# algorithms
# Medium (37.40%)
# Likes:    1550
# Dislikes: 129
# Total Accepted:    157.7K
# Total Submissions: 421.6K
# Testcase Example:  '3'
#
# Given an integer n, generate all structurally unique BST's (binary search
# trees) that store values 1 ... n.
# 
# Example:
# 
# 
# Input: 3
# Output:
# [
# [1,null,3,2],
# [3,2,null,1],
# [3,1,null,null,2],
# [2,1,3],
# [1,null,2,null,3]
# ]
# Explanation:
# The above output corresponds to the 5 unique BST's shown below:
# 
# ⁠  1         3     3      2      1
# ⁠   \       /     /      / \      \
# ⁠    3     2     1      1   3      2
# ⁠   /     /       \                 \
# ⁠  2     1         2                 3
# 
# 
#

# @lc code=start
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """

        return self.dfs(1, n)

    def dfs(self, start, end):
        if start > end:
            return [None]
            
        trees = []
        for root in range(start, end+1):
            lefts = self.dfs(start, root-1)
            rights = self.dfs(root+1, end)
            for left in lefts:
                for right in rights:
                    trees.append(TreeNode(root, left, right))
        return trees    


        # 动态规划

    #     pre = []
    #     if n == 0:
    #         return pre 

    #     pre.append(None)

    #     for i in range(1, n+1):
    #         cur = []

    #         # 遍历之前所有的解
    #         for root in pre:
    #             # 插入到根结点
    #             insert = TreeNode(i)
    #             insert.left = root
    #             cur.append(insert)

    #             # 插入到右孩子...
    #             for j in range(n):
    #                 root_copy = self.tree_copy(root)
    #                 right = root_copy

    #                 for _ in range(j):
    #                     if not right:
    #                         break
    #                     right = right.right

    #                 if not right:
    #                     break

    #                 right_tree = right.right
                    
    #                 insert = TreeNode(i)
    #                 right.right = insert
    #                 insert.left = right_tree
                    
    #                 cur.append(root_copy)
    #         pre = cur
    #     return pre                    


    # def tree_copy(self, root):
    #     if not root:
    #         return root
    #     new_root = TreeNode(root.val)
    #     new_root.left = self.tree_copy(root.left)
    #     new_root.right = self.tree_copy(root.right)
    #     return new_root


        # def node(val, left, right):
        #     node = TreeNode(val)
        #     node.left = left
        #     node.right = right
        #     return node
 
        # def trees(first, last):
        #     return [node(root, left, right)
        #             for root in range(first, last+1)
        #             for left in trees(first, root-1)
        #             for right in trees(root+1, last)] or [None]
        
        # if n == 0:
        #     return []
        # return trees(1, n)

# @lc code=end

