/*
 * @lc app=leetcode id=2571 lang=cpp
 *
 * [2571] Minimum Operations to Reduce an Integer to 0
 *
 * https://leetcode.com/problems/minimum-operations-to-reduce-an-integer-to-0/description/
 *
 * algorithms
 * Medium (45.67%)
 * Likes:    186
 * Dislikes: 163
 * Total Accepted:    10.5K
 * Total Submissions: 23K
 * Testcase Example:  '39'
 *
 * You are given a positive integer n, you can do the following operation any
 * number of times:
 * 
 * 
 * Add or subtract a power of 2 from n.
 * 
 * 
 * Return the minimum number of operations to make n equal to 0.
 * 
 * A number x is power of 2 if x == 2^i where i >= 0.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 39
 * Output: 3
 * Explanation: We can do the following operations:
 * - Add 2^0 = 1 to n, so now n = 40.
 * - Subtract 2^3 = 8 from n, so now n = 32.
 * - Subtract 2^5 = 32 from n, so now n = 0.
 * It can be shown that 3 is the minimum number of operations we need to make n
 * equal to 0.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 54
 * Output: 3
 * Explanation: We can do the following operations:
 * - Add 2^1 = 2 to n, so now n = 56.
 * - Add 2^3 = 8 to n, so now n = 64.
 * - Subtract 2^6 = 64 from n, so now n = 0.
 * So the minimum number of operations is 3.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        while (n != 1) {
            if (n & 1) {
                if ((n>>1) & 1) n += 1;
                else n -= 1;
                
                ans += 1;
            }
            n >>= 1;
        }
        return ans + 1;
    }
};
// @lc code=end

