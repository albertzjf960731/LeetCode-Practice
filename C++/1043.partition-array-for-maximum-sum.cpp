/*
 * @lc app=leetcode id=1043 lang=cpp
 *
 * [1043] Partition Array for Maximum Sum
 *
 * https://leetcode.com/problems/partition-array-for-maximum-sum/description/
 *
 * algorithms
 * Medium (71.40%)
 * Likes:    3012
 * Dislikes: 218
 * Total Accepted:    66.1K
 * Total Submissions: 92.6K
 * Testcase Example:  '[1,15,7,9,2,5,10]\n3'
 *
 * Given an integer array arr, partition the array into (contiguous) subarrays
 * of length at most k. After partitioning, each subarray has their values
 * changed to become the maximum value of that subarray.
 * 
 * Return the largest sum of the given array after partitioning. Test cases are
 * generated so that the answer fits in a 32-bit integer.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [1,15,7,9,2,5,10], k = 3
 * Output: 84
 * Explanation: arr becomes [15,15,15,9,10,10,10]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
 * Output: 83
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = [1], k = 1
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 500
 * 0 <= arr[i] <= 10^9
 * 1 <= k <= arr.length
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = nums.size();
        vector<int> dp(n+1, 0);

        for (int i=0; i<n; ++i) {
            int curMax = 0;

            for (int j=i; j>=max(0, i-k+1); --j) {
                curMax = max(curMax, nums[j]);
                dp[i+1] = max(dp[i+1], dp[j] + curMax * (i-j+1));
            }
        }
        return dp[n];
    }
};
// @lc code=end

