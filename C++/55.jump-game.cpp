/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] Jump Game
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxPos = 0;
        for (int i=0; i<nums.size(); i++) {
            if (maxPos<i)
                return false;
            maxPos = max(maxPos, nums[i]+i);
        }
        return true;
    }
};
// @lc code=end

