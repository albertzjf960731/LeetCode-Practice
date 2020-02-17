/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 *
 * https://leetcode.com/problems/power-of-four/description/
 *
 * algorithms
 * Easy (41.11%)
 * Likes:    403
 * Dislikes: 176
 * Total Accepted:    135K
 * Total Submissions: 328.4K
 * Testcase Example:  '16'
 *
 * Given an integer (signed 32 bits), write a function to check whether it is a
 * power of 4.
 * 
 * Example 1:
 * 
 * 
 * Input: 16
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 5
 * Output: false
 * 
 * 
 * Follow up: Could you solve it without loops/recursion?
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfFour(int num) {
        return num>0 && (num&(num-1))==0 && (num-1)%3==0;
    }
};
// @lc code=end

