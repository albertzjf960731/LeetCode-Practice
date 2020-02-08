/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 *
 * https://leetcode.com/problems/combination-sum-iv/description/
 *
 * algorithms
 * Medium (44.39%)
 * Likes:    1101
 * Dislikes: 134
 * Total Accepted:    106.1K
 * Total Submissions: 239K
 * Testcase Example:  '[1,2,3]\n4'
 *
 * Given an integer array with all positive numbers and no duplicates, find the
 * number of possible combinations that add up to a positive integer target.
 * 
 * Example:
 * 
 * 
 * nums = [1, 2, 3]
 * target = 4
 * 
 * The possible combination ways are:
 * (1, 1, 1, 1)
 * (1, 1, 2)
 * (1, 2, 1)
 * (1, 3)
 * (2, 1, 1)
 * (2, 2)
 * (3, 1)
 * 
 * Note that different sequences are counted as different combinations.
 * 
 * Therefore the output is 7.
 * 
 * 
 * 
 * 
 * Follow up:
 * What if negative numbers are allowed in the given array?
 * How does it change the problem?
 * What limitation we need to add to the question to allow negative numbers?
 * 
 * Credits:
 * Special thanks to @pbrother for adding this problem and creating all test
 * cases.
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
    //     vector<vector<int>> res;
    //     vector<int> path;

    //     DFS(nums, target, path, res);
    //     return res.size();
    // }

    // void DFS(vector<int>& nums, int target, vector<int>& path, vector<vector<int>>& res) {
    //     if(target<0) 
    //         return;
    //     else if (target==0)
    //         res.push_back(path);
    //     else {
    //         for(int i=0; i<nums.size(); i++) {
    //             path.push_back(nums[i]);
    //             DFS(nums, target-nums[i], path, res);
    //             path.pop_back();
    //         }
    //     }
    // }

        // DP: when solve the problem return the count

        // DFS : for return all the possible result


        // 爬楼梯
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for (int i=1; i<=target; i++) {
            for (int num: nums){
                if (num<=i) {
                    dp[i] += dp[i-num];
                    if(dp[i] > INT_MAX) dp[i] %= INT_MAX;
                }
            }
        }
        return dp[target];
    }
};
// @lc code=end

