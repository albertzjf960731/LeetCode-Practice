/*
 * @lc app=leetcode id=633 lang=cpp
 *
 * [633] Sum of Square Numbers
 *
 * https://leetcode.com/problems/sum-of-square-numbers/description/
 *
 * algorithms
 * Easy (32.47%)
 * Likes:    418
 * Dislikes: 279
 * Total Accepted:    57.4K
 * Total Submissions: 176.9K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer c, your task is to decide whether there're two
 * integers a and b such that a^2 + b^2 = c.
 * 
 * Example 1:
 * 
 * 
 * Input: 5
 * Output: True
 * Explanation: 1 * 1 + 2 * 2 = 5
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 3
 * Output: False
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool judgeSquareSum(int c) {
        int left=0, right=pow(c, 0.5);

        while(left<=right) {
            int l_pow = left*left, r_pow=right*right;
            
            if (l_pow==c-r_pow)
                return true;
            else if (l_pow<c-r_pow)
                left++;
            else
                right--;
        }
        return false;
    }
};
// @lc code=end

