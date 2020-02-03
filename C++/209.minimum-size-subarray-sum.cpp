/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 *
 * https://leetcode.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (36.50%)
 * Likes:    1656
 * Dislikes: 91
 * Total Accepted:    222.6K
 * Total Submissions: 609.5K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * Given an array of n positive integers and a positive integer s, find the
 * minimal length of a contiguous subarray of which the sum ≥ s. If there isn't
 * one, return 0 instead.
 * 
 * Example: 
 * 
 * 
 * Input: s = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 * Explanation: the subarray [4,3] has the minimal length under the problem
 * constraint.
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution of
 * which the time complexity is O(n log n). 
 * 
 */
#include<vector>
#include<numeric>
using namespace std;

// @lc code=start
class Solution {
public:
    // int minSubArrayLen(int s, vector<int>& nums) {
    //     int left=0, right=nums.size();
    //     while (left<right) {
    //         int mid = left + (right-left)/2;
    //         if (!isLarge(nums, s, mid)) 
    //             left = mid+1;
    //         else 
    //             right = mid;
    //     }
    //     if (left==nums.size() && accumulate(nums.begin(), nums.end(), 0)<s)
    //         return 0;
    //     return left;
    // }

    // bool isLarge(vector<int>& nums, int s, int k) {

    //     int sum = 0;
    //     for (int i=0; i<k; ++i)
    //         sum += nums[i];
        
    //     int ans = sum;
    //     for (int i=k; i<nums.size(); ++i) {
    //         sum += nums[i] - nums[i-k];
    //         ans = max(ans ,sum);
    //     }
    //     return ans >= s;
    // }

    int minSubArrayLen(int s, vector<int>& nums) {
        int sum=0, len=INT_MAX;
        int left=0, right=0;

        while (right < nums.size()) {
            sum += nums[right++];
            while (sum>=s) {
                len = min(len, right-left);
                sum -= nums[left++];
            }
        }
        return len == INT_MAX ? 0 : len;
    }
};
// @lc code=end

