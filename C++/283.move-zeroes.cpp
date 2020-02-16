/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (55.92%)
 * Likes:    2842
 * Dislikes: 95
 * Total Accepted:    602.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * 
 * Note:
 * 
 * 
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left=0;
        for (int right=0; right<nums.size(); right++) {
            if (nums[right]!=0) {
                nums[left] = nums[right];
                left++;
            }
        }
        for (; left<nums.size(); left++)
            nums[left] = 0;
    }
};
// @lc code=end

