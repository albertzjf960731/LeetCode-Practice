#
# @lc app=leetcode id=146 lang=python3
#
# [146] LRU Cache
#
# https://leetcode.com/problems/lru-cache/description/
#
# algorithms
# Medium (42.88%)
# Likes:    20748
# Dislikes: 1033
# Total Accepted:    1.7M
# Total Submissions: 4M
# Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +
#   '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
#
# Design a data structure that follows the constraints of a Least Recently Used
# (LRU) cache.
# 
# Implement the LRUCache class:
# 
# 
# LRUCache(int capacity) Initialize the LRU cache with positive size
# capacity.
# int get(int key) Return the value of the key if the key exists, otherwise
# return -1.
# void put(int key, int value) Update the value of the key if the key exists.
# Otherwise, add the key-value pair to the cache. If the number of keys exceeds
# the capacity from this operation, evict the least recently used key.
# 
# 
# The functions get and put must each run in O(1) average time complexity.
# 
# 
# Example 1:
# 
# 
# Input
# ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
# [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
# Output
# [null, null, null, 1, null, -1, null, -1, 3, 4]
# 
# Explanation
# LRUCache lRUCache = new LRUCache(2);
# lRUCache.put(1, 1); // cache is {1=1}
# lRUCache.put(2, 2); // cache is {1=1, 2=2}
# lRUCache.get(1);    // return 1
# lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
# lRUCache.get(2);    // returns -1 (not found)
# lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
# lRUCache.get(1);    // return -1 (not found)
# lRUCache.get(3);    // return 3
# lRUCache.get(4);    // return 4
# 
# 
# 
# Constraints:
# 
# 
# 1 <= capacity <= 3000
# 0 <= key <= 10^4
# 0 <= value <= 10^5
# At most 2 * 10^5 calls will be made to get and put.
# 
# 
#

# @lc code=start
class ListNode:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None

class LRUCache:

    def __init__(self, capacity: int):
        # self.capacity = capacity
        # self.cache = {}
        # self.keys = []

        self.capacity = capacity
        self.cache = {}
        self.head = ListNode(-1, -1)
        self.tail = ListNode(-1, -1)
        self.head.next = self.tail
        self.tail.prev = self.head

    def get(self, key: int) -> int:
        # if key in self.cache:
        #     self.keys.remove(key)
        #     self.keys.append(key)
        #     return self.cache[key]
        # return -1

        if key in self.cache:
            node = self.cache[key]
            self.remove(node)
            self.add(node)
            return node.value
        return -1
        
    def put(self, key: int, value: int) -> None:
        # if key in self.cache:
        #     self.keys.remove(key)
        # elif len(self.cache) == self.capacity:
        #     del self.cache[self.keys.pop(0)]
        # self.cache[key] = value
        # self.keys.append(key)


        if key in self.cache:
            self.remove(self.cache[key])
        elif len(self.cache) == self.capacity:
            self.remove(self.head.next)
        self.add(ListNode(key, value))

    def add(self, node):
        self.tail.prev.next = node
        node.prev = self.tail.prev
        self.tail.prev = node
        node.next = self.tail

        self.cache[node.key] = node

    def remove(self, node):
        node.prev.next = node.next
        node.next.prev = node.prev
        del self.cache[node.key]


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
# @lc code=end

