/*
 * @lc app=leetcode id=2401 lang=cpp
 *
 * [2401] Longest Nice Subarray
 *
 * https://leetcode.com/problems/longest-nice-subarray/description/
 *
 * algorithms
 * Medium (48.82%)
 * Likes:    735
 * Dislikes: 16
 * Total Accepted:    18.9K
 * Total Submissions: 38.7K
 * Testcase Example:  '[1,3,8,48,10]'
 *
 * You are given an array nums consisting of positive integers.
 * 
 * We call a subarray of nums nice if the bitwise AND of every pair of elements
 * that are in different positions in the subarray is equal to 0.
 * 
 * Return the length of the longest nice subarray.
 * 
 * A subarray is a contiguous part of an array.
 * 
 * Note that subarrays of length 1 are always considered nice.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,3,8,48,10]
 * Output: 3
 * Explanation: The longest nice subarray is [3,8,48]. This subarray satisfies
 * the conditions:
 * - 3 AND 8 = 0.
 * - 3 AND 48 = 0.
 * - 8 AND 48 = 0.
 * It can be proven that no longer nice subarray can be obtained, so we return
 * 3.
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [3,1,5,11,13]
 * Output: 1
 * Explanation: The length of the longest nice subarray is 1. Any subarray of
 * length 1 can be chosen.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int used = 0, ans = 0;
        for (int left=0, right=0; right<nums.size(); ++right) {
            while ((nums[right] & used) !=0) 
                used ^= nums[left++];

            used |= nums[right];
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};
// @lc code=end

