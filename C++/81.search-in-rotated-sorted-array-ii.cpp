/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Medium (32.84%)
 * Likes:    910
 * Dislikes: 388
 * Total Accepted:    202.7K
 * Total Submissions: 617.1K
 * Testcase Example:  '[2,5,6,0,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return true,
 * otherwise return false.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,5,6,0,0,1,2], target = 0
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [2,5,6,0,0,1,2], target = 3
 * Output: false
 * 
 * Follow up:
 * 
 * 
 * This is a follow up problem to Search in Rotated Sorted Array, where nums
 * may contain duplicates.
 * Would this affect the run-time complexity? How and why?
 * 
 * 
 */
#include<vector>
using namespace std; 

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;
        
        while (left<right && nums[left]==nums[right])
            left++;
        while (left<right) {
            int mid = left + (right-left)/2;
            if (nums[mid]>nums[right])
                left = mid+1;
            else if (nums[mid]<nums[right])
                right = mid;
            else 
                right--;
        }
        int idx = left;
        
        left=0, right=nums.size()-1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            int mid_rotated = (mid+idx) % nums.size();

            if (nums[mid_rotated] == target) 
                return true;
            else if (nums[mid_rotated]<target)
                left = mid+1;
            else 
                right = mid-1;
        }
        return false;
    }

};
// @lc code=end

