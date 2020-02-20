/*
 * @lc app=leetcode id=441 lang=cpp
 *
 * [441] Arranging Coins
 *
 * https://leetcode.com/problems/arranging-coins/description/
 *
 * algorithms
 * Easy (39.19%)
 * Likes:    257
 * Dislikes: 551
 * Total Accepted:    86.5K
 * Total Submissions: 220.6K
 * Testcase Example:  '5'
 *
 * You have a total of n coins that you want to form in a staircase shape,
 * where every k-th row must have exactly k coins.
 * ⁠
 * Given n, find the total number of full staircase rows that can be formed.
 * 
 * n is a non-negative integer and fits within the range of a 32-bit signed
 * integer.
 * 
 * Example 1:
 * 
 * n = 5
 * 
 * The coins can form the following rows:
 * ¤
 * ¤ ¤
 * ¤ ¤
 * 
 * Because the 3rd row is incomplete, we return 2.
 * 
 * 
 * 
 * Example 2:
 * 
 * n = 8
 * 
 * The coins can form the following rows:
 * ¤
 * ¤ ¤
 * ¤ ¤ ¤
 * ¤ ¤
 * 
 * Because the 4th row is incomplete, we return 3.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int arrangeCoins(int n) {
        int left=0, right=n;
        while (left<right) {
            int mid = left + (right-left)/2 + 1;
            
            if(n >= mid/2.0*(mid+1))
                left = mid;
            else 
                right = mid-1;
        }
        return right;
    }
};
// @lc code=end

