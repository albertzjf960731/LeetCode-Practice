/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (51.12%)
 * Likes:    2292
 * Dislikes: 138
 * Total Accepted:    447K
 * Total Submissions: 873.7K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings, group anagrams together.
 * 
 * Example:
 * 
 * 
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * Note:
 * 
 * 
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 * 
 * 
 */
#include<vector>
#include<string>
#include<unordered_map>
using namespace std; 

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash_map;

        for (string s: strs) {
            string t = s;
            sort(t.begin(), t.end());
            hash_map[t].push_back(s);
        }

        vector<vector<string>> res;
        for(auto items: hash_map) {
            res.push_back(items.second);
        }

        return res;
    }
};
// @lc code=end

