/*
 * @lc app=leetcode id=907 lang=cpp
 *
 * [907] Sum of Subarray Minimums
 *
 * https://leetcode.com/problems/sum-of-subarray-minimums/description/
 *
 * algorithms
 * Medium (30.39%)
 * Likes:    798
 * Dislikes: 57
 * Total Accepted:    18.6K
 * Total Submissions: 61.3K
 * Testcase Example:  '[3,1,2,4]'
 *
 * Given an array of integers A, find the sum of min(B), where B ranges over
 * every (contiguous) subarray of A.
 * 
 * Since the answer may be large, return the answer modulo 10^9 + 7.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [3,1,2,4]
 * Output: 17
 * Explanation: Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2],
 * [1,2,4], [3,1,2,4]. 
 * Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.  Sum is 17.
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 30000
 * 1 <= A[i] <= 30000
 * 
 * 
 * 
 * 
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        // int n = nums.size(), mode = 1e9+7;
        
        // vector<int> dp(n);
        // dp[0] = nums[0];
        // int ans = nums[0];

        // for (int i=1; i<n; ++i) {
        //     if (nums[i]>=nums[i-1]) 
        //         dp[i] = dp[i-1] + nums[i];
        //     else {
        //         int j = i - 1;
        //         while (j>=0 && nums[i]<nums[j]) --j;
        //         if (j<0)
        //             dp[i] = (i+1)*nums[i];
        //         else 
        //             dp[i] = (dp[j] + (i-j) * nums[i]);
        //     }
        //     ans = (ans + dp[i]) % mode;
        // }
        // return ans;

        int n = nums.size(), mode = 1e9+7;
        int ans = 0;
        
        vector<int> stack{{-1}};
        vector<int> dp(n+1);
        for (int i=0; i<n; ++i) {
            while (stack.back()!=-1 && nums[i]<=nums[stack.back()]) {
                stack.pop_back();
            }
            
            dp[i+1] = (dp[stack.back()+1] + (i-stack.back())*nums[i]) % mode;
            
            stack.push_back(i);
            ans = (ans + dp[i+1]) % mode;
        }
        return ans;
    }
};
// @lc code=end

