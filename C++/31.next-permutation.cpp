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
        // 要想使得数字变大，只要任意一位变大就可以。
        // 如果从右边找一个更大的数字交换过来，由于是从低位交换过来的，所以数字满足了会变大。
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
            while (j>i && nums[j]<=nums[i]) 
                j--;
            swap(nums[i], nums[j]);
            reverse(nums.begin()+i+1, nums.end());
        }
    }
};
// @lc code=end

