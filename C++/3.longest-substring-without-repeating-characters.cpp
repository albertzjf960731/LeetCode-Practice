/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
#include <string> 
#include <unordered_map>
#include <map>
#include <iostream>

using namespace std; 

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int i = -1;
        
        unordered_map<char, int> hash_map;
        for (int j=0; j<s.size(); j++) {
            if (hash_map.count(s[j]) != 0) {
                i = max(hash_map[s[j]], i);
            }
            hash_map[s[j]] = j;
            ans = max(ans, j-i);
        }
        return ans; 
    }
};
// @lc code=end

int main() {
    Solution sol;
    string s = "abcabcbb";

    int ans = sol.lengthOfLongestSubstring(s);
    cout << ans << endl;
    return 0;
}


