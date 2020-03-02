/*
 * @lc app=leetcode id=705 lang=cpp
 *
 * [705] Design HashSet
 *
 * https://leetcode.com/problems/design-hashset/description/
 *
 * algorithms
 * Easy (58.39%)
 * Likes:    234
 * Dislikes: 61
 * Total Accepted:    39.6K
 * Total Submissions: 67.8K
 * Testcase Example:  '["MyHashSet","add","add","contains","contains","add","contains","remove","contains"]\n' +
  '[[],[1],[2],[1],[3],[2],[2],[2],[2]]'
 *
 * Design a HashSet without using any built-in hash table libraries.
 * 
 * To be specific, your design should include these functions:
 * 
 * 
 * add(value): Insert a value into the HashSet. 
 * contains(value) : Return whether the value exists in the HashSet or not.
 * remove(value): Remove a value in the HashSet. If the value does not exist in
 * the HashSet, do nothing.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * MyHashSet hashSet = new MyHashSet();
 * hashSet.add(1);         
 * hashSet.add(2);         
 * hashSet.contains(1);    // returns true
 * hashSet.contains(3);    // returns false (not found)
 * hashSet.add(2);          
 * hashSet.contains(2);    // returns true
 * hashSet.remove(2);          
 * hashSet.contains(2);    // returns false (already removed)
 * 
 * 
 * 
 * Note:
 * 
 * 
 * All values will be in the range of [0, 1000000].
 * The number of operations will be in the range of [1, 10000].
 * Please do not use the built-in HashSet library.
 * 
 * 
 */
#include<vector>
#include<list>
using namespace std;

// @lc code=start
// class MyHashSet {
// private:
//     vector<int> data;
    
// public:
//     /** Initialize your data structure here. */
//     MyHashSet() {
//         data.resize(1000001, 0);   
//     }
    
//     void add(int key) {
//         data[key] = 1;
//     }
    
//     void remove(int key) {
//         data[key] = 0;
//     }
    
//     /** Returns true if this set contains the specified element */
//     bool contains(int key) {
//         return data[key]==1;
//     }
// };


// class MyHashSet {
// private:
//     vector<vector<int>> data;
    
// public:
//     /** Initialize your data structure here. */
//     MyHashSet() {
//         data.resize(1000, vector<int>());   
//     }
    
//     void add(int key) {
//         int hash_key = key % 1000;
//         if (data[hash_key].empty())
//             data[hash_key].resize(1000);
//         data[hash_key][key/1000] = 1;
//     }
    
//     void remove(int key) {
//         int hash_key = key % 1000;
//         if (!data[hash_key].empty())
//             data[hash_key][key/1000] = 0;
//     }
    
//     /** Returns true if this set contains the specified element */
//     bool contains(int key) {
//         int hash_key = key % 1000;
//         return !data[hash_key].empty() && data[hash_key][key/1000];
//     }
// };

class MyHashSet {
private:
    vector<list<int>> data;
    
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        data.resize(1000, list<int>());   
    }
    
    void add(int key) {
        int hash_key = key % 769;
        data[hash_key].push_back(key);
    }
    
    void remove(int key) {
        int hash_key = key % 769;
        data[hash_key].remove(key);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int hash_key = key % 769;
        for (auto it: data[hash_key])
            if (it == key) return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end

