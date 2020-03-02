/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (29.89%)
 * Likes:    4643
 * Dislikes: 202
 * Total Accepted:    439.7K
 * Total Submissions: 1.5M
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and put.
 * 
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reached its capacity, it should invalidate the least recently
 * used item before inserting a new item.
 * 
 * The cache is initialized with a positive capacity.
 * 
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 * 
 * Example:
 * 
 * 
 * LRUCache cache = new LRUCache( 2 /* capacity 
 * 
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // returns 1
 * cache.put(3, 3);    // evicts key 2
 * cache.get(2);       // returns -1 (not found)
 * cache.put(4, 4);    // evicts key 1
 * cache.get(1);       // returns -1 (not found)
 * cache.get(3);       // returns 3
 * cache.get(4);       // returns 4
 * 
 * 
 * 
 * 
 */
#include<unordered_map>
#include<list>
using namespace std;

// @lc code=start
class LRUCache{
private:
    int cap;
    list<pair<int, int>> dl;
    unordered_map<int, list<pair<int, int>>::iterator> hash_map;
    
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = hash_map.find(key);
        if (it==hash_map.end()) return -1;
    
        dl.splice(dl.begin(), dl, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = hash_map.find(key);
        
        if (it!=hash_map.end()) 
            dl.erase(it->second);
        dl.push_front(make_pair(key, value));
        hash_map[key] = dl.begin();
        
        if (hash_map.size() > cap) {
            hash_map.erase(dl.rbegin()->first);
            dl.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

