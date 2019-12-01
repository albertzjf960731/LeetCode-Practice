/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] Integer to Roman
 */

#include<string>
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        if (s.empty()) return ans;

        unordered_map<char, int>hash_map {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        int num_i, num_j;
        for (int i=0; i<s.size()-1; i++) {
            num_i = hash_map[s[i]];
            num_j = hash_map[s[i+1]];
            if (num_i<num_j) 
                ans -= num_i;
            else 
                ans += num_i;
        }
        ans += hash_map[s.back()];
        return ans;
    }
};
// @lc code=end

