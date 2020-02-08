/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 *
 * https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/
 *
 * algorithms
 * Medium (44.37%)
 * Likes:    1274
 * Dislikes: 70
 * Total Accepted:    66.2K
 * Total Submissions: 149.1K
 * Testcase Example:  '[4,3,2,3,5,2,1]\n4'
 *
 * Given an array of integers nums and a positive integer k, find whether it's
 * possible to divide this array into k non-empty subsets whose sums are all
 * equal.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
 * Output: True
 * Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3),
 * (2,3) with equal sums.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= k <= len(nums) <= 16.
 * 0 < nums[i] < 10000.
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int num: nums) sum += num;
        if (k<=0 || sum%k!=0) return false;
        
        vector<int> visited(nums.size(), 0);
        return DFS(nums, visited, 0, k, 0, sum/k);
    }
    bool DFS(vector<int>& nums, vector<int>& visited, int start, int k, int path, int target) {
        if(k==1) 
            return true;
        if (path==target) 
            return DFS(nums, visited, 0, k-1, 0, target);
        for(int i=start; i<nums.size(); i++) {
            if (!visited[i] && nums[i]<=target) {
                visited[i] = 1;
                if (DFS(nums, visited, i+1, k, path+nums[i], target))
                    return true;
                visited[i] = 0;
            }
        }
        return false;
    }
};
// @lc code=end

