/*
 * @lc app=leetcode id=665 lang=cpp
 *
 * [665] Non-decreasing Array
 *
 * https://leetcode.com/problems/non-decreasing-array/description/
 *
 * algorithms
 * Medium (21.59%)
 * Likes:    3727
 * Dislikes: 669
 * Total Accepted:    177.9K
 * Total Submissions: 815.7K
 * Testcase Example:  '[4,2,3]'
 *
 * Given an array nums with n integers, your task is to check if it could
 * become non-decreasing by modifying at most one element.
 * 
 * We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for
 * every i (0-based) such that (0 <= i <= n - 2).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,2,3]
 * Output: true
 * Explanation: You could modify the first 4 to 1 to get a non-decreasing
 * array.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,2,1]
 * Output: false
 * Explanation: You can't get a non-decreasing array by modify at most one
 * element.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == nums.length
 * 1 <= n <= 10^4
 * -10^5 <= nums[i] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        for (int i=0, cnt=1; i<nums.size()-1; i++) {
            if (nums[i] <= nums[i+1])
                continue;
            
            if (cnt == 0) return false;
            
            if (i-1 >= 0 && nums[i-1] > nums[i+1]) 
                nums[i+1] = nums[i];
            else 
                nums[i] = nums[i+1];
            cnt -= 1;
        }
        return true;    }
};
// @lc code=end

