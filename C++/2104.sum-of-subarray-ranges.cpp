/*
 * @lc app=leetcode id=2104 lang=cpp
 *
 * [2104] Sum of Subarray Ranges
 *
 * https://leetcode.com/problems/sum-of-subarray-ranges/description/
 *
 * algorithms
 * Medium (60.45%)
 * Likes:    941
 * Dislikes: 52
 * Total Accepted:    39K
 * Total Submissions: 64.6K
 * Testcase Example:  '[1,2,3]'
 *
 * You are given an integer array nums. The range of a subarray of nums is the
 * difference between the largest and smallest element in the subarray.
 * 
 * Return the sum of all subarray ranges of nums.
 * 
 * A subarray is a contiguous non-empty sequence of elements within an
 * array.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output: 4
 * Explanation: The 6 subarrays of nums are the following:
 * [1], range = largest - smallest = 1 - 1 = 0 
 * [2], range = 2 - 2 = 0
 * [3], range = 3 - 3 = 0
 * [1,2], range = 2 - 1 = 1
 * [2,3], range = 3 - 2 = 1
 * [1,2,3], range = 3 - 1 = 2
 * So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,3,3]
 * Output: 4
 * Explanation: The 6 subarrays of nums are the following:
 * [1], range = largest - smallest = 1 - 1 = 0
 * [3], range = 3 - 3 = 0
 * [3], range = 3 - 3 = 0
 * [1,3], range = 3 - 1 = 2
 * [3,3], range = 3 - 3 = 0
 * [1,3,3], range = 3 - 1 = 2
 * So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [4,-2,-3,4,1]
 * Output: 59
 * Explanation: The sum of all subarray ranges of nums is 59.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 1000
 * -10^9 <= nums[i] <= 10^9
 * 
 * 
 * 
 * Follow-up: Could you find a solution with O(n) time complexity?
 * 
 */

// @lc code=start
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> min_stack{0}, max_stack{0};
        vector<long long> min_dp(n), max_dp(n);
        min_dp[0] = max_dp[0] = nums[0];
        
        long long ans = 0;
        
        for (int i=1; i<nums.size(); ++i) {
            
            while (!min_stack.empty() && nums[i]<=nums[min_stack.back()])
                min_stack.pop_back();
            if (min_stack.empty()) 
                min_dp[i] = (i+1) * (long long) nums[i];
            else {
                int j = min_stack.back();
                min_dp[i] = min_dp[j] + (i-j) * (long long)nums[i]; 
            }

            while (!max_stack.empty() && nums[i]>=nums[max_stack.back()])
                max_stack.pop_back();
            if (max_stack.empty()) 
                max_dp[i] = (i+1) * (long long)nums[i];
            else {
                int j = max_stack.back();
                max_dp[i] = max_dp[j] + (i-j) * (long long)nums[i]; 
            }
            
            min_stack.push_back(i);
            max_stack.push_back(i);
            ans += max_dp[i] - min_dp[i];            
        }
        return ans;
    }
};
// @lc code=end

