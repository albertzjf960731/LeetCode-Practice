/*
 * @lc app=leetcode id=1031 lang=cpp
 *
 * [1031] Maximum Sum of Two Non-Overlapping Subarrays
 *
 * https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/description/
 *
 * algorithms
 * Medium (55.82%)
 * Likes:    360
 * Dislikes: 21
 * Total Accepted:    13K
 * Total Submissions: 23.3K
 * Testcase Example:  '[0,6,5,2,2,5,1,9,4]\n1\n2'
 *
 * Given an array A of non-negative integers, return the maximum sum of
 * elements in two non-overlapping (contiguous) subarrays, which have lengths L
 * and M.  (For clarification, the L-length subarray could occur before or
 * after the M-length subarray.)
 * 
 * Formally, return the largest V for which V = (A[i] + A[i+1] + ... +
 * A[i+L-1]) + (A[j] + A[j+1] + ... + A[j+M-1]) and either:
 * 
 * 
 * 0 <= i < i + L - 1 < j < j + M - 1 < A.length, or
 * 0 <= j < j + M - 1 < i < i + L - 1 < A.length.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: A = [0,6,5,2,2,5,1,9,4], L = 1, M = 2
 * Output: 20
 * Explanation: One choice of subarrays is [9] with length 1, and [6,5] with
 * length 2.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: A = [3,8,1,3,2,1,8,9,0], L = 3, M = 2
 * Output: 29
 * Explanation: One choice of subarrays is [3,8,1] with length 3, and [8,9]
 * with length 2.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: A = [2,1,5,6,0,9,5,0,3,8], L = 4, M = 3
 * Output: 31
 * Explanation: One choice of subarrays is [5,6,0,9] with length 4, and [3,8]
 * with length 3.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * L >= 1
 * M >= 1
 * L + M <= A.length <= 1000
 * 0 <= A[i] <= 1000
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
    int maxSumTwoNoOverlap(vector<int>& nums, int len1, int len2) {
        return max(maxSumTwoSubarray(nums, len1, len2), maxSumTwoSubarray(nums, len2, len1));
    }

    int maxSumTwoSubarray(vector<int>& nums, int len_l, int len_r) {
        // for (int i=1; i<nums.size(); ++i) 
        //     nums[i] += nums[i-1];
        
        // int ans = nums[len_l+len_r-1];
        // int left=nums[len_l-1];
        
        // for (int i=len_l+len_r; i<nums.size(); i++) {
        //     left = max(left, nums[i-len_r]-nums[i-len_l-len_r]);
        //     ans = max(ans, left + nums[i]-nums[i-len_r]);
        // }
        // return ans;

        int ans = INT_MIN;

        vector<int> left_sums(nums.size()+1, 0), right_sums(nums.size()+1, 0);
        for (int i=0, j=nums.size()-1, sum_l=0, sum_r=0; i<nums.size(); i++, j--) {
            sum_l += nums[i], sum_r += nums[j];
            left_sums[i+1] = max(left_sums[i], sum_l);
            right_sums[j] = max(right_sums[j+1], sum_r);
            if (i+1 >= len_l) sum_l -= nums[i+1-len_l];
            if (i+1 >= len_r) sum_r -= nums[j+len_r-1];
        }
        for(int i=0; i<nums.size(); i++) 
            ans = max(ans, left_sums[i]+right_sums[i]);
        return ans;
    }
};
// @lc code=end

