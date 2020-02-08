/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] Next Permutation
 */
#include<vector>
#include<algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(), nums.end());

        int i = nums.size()-2;
        //找到第一个不再递增的位置
        while ((i>=0 && nums[i]>=nums[i+1]))
            i--;
        // 如果到了最左边，就直接倒置输出
        if (i<0) 
            reverse(nums.begin(), nums.end());
        else {
            //找到刚好大于 nums[i]的位置
            int j = nums.size()-1;
            while (j>=0 && nums[j]<=nums[i]) 
                j--;
            swap(nums[i], nums[j]);
            reverse(nums.begin()+i+1, nums.end());
        }
    }
};
// @lc code=end

