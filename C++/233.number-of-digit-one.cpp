/*
 * @lc app=leetcode id=233 lang=cpp
 *
 * [233] Number of Digit One
 *
 * https://leetcode.com/problems/number-of-digit-one/description/
 *
 * algorithms
 * Hard (30.88%)
 * Likes:    220
 * Dislikes: 527
 * Total Accepted:    45.1K
 * Total Submissions: 145.9K
 * Testcase Example:  '13'
 *
 * Given an integer n, count the total number of digit 1 appearing in all
 * non-negative integers less than or equal to n.
 * 
 * Example:
 * 
 * 
 * Input: 13
 * Output: 6 
 * Explanation: Digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
 * 
 * 
 */


// f(9) = 1;
// f(99) = f(9) * 10 + 10(contributed by the most significant digit in range [10, 19]) = 20  
// f(999) = f(99) * 10 + 100(contributed by the most significant digit in range [100, 199]) = 300
// f(9999) = f(999) * 10 + 1000(contributed by the most significant digit in range [1000, 1999]) = 10 * 300 + 1000 = 4000
// ... ...

// 23 = [0, 9] + [10, 19] + [20, 23]

// f(23) = f(9) * 2 + 10 + f(3)

// @lc code=start
class Solution {
public:
    int countDigitOne(int n) {
        // Go through the digit positions by using position multiplier m with values 1, 10, 100, 1000, etc.

        // For each position, split the decimal representation into two parts, for example split n=3141592 into a=31415 and b=92 when we're at m=100 for analyzing the hundreds-digit. And then we know that the hundreds-digit of n is 1 for prefixes "" to "3141", i.e., 3142 times. Each of those times is a streak, though. Because it's the hundreds-digit, each streak is 100 long. So (a / 10 + 1) * 100 times, the hundreds-digit is 1.

        // Consider the thousands-digit, i.e., when m=1000. Then a=3141 and b=592. The thousands-digit is 1 for prefixes "" to "314", so 315 times. And each time is a streak of 1000 numbers. However, since the thousands-digit is a 1, the very last streak isn't 1000 numbers but only 593 numbers, for the suffixes "000" to "592". So (a / 10 * 1000) + (b + 1) times, the thousands-digit is 1.

        // The case distincton between the current digit/position being 0, 1 and >=2 can easily be done in one expression. With (a + 8) / 10 you get the number of full streaks, and a % 10 == 1 tells you whether to add a partial streak.
        int ans = 0;
        for(long m=1; m<=n; m*=10){
            int a = n / m, b = n % m;
            ans += (a+8)/10*m + (a%10==1)*(b+1);
        }
        return ans;
    }
};
// @lc code=end

