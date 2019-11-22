#
# @lc app=leetcode id=677 lang=python
#
# [677] Map Sum Pairs
#
# https://leetcode.com/problems/map-sum-pairs/description/
#
# algorithms
# Medium (52.40%)
# Likes:    366
# Dislikes: 66
# Total Accepted:    31.6K
# Total Submissions: 60.3K
# Testcase Example:  '["MapSum", "insert", "sum", "insert", "sum"]\n' +
#   '[[], ["apple",3], ["ap"], ["app",2], ["ap"]]'
#
# 
# Implement a MapSum class with insert, and sum methods.
# 
# 
# 
# For the method insert, you'll be given a pair of (string, integer). The
# string represents the key and the integer represents the value. If the key
# already existed, then the original key-value pair will be overridden to the
# new one.
# 
# 
# 
# For the method sum, you'll be given a string representing the prefix, and you
# need to return the sum of all the pairs' value whose key starts with the
# prefix.
# 
# 
# Example 1:
# 
# Input: insert("apple", 3), Output: Null
# Input: sum("ap"), Output: 3
# Input: insert("app", 2), Output: Null
# Input: sum("ap"), Output: 5
# 
# 
# 
#

# @lc code=start

class TrieNode():
    def __init__(self, val = 0):
        self.val = val
        self.children = {}
 
class MapSum(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()
        self.keys = {}


    # For inserting, we first determine if the string already exists in the Trie. If it does, we calculate the difference in the previous and new value, and update the nodes with the difference as we traverse down the Trie nodes.

    # Sum is simple because each node already holds the sum of its children and we simply have to traverse to the node and obtain its count.

    def insert(self, key, val):
        """
        :type key: str
        :type val: int
        :rtype: None
        """
        curr = self.root
        delta = val - self.keys.get(key, 0)
        self.keys[key] = val
        
        curr = self.root
        curr.val += delta
        for char in key:
            if char not in curr.children:
                curr.children[char] = TrieNode()
            curr = curr.children[char]
            curr.val += delta

    def sum(self, prefix):
        """
        :type prefix: str
        :rtype: int
        """
        curr = self.root
        for char in prefix:
            if char not in curr.children:
                return 0
            curr = curr.children[char]
        return curr.val


# Your MapSum object will be instantiated and called as such:
# obj = MapSum()
# obj.insert(key,val)
# param_2 = obj.sum(prefix)
# @lc code=end

sol = MapSum()
sol.insert('apple', 3)  
print(sol.sum('ap'))
sol.insert('apple', 2)
print(sol.sum('ap'))