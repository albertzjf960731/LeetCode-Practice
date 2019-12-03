/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1, m;
        while (l<=r) {
            m = (l+r)/2;
            if (nums[m]<target)
                l = m+1;
            else if (nums[m]>target)
                r = m-1;
            else {
                l=m, r=m;
                while (l>=0 && nums[l]==target)
                    l--;
                while (r<nums.size() && nums[r]==target)
                    r++;
                return vector<int>{l+1, r-1};
            }
        }
        return vector<int>{-1, -1};
    }
};
// @lc code=end

