/*
 * @lc app=leetcode id=476 lang=cpp
 *
 * [476] Number Complement
 *
 * https://leetcode.com/problems/number-complement/description/
 *
 * algorithms
 * Easy (63.21%)
 * Likes:    658
 * Dislikes: 75
 * Total Accepted:    124.1K
 * Total Submissions: 196.3K
 * Testcase Example:  '5'
 *
 * Given a positive integer, output its complement number. The complement
 * strategy is to flip the bits of its binary representation.
 * 
 * Note:
 * 
 * The given integer is guaranteed to fit within the range of a 32-bit signed
 * integer.
 * You could assume no leading zero bit in the integer’s binary
 * representation.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: 5
 * Output: 2
 * Explanation: The binary representation of 5 is 101 (no leading zero bits),
 * and its complement is 010. So you need to output 2.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 1
 * Output: 0
 * Explanation: The binary representation of 1 is 1 (no leading zero bits), and
 * its complement is 0. So you need to output 0.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findComplement(int num) {
        // int ans = 0;
        // int cnt = 0;
        // while (num) {
        //     ans |= (num & 1 ^ 1) << cnt;
        //     num >>= 1;
        //     cnt += 1;
        // }
        // return ans; 
        
        for(long i=1; i<=num; i<<=1) 
            num ^= i; 
        return num;
    }
};
// @lc code=end

