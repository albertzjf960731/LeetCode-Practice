/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] Remove Element
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        for (int j=0; j<nums.size(); j++) {
            if (nums[j]!=val)
                nums[i++] = nums[j];
        }
        return i;
    }
};
// @lc code=end

