/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (58.87%)
 * Likes:    2743
 * Dislikes: 89
 * Total Accepted:    476.5K
 * Total Submissions: 808.9K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */
#include<vector>
#include<iostream>
using namespace std; 

// @lc code=start
class Solution {
public:
    // vector<vector<int>> permute(vector<int>& nums) {
    //     vector<vector<int>> res;
    //     vector<int> path;
    //     DFS(nums, res, path);
    //     return res;
    // }

    // void DFS(vector<int>& nums, vector<vector<int>>& res, vector<int>& path) {
    //     if (path.size()==nums.size()) {
    //         res.push_back(path);
    //         return;
    //     }

    //     for (int i=0; i<nums.size(); i++) {
    //         if (find(path.begin(), path.end(), nums[i]) == path.end()) {
    //             path.push_back(nums[i]);
    //             DFS(nums, res, path);
    //             path.pop_back();
    //         }
    //     }
    // }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        DFS(nums, res, 0);
        return res;
    }

    void DFS(vector<int> nums, vector<vector<int>>& res, int pos) {
        if (pos==nums.size()-1) {
            res.push_back(nums);
            return;
        }

        for (int i=pos; i<nums.size(); i++) {
            swap(nums[pos], nums[i]);
            DFS(nums, res, pos+1);
            // swap(nums[pos], nums[i]);
        }
    }
};
// @lc code=end

int main() {
    Solution sol;
    vector<int> nums{1,2,3};
    vector<vector<int>> res = sol.permute(nums);
}