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
        unordered_map<char, int> last;
        for (int left=0, right=0; right<s.size(); right++) {
            if (last.count(s[right]))
                left = max(last[s[right]]+1, left);
            ans = max(ans, right-left+1);
            last[s[right]] = right;
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


