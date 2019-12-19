/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (56.59%)
 * Likes:    2658
 * Dislikes: 62
 * Total Accepted:    454.8K
 * Total Submissions: 801.8K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */
#include<vector>
using namespace std; 

// @lc code=start
class Solution {
public:
    // vector<vector<int>> subsets(vector<int>& nums) {
    //     vector<vector<int>> res;
    //     res.push_back(vector<int>());

    //     for (int num: nums) {
    //         int size = res.size();
    //         for (int i=0; i<size; i++) {
    //             vector<int> item = res[i];
    //             item.push_back(num);
    //             res.push_back(item);
    //         }
    //     }
    //     return res;
    // }

    // vector<vector<int>> subsets(vector<int>& nums) {
    //     vector<vector<int>> res;
    //     vector<int> path;
    //     DFS(nums, 0, path, res);
    //     return res;
    // }
    // void DFS(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& res) {
    //     res.push_back(path);
    //     for (int i=start; i<nums.size(); i++) {
    //         path.push_back(nums[i]);
    //         DFS(nums, i+1, path, res);
    //         path.pop_back();
    //     }
    // }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        for (int i=0; i<(1<<nums.size()); i++){
            vector<int> item;
            for (int j=0; j<nums.size(); j++) {
                if (i & (1<<j))
                    item.push_back(nums[j]);
            }
            res.push_back(item);
        }    
        return res;
    }

};
// @lc code=end

