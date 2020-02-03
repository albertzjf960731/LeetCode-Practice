/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Hard (40.17%)
 * Likes:    648
 * Dislikes: 183
 * Total Accepted:    157K
 * Total Submissions: 390.8K
 * Testcase Example:  '[1,3,5]'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 * 
 * Find the minimum element.
 * 
 * The array may contain duplicates.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,5]
 * Output: 1
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,2,0,1]
 * Output: 0
 * 
 * Note:
 * 
 * 
 * This is a follow up problem to Find Minimum in Rotated Sorted Array.
 * Would allow duplicates affect the run-time complexity? How and why?
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0, right=nums.size()-1;
        
        while (left<right && nums[left]==nums[right])
            left++;
        while(left<right) {
            int mid = left + (right-left)/2;
            if (nums[mid]>nums[right])
                left = mid+1;
            else if (nums[mid] < nums[right]) 
                right = mid;
            else 
                right --;
        }
        return nums[left];
    }
};
// @lc code=end

