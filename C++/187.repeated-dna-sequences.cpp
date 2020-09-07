/*
 * @lc app=leetcode id=187 lang=cpp
 *
 * [187] Repeated DNA Sequences
 */
#include<unordered_set>
#include<string>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string str) {
        if (str.size() < 10) return {};
        
        unordered_set<string> hash_set, res;
        for (int i=0; i<=str.size()-10; ++i) {
            string sub_str = str.substr(i, 10);
            if (hash_set.count(sub_str)) {
                res.insert(sub_str);
            }
            else {
                hash_set.insert(sub_str);
            }
        }
        return {res.begin(), res.end()};
    }
};
// @lc code=end

