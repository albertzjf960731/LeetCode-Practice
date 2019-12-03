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
        int i = nums.size()-2;
        while ((i>=0 && nums[i]>=nums[i+1]))
            i--;
        if (i<0) 
            reverse(nums.begin(), nums.end());
        else {
            int j = nums.size()-1;
            while (j>=0 && nums[j]<=nums[i]) 
                j--;
            swap(nums[i], nums[j]);
            reverse(nums.begin()+i+1, nums.end());
        }
    }
};
// @lc code=end

