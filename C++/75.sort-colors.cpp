/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 *
 * https://leetcode.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (43.95%)
 * Likes:    2240
 * Dislikes: 184
 * Total Accepted:    386.8K
 * Total Submissions: 878.5K
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * Given an array with n objects colored red, white or blue, sort them in-place
 * so that objects of the same color are adjacent, with the colors in the order
 * red, white and blue.
 * 
 * Here, we will use the integers 0, 1, and 2 to represent the color red,
 * white, and blue respectively.
 * 
 * Note: You are not suppose to use the library's sort function for this
 * problem.
 * 
 * Example:
 * 
 * 
 * Input: [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 * 
 * Follow up:
 * 
 * 
 * A rather straight forward solution is a two-pass algorithm using counting
 * sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, then
 * overwrite array with total number of 0's, then 1's and followed by 2's.
 * Could you come up with a one-pass algorithm using only constant space?
 * 
 * 
 */
#include<vector>
#include<iostream>
using namespace std; 

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero=-1, one=-1, two=-1;

        for (auto num: nums) {
            if (num==0) {
                two++;
                nums[two] = 2;
                one++;
                nums[one] = 1;
                zero++;
                nums[zero] = 0;
            }
            if (num==1) {
                two++;
                nums[two] = 2;
                one++;
                nums[one] = 1;
            }
            if (num==2) {
                two++;
                nums[two] = 2;
            }
        }
    }
};
// @lc code=end

int main() {
    Solution sol;
    vector<int> nums{0};
    sol.sortColors(nums);
}