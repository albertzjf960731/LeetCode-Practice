/*
 * @lc app=leetcode id=390 lang=cpp
 *
 * [390] Elimination Game
 *
 * https://leetcode.com/problems/elimination-game/description/
 *
 * algorithms
 * Medium (44.59%)
 * Likes:    499
 * Dislikes: 381
 * Total Accepted:    35.1K
 * Total Submissions: 78.4K
 * Testcase Example:  '9'
 *
 * 
 * There is a list of sorted integers from 1 to n. Starting from left to right,
 * remove the first number and every other number afterward until you reach the
 * end of the list.
 * 
 * Repeat the previous step again, but this time from right to left, remove the
 * right most number and every other number from the remaining numbers.
 * 
 * We keep repeating the steps again, alternating left to right and right to
 * left, until a single number remains.
 * 
 * Find the last number that remains starting with a list of length n.
 * 
 * Example:
 * 
 * Input:
 * n = 9,
 * 1 2 3 4 5 6 7 8 9
 * 2 4 6 8
 * 2 6
 * 6
 * 
 * Output:
 * 6
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int helper(int n) {
        if(n==1) return 1;
        if(n==2) return 2;

        if(n%2 != 0) return helper(n-1);
        else return 2*(n/2+1-helper(n/2));
    }

    int lastRemaining(int n) {
        return helper(n);
    }


    int helper(int n, int m) {
        if (n == 1) {
            return 0;
        }
        int x = helper(n-1, m);
        return (m + x) % n;
    }
    int lastRemaining(int n, int m) {
        return helper(n, m);
    }
};
// @lc code=end

