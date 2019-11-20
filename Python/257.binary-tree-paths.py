#
# @lc app=leetcode id=257 lang=python
#
# [257] Binary Tree Paths
#
# https://leetcode.com/problems/binary-tree-paths/description/
#
# algorithms
# Easy (47.80%)
# Likes:    1122
# Dislikes: 79
# Total Accepted:    259.4K
# Total Submissions: 540.9K
# Testcase Example:  '[1,2,3,null,5]'
#
# Given a binary tree, return all root-to-leaf paths.
# 
# Note: A leaf is a node with no children.
# 
# Example:
# 
# 
# Input:
# 
# ⁠  1
# ⁠/   \
# 2     3
# ⁠\
# ⁠ 5
# 
# Output: ["1->2->5", "1->3"]
# 
# Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
    #     if not root:
    #         return []
    #     res = []
    #     self.dfs(root, [root.val], res)
    #     return res 
    
    # def dfs(self, root, path, res):
    #     if not root.left and not root.right:
    #         res.append('->'.join(str(item) for item in path))
    #         return

    #     if root.left:
    #         self.dfs(root.left, path+[root.left.val], res)
    #     if root.right:
    #         self.dfs(root.right, path+[root.right.val], res)


        # if not root:
        #     return []   
        # res = []
        # stack = [(root, '')]
        # while stack:
        #     node, path = stack.pop()

        #     if not node.left and not node.right:
        #         res.append(path+str(node.val))
        #     if node.left:
        #         stack.append((node.left, path+str(node.val)+'->'))
        #     if node.right:
        #         stack.append((node.right, path+str(node.val)+'->'))
        # return res

        import collections
        if not root:
            return []

        res = []
        queue = collections.deque([(root, '')])
        while queue:
            node, path = queue.popleft()

            if not node.left and not node.right:
                res.append(path+str(node.val))
            if node.left:
                queue.append((node.left, path+str(node.val)+'->'))
            if node.right:
                queue.append((node.right, path+str(node.val)+'->'))
        return res      

# @lc code=end

sol = Solution()
root = TreeNode(1)
cur = root
cur.left = TreeNode(2)  
cur.right = TreeNode(3)
cur = cur.left
cur.right = TreeNode(5)
print(sol.binaryTreePaths(root))