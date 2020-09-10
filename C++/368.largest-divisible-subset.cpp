/*
 * @lc app=leetcode id=368 lang=cpp
 *
 * [368] Largest Divisible Subset
 *
 * https://leetcode.com/problems/largest-divisible-subset/description/
 *
 * algorithms
 * Medium (37.90%)
 * Likes:    1479
 * Dislikes: 72
 * Total Accepted:    98.7K
 * Total Submissions: 260.2K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct positive integers, find the largest subset such that
 * every pair (Si, Sj) of elements in this subset satisfies:
 * 
 * Si % Sj = 0 or Sj % Si = 0.
 * 
 * If there are multiple solutions, return any subset is fine.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: [1,2,3]
 * Output: [1,2] (of course, [1,3] will also be ok)
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,4,8]
 * Output: [1,2,4,8]
 * 
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n =nums.size();
        vector<pair<int, int>> dp(n);
        int max_len = 0, max_idx = 0;
        for (int i=0; i<n; ++i) {
            for (int j=i; j>=0; --j) {
                if (nums[i]%nums[j]==0 && dp[i].first<dp[j].first+1) {
                    dp[i].first = dp[j].first + 1;
                    dp[i].second = j;
                    if (max_len < dp[i].first) {
                        max_len = dp[i].first;
                        max_idx = i;
                    }
                }
            }
        }
        
        vector<int> res;
        for (int i=0, idx=max_idx; i<max_len; ++i) {
            res.push_back(nums[idx]);
            idx = dp[idx].second;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

