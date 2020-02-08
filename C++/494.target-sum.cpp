/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 *
 * https://leetcode.com/problems/target-sum/description/
 *
 * algorithms
 * Medium (46.21%)
 * Likes:    1898
 * Dislikes: 85
 * Total Accepted:    129.9K
 * Total Submissions: 281.2K
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * 
 * You are given a list of non-negative integers, a1, a2, ..., an, and a
 * target, S. Now you have 2 symbols + and -. For each integer, you should
 * choose one from + and - as its new symbol.
 * ⁠
 * 
 * Find out how many ways to assign symbols to make sum of integers equal to
 * target S.  
 * 
 * 
 * Example 1:
 * 
 * Input: nums is [1, 1, 1, 1, 1], S is 3. 
 * Output: 5
 * Explanation: 
 * 
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 * 
 * There are 5 ways to assign symbols to make the sum of nums be target 3.
 * 
 * 
 * 
 * Note:
 * 
 * The length of the given array is positive and will not exceed 20. 
 * The sum of elements in the given array will not exceed 1000.
 * Your output answer is guaranteed to be fitted in a 32-bit integer.
 * 
 * 
 */
#include<vector>
using namespace std; 

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // P - N = target;
        // P + N = sum;
        // P = (target + sum) / 2;
        // int sum = 0;
        // for (int num: nums)  sum += num;

        // if (sum<target || (sum+target)%2==1) 
        //     return 0;
        
        // target = (sum+target) / 2;
        // vector<int> dp(target+1, 0);
        // dp[0] = 1;
        // for (int num: nums) {
        //     for (int i=target; i>=num; i--) {
        //         dp[i] += dp[i-num];
        //     }
        // }
        // return dp[target];

        int sum = 0;
        for (int num: nums)  sum += num;

        if (sum<target || (sum+target)%2==1) 
            return 0;
        target = (sum+target) / 2;

        int ans = 0;
        DFS(nums, 0, target, ans);
        return ans;
    }
    void DFS(vector<int>& nums, int start, int target, int& ans) {
        if (target==0) 
            ans ++;
        for (int i=start; i<nums.size(); i++) {
            if (target>=nums[i]) 
                DFS(nums, i+1, target-nums[i], ans);
        }
    }
};
// @lc code=end

