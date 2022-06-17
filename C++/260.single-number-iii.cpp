/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 *
 * https://leetcode.com/problems/single-number-iii/description/
 *
 * algorithms
 * Medium (59.32%)
 * Likes:    1140
 * Dislikes: 90
 * Total Accepted:    124.3K
 * Total Submissions: 209.5K
 * Testcase Example:  '[1,2,1,3,2,5]'
 *
 * Given an array of numbers nums, in which exactly two elements appear only
 * once and all the other elements appear exactly twice. Find the two elements
 * that appear only once.
 * 
 * Example:
 * 
 * 
 * Input:  [1,2,1,3,2,5]
 * Output: [3,5]
 * 
 * Note:
 * 
 * 
 * The order of the result is not important. So in the above example, [5, 3] is
 * also correct.
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant space complexity?
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = 0;
        for (int num: nums) diff ^= num;

        int last = diff & (-diff);
        // int last = diff & (~(diff - 1));

        int a=0, b=0;
        for (int num: nums) {
            if (last&num)
                a ^= num;
            else 
                b ^= num;
        }
        return vector<int>{a, b};
    }
};
// @lc code=end

