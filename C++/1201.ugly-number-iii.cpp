/*
 * @lc app=leetcode id=1201 lang=cpp
 *
 * [1201] Ugly Number III
 *
 * https://leetcode.com/problems/ugly-number-iii/description/
 *
 * algorithms
 * Medium (24.89%)
 * Likes:    133
 * Dislikes: 156
 * Total Accepted:    6K
 * Total Submissions: 24.2K
 * Testcase Example:  '3\n2\n3\n5'
 *
 * Write a program to find the n-th ugly number.
 * 
 * Ugly numbers are positive integers which are divisible by a or b or c.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3, a = 2, b = 3, c = 5
 * Output: 4
 * Explanation: The ugly numbers are 2, 3, 4, 5, 6, 8, 9, 10... The 3rd is 4.
 * 
 * Example 2:
 * 
 * 
 * Input: n = 4, a = 2, b = 3, c = 4
 * Output: 6
 * Explanation: The ugly numbers are 2, 3, 4, 6, 8, 9, 10, 12... The 4th is
 * 6.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 5, a = 2, b = 11, c = 13
 * Output: 10
 * Explanation: The ugly numbers are 2, 4, 6, 8, 10, 11, 12, 13... The 5th is
 * 10.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: n = 1000000000, a = 2, b = 217983653, c = 336916467
 * Output: 1999999984
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n, a, b, c <= 10^9
 * 1 <= a * b * c <= 10^18
 * It's guaranteed that the result will be in range [1, 2 * 10^9]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        // Ugly numbers are positive integers which are divisible by a or b or c.

        long lcm_ab=lcm(a, b), lcm_ac=lcm(a, c), lcm_bc=lcm((long)b, (long)c), lcm_abc = lcm(a, lcm_bc);
        
        int left=1, right=2*1e9;
        while (left<right) {
            int mid = left + (right-left)/2;
            int count = mid/a + mid/b + mid/c - mid/lcm_ab - mid/lcm_ac - mid/lcm_bc + mid/lcm_abc;

            if (count < n) 
                left = mid+1;
            else 
                right =mid;
        }
        return left;   
    }
};
// @lc code=end

