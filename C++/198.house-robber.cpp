/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 *
 * https://leetcode.com/problems/house-robber/description/
 *
 * algorithms
 * Easy (41.56%)
 * Likes:    3651
 * Dislikes: 116
 * Total Accepted:    428.1K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,3,1]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed, the only constraint stopping
 * you from robbing each of them is that adjacent houses have security system
 * connected and it will automatically contact the police if two adjacent
 * houses were broken into on the same night.
 * 
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money =
 * 3).
 * Total amount you can rob = 1 + 3 = 4.
 * 
 * Example 2:
 * 
 * 
 * Input: [2,7,9,3,1]
 * Output: 12
 * Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house
 * 5 (money = 1).
 * Total amount you can rob = 2 + 9 + 1 = 12.
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        // [2,1,1,2]
        // int rob_odd=0, rob_even=0;
        // for (int i=0; i<nums.size(); ++i) {
        //     if (i%2==0) 
        //         rob_even += nums[i];
        //     else 
        //         rob_odd += nums[i];
        // }
        // return max(rob_even, rob_odd);

        // int prev=0, cur=0, tmp;
        // for (auto num: nums) {
        //     tmp = cur;
        //     cur = max(prev+num, cur);
        //     prev = tmp;
        // }
        // return cur;

        int cur=0;
        int prev1=0, prev2=0;
        for (auto num: nums){
            cur = max(prev1+num, cur);
            prev1 = prev2;
            prev2 = cur;
        }
        return cur;

        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        nums[1] = max(nums[0], nums[1]);
        for (int i=2; i<n; ++i)
            nums[i] = max(nums[i-1], nums[i-2]+nums[i]);
        return nums[n-1];
    }
};
// @lc code=end

