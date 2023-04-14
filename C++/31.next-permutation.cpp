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
        int n = nums.size();
        
        // 非递增
        // max(i)
        int i = n - 2;
        while (i>=0 && nums[i]>=nums[i+1]) i--;

        if (i == -1) {
            reverse(nums.begin(), nums.end());
        }
        else {
            // min(nums[j]) && nums[i] < nums[j];
            int j = n - 1;
            while (nums[j]<=nums[i]) j--;
            swap(nums[i], nums[j]);
            reverse(nums.begin()+i+1, nums.end());
        }
    }
};
// @lc code=end

