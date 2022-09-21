/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (32.49%)
 * Likes:    977
 * Dislikes: 1616
 * Total Accepted:    452.3K
 * Total Submissions: 1.4M
 * Testcase Example:  '4'
 *
 * Implement int sqrt(int x).
 * 
 * Compute and return the square root of x, where x is guaranteed to be a
 * non-negative integer.
 * 
 * Since the return type is an integer, the decimal digits are truncated and
 * only the integer part of the result is returned.
 * 
 * Example 1:
 * 
 * 
 * Input: 4
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since 
 * the decimal part is truncated, 2 is returned.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // int mySqrt(int x) {
    //     // newton optimization
    //     long ans = x;
    //     while ((ans * ans) > x) 
    //         ans = (ans + x / ans) / 2;
    //     return ans;
    // }

    int mySqrt(int x) {
        long left=1, right=x;
        while (left<=right) {
            long mid = left + (right-left)/2;
            long div = x / mid;

            if(div==mid) 
                return mid;
            else if(mid<div) left = mid+1;
            else right = mid-1;
        }
        return right;

        int left = 0, right = n;
        while (left < right) {
            int mid = right - (right - left) / 2;
            int div = n / mid;
            
            if (mid > div) right = mid - 1;
            else left = mid;
        }
        return right;
    }
};
// @lc code=end

