/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (41.79%)
 * Likes:    3564
 * Dislikes: 80
 * Total Accepted:    305.1K
 * Total Submissions: 729K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * Given an unsorted array of integers, find the length of longest increasing
 * subsequence.
 * 
 * Example:
 * 
 * 
 * Input: [10,9,2,5,3,7,101,18]
 * Output: 4 
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore
 * the length is 4. 
 * 
 * Note: 
 * 
 * 
 * There may be more than one LIS combination, it is only necessary for you to
 * return the length.
 * Your algorithm should run in O(n^2) complexity.
 * 
 * 
 * Follow up: Could you improve it to O(n log n) time complexity?
 * 
 */
#include<iostream>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    // int lengthOfLIS(vector<int>& nums) {
    //     int nums_size = nums.size();
    //     if (nums_size==0) return 0;

    //     vector<int> dp(nums_size, 1);

    //     for(int i=1; i<nums_size; ++i) {
    //         for(int j=0; j<i; --j) {
    //             if(nums[i]>nums[j]) 
    //                 dp[i] = max(dp[i], dp[j]+1);
    //         }
    //     }
    //     return *max_element(dp.begin(), dp.end());
    // }

    // 递增序列，当前最小
    // 4, 2, 4, 5, 3, 7 => 2, 3, 5, 7
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;

        for(int i=0; i<nums.size(); ++i) {
            auto it = lower_bound(res.begin(), res.end(), nums[i]);
            if(it==res.end())
                res.push_back(nums[i]);
            else 
                *it = nums[i];
        }
        return res.size();
    }

};
// @lc code=end

int main(){
    Solution sol;
    vector<int> nums{10,9,2,5,3,7,101,18};
    cout << sol.lengthOfLIS(nums) << endl;
}
