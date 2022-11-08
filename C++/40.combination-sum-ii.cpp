/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (53.16%)
 * Likes:    7251
 * Dislikes: 177
 * Total Accepted:    667.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sum to target.
 * 
 * Each number in candidates may only be used once in the combination.
 * 
 * Note: The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [10,1,2,7,6,1,5], target = 8
 * Output: 
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5
 * Output: 
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> res;
        vector<int> path;

        DFS(candidates, target, 0, path, res);
        return res;
    }

    void DFS(vector<int>& nums, int target, int index, vector<int>& path, vector<vector<int>>& res) {
        if(target<0) 
            return;
        else if (target==0)
            res.push_back(path);
        else {
            for(int i=index; i<nums.size(); i++) {
                // 防止重复！
                if (i==index || nums[i]!=nums[i-1]){
                    path.push_back(nums[i]);
                    DFS(nums, target-nums[i], i+1, path, res);
                    path.pop_back();
                }
            }
        }
    }
};
// @lc code=end
