#
# @lc app=leetcode id=1490 lang=python3
#
# [1490] Clone N-ary Tree
#
# https://leetcode.com/problems/clone-n-ary-tree/description/
#
# algorithms
# Medium (83.17%)
# Likes:    409
# Dislikes: 15
# Total Accepted:    29.4K
# Total Submissions: 35.4K
# Testcase Example:  '[1,null,3,2,4,null,5,6]'
#
# Given a root of an N-ary tree, return a deep copy (clone) of the tree.
# 
# Each node in the n-ary tree contains a val (int) and a list (List[Node]) of
# its children.
# 
# 
# class Node {
# ⁠   public int val;
# ⁠   public List<Node> children;
# }
# 
# 
# Nary-Tree input serialization is represented in their level order traversal,
# each group of children is separated by the null value (See examples).
# 
# 
# Example 1:
# 
# 
# 
# 
# Input: root = [1,null,3,2,4,null,5,6]
# Output: [1,null,3,2,4,null,5,6]
# 
# 
# Example 2:
# 
# 
# 
# 
# Input: root =
# [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
# Output:
# [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
# 
# 
# 
# Constraints:
# 
# 
# The depth of the n-ary tree is less than or equal to 1000.
# The total number of nodes is between [0, 10^4].
# 
# 
# 
# Follow up: Can your solution work for the graph problem?
#

# @lc code=start
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []
"""

class Solution:
    def cloneTree(self, root: 'Node') -> 'Node':
        if not root:
            return None
        if not root:
            return None
        
        queue = deque()
        queue.append(root)

        hmap = {}
        hmap[root] = Node(root.val)
        while queue:
            cur = queue.popleft()

            for ch in cur.children:
                queue.append(ch)
                hmap[ch] = Node(ch.val)
                hmap[cur].children.append(hmap[ch])
        return hmap[root]
# @lc code=end

