/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (45.17%)
 * Likes:    5682
 * Dislikes: 239
 * Total Accepted:    707.3K
 * Total Submissions: 1.6M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 以下标 i 结尾的子数组的元素的最大的和
        
        // vector<int> dp(nums.size(), 0);
        // dp[0] = nums[0];
        // for (int i=1; i<nums.size(); i++) {
        //     dp[i] = max(dp[i-1]+nums[i], nums[i]);
        // }
        // return *max_element(dp.begin(), dp.end());

        int pre=nums[0], ans = nums[0];
        for (int i=1; i<nums.size(); i++) {
            pre = max(pre+nums[i], nums[i]);
            ans = max(ans, pre);
        }        
        return ans;
    }

    int maxSumMatrix(vector<vector<int>>& matrix) {
        int ans = INT_MIN;

        int rows=matrix.size(), cols=matrix[0].size();

        for (int left=0; left<cols; left++) {
            
            vector<int> sums(rows, 0);
            for (int right=left; right<cols; right++) {
                for (int i=0; i<rows; i++)
                    sums[i] += matrix[i][right];
                
                int pre=sums[0], sum=sums[0];
                for (int i=1; i<rows; i++) {
                    pre = max(pre+sums[i], sums[i]);
                    sum = max(sum, pre);
                }
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};
// @lc code=end

