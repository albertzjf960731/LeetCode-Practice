/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int maxPos=0, lastPos=0, steps=0;
        
        for (int i=0; i<nums.size()-1; i++) {
            maxPos = max(maxPos, nums[i]+i);
            if (i==lastPos) {
                lastPos = maxPos;
                steps++;
            }
        }
        return steps;
    }
};
// @lc code=end

