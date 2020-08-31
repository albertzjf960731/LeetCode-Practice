/*
 * @lc app=leetcode id=795 lang=cpp
 *
 * [795] Number of Subarrays with Bounded Maximum
 *
 * https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/description/
 *
 * algorithms
 * Medium (45.08%)
 * Likes:    445
 * Dislikes: 39
 * Total Accepted:    15.2K
 * Total Submissions: 33.8K
 * Testcase Example:  '[2,1,4,3]\n2\n3'
 *
 * We are given an array A of positive integers, and two positive integers L
 * and R (L <= R).
 * 
 * Return the number of (contiguous, non-empty) subarrays such that the value
 * of the maximum array element in that subarray is at least L and at most R.
 * 
 * 
 * Example :
 * Input: 
 * A = [2, 1, 4, 3]
 * L = 2
 * R = 3
 * Output: 3
 * Explanation: There are three subarrays that meet the requirements: [2], [2,
 * 1], [3].
 * 
 * 
 * Note:
 * 
 * 
 * L, R  and A[i] will be an integer in the range [0, 10^9].
 * The length of A will be in the range of [1, 50000].
 * 
 * 
 */
#include<vector>
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int L, int R) {
        // int ans=0;
        // int left=-1, right=-1;
        // for (int i=0; i<nums.size(); i++) {
        //     if (nums[i]>R) left=i;
        //     if (nums[i]>=L) right=i;
        //     ans += right-left;
        // }
        // return ans;

        return helper(nums, R) - helper(nums, L-1);
    }
    int helper(vector<int>& nums, int bound) {
        int cur = 0, ans = 0;
        for (int num: nums) {
            cur = (num <= bound) ? cur + 1 : 0;
            ans += cur;
        }
        return ans;
    }
};
// @lc code=end

