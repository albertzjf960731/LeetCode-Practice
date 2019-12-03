/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1, m;
        while (l<r) {
            m = (l+r)/2;
            if (nums[m]>nums[r]) 
                l = m+1;
            else 
                r = m;
        }
        int rotated = l, real_m;
        l=0, r=nums.size()-1;
        while (l<=r) {
            m = (l+r)/2;
            real_m = (m+rotated) % nums.size();
            if (nums[real_m] ==target)
                return real_m;
            if (nums[real_m]<target)
                l = m+1;
            else 
                r = (m-1);
        }
        return -1;
    }
};
// @lc code=end

