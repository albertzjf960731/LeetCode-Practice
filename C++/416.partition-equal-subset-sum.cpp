/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 *
 * https://leetcode.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (42.14%)
 * Likes:    1861
 * Dislikes: 55
 * Total Accepted:    133.2K
 * Total Submissions: 315.8K
 * Testcase Example:  '[1,5,11,5]'
 *
 * Given a non-empty array containing only positive integers, find if the array
 * can be partitioned into two subsets such that the sum of elements in both
 * subsets is equal.
 * 
 * Note:
 * 
 * 
 * Each of the array element will not exceed 100.
 * The array size will not exceed 200.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1, 5, 11, 5]
 * 
 * Output: true
 * 
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1, 2, 3, 5]
 * 
 * Output: false
 * 
 * Explanation: The array cannot be partitioned into equal sum subsets.
 * 
 * 
 * 
 * 
 */
#include<vector>
#include<numeric>
#include<bitset>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
         int target = accumulate(nums.begin(), nums.end(), 0);

        if (target%2==1) return false;
        target /= 2;

        vector<bool> dp(target+1, false);
        dp[0] = true;

        for (int i=0; i<nums.size(); i++) {
            // [1, 2, 5]
            // for (int j=nums[i]; j<=target; j++) {
            for (int j=target; j>=nums[i]; j--) {
                // 当前新nums[i], 初始状态没有放入
                dp[j] = dp[j] || dp[j-nums[i]];
            }
        }
        return dp.back();

    //     bitset<5001> bits(1);
    //     int sum = accumulate(nums.begin(), nums.end(), 0);
    //     for (int num : nums) 
    //         bits |= (bits << num);
        
    //     return !(sum & 1) && bits[sum>>1];
        
    //     int sum = accumulate(nums.begin(), nums.end(), 0);
    //     if (sum%2 == 1) 
    //         return false;
        
    //     sum /= 2;
    //     if(*max_element(nums.begin(), nums.end()) > sum) return false;
    //     sort(nums.begin(), nums.end(), greater<int>());
    //     return DFS(nums, 0, sum);
    // }

    // bool DFS(vector<int>& nums, int start, int target) {
    //     if (target==0) 
    //         return true;
    //     for (int i=start; i<nums.size(); i++) {
    //         if (target>=nums[i])
    //             if(DFS(nums, i+1, target-nums[i]))
    //                 return true;
    //     }
    //     return false;
    }
};
// @lc code=end

