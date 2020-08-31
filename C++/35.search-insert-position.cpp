/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] Search Insert Position
 */
#include<vector>    
using namespace std;

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // int l=0, r=nums.size()-1, m;
        // while (l<=r) {
        //     m = (l+r)/2;
        //     if (nums[m]==target)
        //         return m;
        //     else if (nums[m]<target)
        //         l=m+1;
        //     else
        //         r=m-1;
        // }
        // return l;
        if (nums.back() < target) return nums.size();
        
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};
// @lc code=end

