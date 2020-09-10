/*
 * @lc app=leetcode id=201 lang=cpp
 *
 * [201] Bitwise AND of Numbers Range
 *
 * https://leetcode.com/problems/bitwise-and-of-numbers-range/description/
 *
 * algorithms
 * Medium (37.08%)
 * Likes:    574
 * Dislikes: 78
 * Total Accepted:    95.3K
 * Total Submissions: 256.9K
 * Testcase Example:  '5\n7'
 *
 * Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND
 * of all numbers in this range, inclusive.
 * 
 * Example 1:
 * 
 * 
 * Input: [5,7]
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [0,1]
 * Output: 0
 */

// @lc code=start
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while (n > m) {
            n = n & (n-1);
        }
        return n;

        // unsigned int mask = 0xFFFFFFFF;
        // while ((m&mask) != (n&mask))
        //     mask <<= 1;
        // return m & mask;

        // int zeros = 0;
        // while(m != n) {
        //     zeros ++;
        //     m >>= 1;
        //     n >>= 1;
        // }
        // return m << zeros;
    }
};
// @lc code=end

