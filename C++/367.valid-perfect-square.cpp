/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 *
 * https://leetcode.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (40.81%)
 * Likes:    590
 * Dislikes: 133
 * Total Accepted:    141K
 * Total Submissions: 345.5K
 * Testcase Example:  '16'
 *
 * Given a positive integer num, write a function which returns True if num is
 * a perfect square else False.
 * 
 * Note: Do not use any built-in library function such as sqrt.
 * 
 * Example 1:
 * 
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
 * Input: 14
 * Output: false
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        
        // int sub = 1;
        // while (num>0) {
        //     num -= sub;
        //     sub += 2;
        // }
        // return num == 0;

        int left=1, right=num;
        while (left<=right) {
            long mid = left + (right-left)/2;
            long prod = mid*mid;
            if (prod == num) 
                return true;
            else if (prod<num) 
                left = mid+1;
            else 
                right = mid-1;
        }
        return false;
    }
};
// @lc code=end

