/*
 * @lc app=leetcode id=1262 lang=cpp
 *
 * [1262] Greatest Sum Divisible by Three
 *
 * https://leetcode.com/problems/greatest-sum-divisible-by-three/description/
 *
 * algorithms
 * Medium (47.65%)
 * Likes:    595
 * Dislikes: 16
 * Total Accepted:    21.9K
 * Total Submissions: 44.9K
 * Testcase Example:  '[3,6,5,1,8]'
 *
 * Given an array nums of integers, we need to find the maximum possible sum of
 * elements of the array such that it is divisible by three.
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [3,6,5,1,8]
 * Output: 18
 * Explanation: Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum
 * divisible by 3).
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4]
 * Output: 0
 * Explanation: Since 4 is not divisible by 3, do not pick any number.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,2,3,4,4]
 * Output: 12
 * Explanation: Pick numbers 1, 3, 4 and 4 their sum is 12 (maximum sum
 * divisible by 3).
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 4 * 10^4
 * 1 <= nums[i] <= 10^4
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
       vector<vector<int>> dp(nums.size()+1, vector<int>(3));
   
       dp[0][0] = 0; 
       dp[0][1] = INT_MIN; 
       dp[0][2] = INT_MIN; 

        
       for (int i=1; i<=nums.size(); i++) {

           dp[i][0] = max(dp[i-1][0], dp[i-1][(nums[i-1]) % 3] + nums[i-1]);
           dp[i][1] = max(dp[i-1][1], dp[i-1][(nums[i-1]+1) % 3] + nums[i-1]);
           dp[i][2] = max(dp[i-1][2], dp[i-1][(nums[i-1]+2) % 3] + nums[i-1]);
       }
        
       return dp[nums.size()][0];
    }
};
// @lc code=end

