/*
 * @lc app=leetcode id=706 lang=cpp
 *
 * [706] Design HashMap
 *
 * https://leetcode.com/problems/design-hashmap/description/
 *
 * algorithms
 * Easy (59.00%)
 * Likes:    629
 * Dislikes: 86
 * Total Accepted:    69.5K
 * Total Submissions: 117.8K
 * Testcase Example:  '["MyHashMap","put","put","get","get","put","get", "remove", "get"]\n' +
  '[[],[1,1],[2,2],[1],[3],[2,1],[2],[2],[2]]'
 *
 * Design a HashMap without using any built-in hash table libraries.
 * 
 * To be specific, your design should include these functions:
 * 
 * 
 * put(key, value) : Insert a (key, value) pair into the HashMap. If the value
 * already exists in the HashMap, update the value.
 * get(key): Returns the value to which the specified key is mapped, or -1 if
 * this map contains no mapping for the key.
 * remove(key) : Remove the mapping for the value key if this map contains the
 * mapping for the key.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * MyHashMap hashMap = new MyHashMap();
 * hashMap.put(1, 1);          
 * hashMap.put(2, 2);         
 * hashMap.get(1);            // returns 1
 * hashMap.get(3);            // returns -1 (not found)
 * hashMap.put(2, 1);          // update the existing value
 * hashMap.get(2);            // returns 1 
 * hashMap.remove(2);          // remove the mapping for 2
 * hashMap.get(2);            // returns -1 (not found) 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * All keys and values will be in the range of [0, 1000000].
 * The number of operations will be in the range of [1, 10000].
 * Please do not use the built-in HashMap library.
 * 
 * 
 */
#include<vector>
#include<list>
using namespace std;

// @lc code=start
// class MyHashMap {
// private:
//     vector<int> data;
    
// public:
//     /** Initialize your data structure here. */
//     MyHashMap() {
//         data.resize(1000000, -1);
//     }
    
//     /** value will always be non-negative. */
//     void put(int key, int value) {
//         data[key] = value;
//     }
    
//     /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
//     int get(int key) {
//         return data[key];
//     }
    
//     /** Removes the mapping of the specified value key if this map contains a mapping for the key */
//     void remove(int key) {
//         data[key] = -1;
//     }
// };


// class MyHashMap {
// private:
//     vector<vector<int>> data;
    
// public:
//     /** Initialize your data structure here. */
//     MyHashMap() {
//         data.resize(1000, vector<int>());
//     }
    
//     /** value will always be non-negative. */
//     void put(int key, int value) {
//         int hash_key = key % 1000;
//         if (data[hash_key].empty())
//             data[hash_key].resize(1000, -1);
//         data[hash_key][key/1000] = value;
//     }
    
//     /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
//     int get(int key) {
//         int hash_key = key % 1000;
//         if (!data[hash_key].empty())
//             return data[hash_key][key/1000];
//         return -1;
//     }
    
//     /** Removes the mapping of the specified value key if this map contains a mapping for the key */
//     void remove(int key) {
//         int hash_key = key % 1000;
//         if (!data[hash_key].empty())
//             data[hash_key][key/1000] = -1;
//     }
// };


class MyHashMap {
    
private:
	vector<list<pair<int,int>>> data;


	list<pair<int,int>>::iterator getIter(int hash_key, int key) {
		list<pair<int,int>>::iterator it;
		for(it = data[hash_key].begin(); it != data[hash_key].end(); ++it) {
			if(it->first == key)
				return it;
		}
		return it;
	}

public:
	/** Initialize your data structure here. */
	MyHashMap() {
		data.resize(769);
	}

	/** value will always be non-negative. */
	void put(int key, int value) {
		int hash_key = key % 769;
        
		auto it = getIter(hash_key, key);
		if(it==data[hash_key].end())
			data[hash_key].push_back(make_pair(key,value));
		else
			it->second = value;
	}

	/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
	int get(int key) {
		int hash_key = key % 769;
        
		auto it = getIter(hash_key, key);
		if(it!=data[hash_key].end())
			return it->second;
		return -1;
	}

	/** Removes the mapping of the specified value key if this map contains a mapping for the key */
	void remove(int key) {
		int hash_key = key % 769;
        
		auto it = getIter(hash_key, key);
		if(it!=data[hash_key].end())
			data[hash_key].erase(it); 
	}
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end

