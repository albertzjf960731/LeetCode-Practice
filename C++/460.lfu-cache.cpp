/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 *
 * https://leetcode.com/problems/lfu-cache/description/
 *
 * algorithms
 * Hard (32.43%)
 * Likes:    1107
 * Dislikes: 105
 * Total Accepted:    61.7K
 * Total Submissions: 190.3K
 * Testcase Example:  '["LFUCache","put","put","get","put","get","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[3],[4,4],[1],[3],[4]]'
 *
 * Design and implement a data structure for Least Frequently Used (LFU) cache.
 * It should support the following operations: get and put.
 * 
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reaches its capacity, it should invalidate the least
 * frequently used item before inserting a new item. For the purpose of this
 * problem, when there is a tie (i.e., two or more keys that have the same
 * frequency), the least recently used key would be evicted.
 * 
 * Note that the number of times an item is used is the number of calls to the
 * get and put functions for that item since it was inserted. This number is
 * set to zero when the item is removed.
 * 
 * 
 * 
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 * 
 * 
 * 
 * Example:
 * 
 * 
 * LFUCache cache = new LFUCache( 2 /* capacity  );
 * 
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // returns 1
 * cache.put(3, 3);    // evicts key 2
 * cache.get(2);       // returns -1 (not found)
 * cache.get(3);       // returns 3.
 * cache.put(4, 4);    // evicts key 1.
 * cache.get(1);       // returns -1 (not found)
 * cache.get(3);       // returns 3
 * cache.get(4);       // returns 4
 * 
 * 
 * 
 * 
 */
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;

// @lc code=start
class LFUCache {
private:
    int cap, minFreq;
    unordered_map<int, pair<int, int>> key2val_freq;
    unordered_map<int, list<int>> freq2keys;
    unordered_map<int, list<int>::iterator> key2iter;
    
public:
    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (!key2val_freq.count(key)) return -1;

        int freq = key2val_freq[key].second; 
        freq2keys[freq].erase(key2iter[key]);

        freq ++;
        key2val_freq[key].second = freq;
        freq2keys[freq].push_back(key);
        key2iter[key] = --freq2keys[freq].end();
        // key2iter[key] = freq2keys[freq].rbegin();

        if (freq2keys[minFreq].size()==0) ++minFreq;
        return key2val_freq[key].first;
    }
    
    void put(int key, int value) {
        if (cap <= 0) return;

        if (get(key)!=-1) {
            key2val_freq[key].first = value;
            return;
        }

        if (key2val_freq.size() == cap) {
            int k = freq2keys[minFreq].front();
            key2val_freq.erase(k);
            key2iter.erase(k);
            freq2keys[minFreq].pop_front();
        }
        key2val_freq[key] = {value, 1};
        freq2keys[1].push_back(key);
        key2iter[key] = --freq2keys[1].end();

        minFreq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

