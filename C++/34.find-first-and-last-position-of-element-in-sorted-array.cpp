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
        int left=0, right=nums.size()-1;
        while (left<=right) {
            int mid = left + (right-left)/2;
            if (nums[mid]<target)
                left = mid+1;
            else if (nums[mid]>target)
                right = mid-1;
            else {
                left=mid, right=mid;
                while (left>=0 && nums[left]==target)
                    left--;
                while (right<nums.size() && nums[right]==target)
                    right++;
                return vector<int>{left+1, right-1};
            }
        }
        return vector<int>{-1, -1};
    }
};
// @lc code=end

