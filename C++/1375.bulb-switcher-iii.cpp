/*
 * @lc app=leetcode id=1375 lang=cpp
 *
 * [1375] Bulb Switcher III
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int ans = 0, max_num = 0;
        for (int i=0; i<light.size(); i++) {
            max_num = max(max_num, light[i]);
            if (max_num == i+1)
                ans ++;
        }
        return ans;
    }
};
// @lc code=end

