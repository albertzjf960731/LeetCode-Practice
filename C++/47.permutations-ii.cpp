/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (43.26%)
 * Likes:    1406
 * Dislikes: 48
 * Total Accepted:    293.2K
 * Total Submissions: 677.6K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 * 
 */
#include<vector>
#include<unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        DFS(nums, 0, res);
        return res;
    }
    
    // void DFS(vector<int> nums, int pos, vector<vector<int>>& res) {
    //     if (pos==nums.size()) {
    //         res.push_back(nums);
    //         return;
    //     } 
    //     for (int i=pos; i<nums.size(); i++) {
    //         if (i==pos || nums[i]!=nums[pos]) {
    //             swap(nums[i], nums[pos]);
    //             DFS(nums, pos+1, res);
    //         }
    //     }
    // }
            // The reason why not swap back is to maintain the sorted ordered for the rest of the array.

            // swap(nums[i], nums[pos]);

    void DFS(vector<int>& nums, int pos, vector<vector<int>>& res) {
        if (pos==nums.size()) {
            res.push_back(nums);
            return;
        } 
        unordered_set<int> visited; //保存当前要交换的位置已经有过哪些数字了
        for (int i=pos; i<nums.size(); i++) {
            if (!visited.count(nums[i])) {
            // if(i==pos || nums[i]!=nums[i-1]) {
                visited.insert(nums[i]);
                swap(nums[i], nums[pos]);
                DFS(nums, pos+1, res);
                swap(nums[i], nums[pos]);
            }
        }
    }
};
// @lc code=end
// [1,2,2]
