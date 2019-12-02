/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        if(nums.empty()) return i;

        for (int j=1; j<nums.size(); j++) {
            if (nums[j] != nums[i]) 
                nums[++i] = nums[j];
        }
        return i+1;
    }
};
// @lc code=end

