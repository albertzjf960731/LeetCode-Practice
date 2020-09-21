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
        vector<int> path;
        vector<bool> visited(nums.size(), false);
        
        DFS(nums, path, res, visited);
        return res;
    }
    
    void DFS(vector<int> nums, vector<int>& path, vector<vector<int>>& res, vector<bool>& visited) {
        if (path.size()==nums.size()) {
            res.push_back(path);
            return;
        } 
        
        for (int i=0; i<nums.size(); i++) {
            if (visited[i]) continue;
            if (i>0 && nums[i]==nums[i-1] && !visited[i-1]) continue;
            
            path.push_back(nums[i]);
            visited[i] = true;
            DFS(nums, path, res, visited);
            path.pop_back();
            visited[i] = false;
        }
    }
            // The reason why not swap back is to maintain the sorted ordered for the rest of the array.

            // swap(nums[i], nums[pos]);

    // void DFS(vector<int>& nums, int pos, vector<vector<int>>& res) {
    //     if (pos==nums.size()) {
    //         res.push_back(nums);
    //         return;
    //     } 
    //     unordered_set<int> visited; //保存当前要交换的位置已经有过哪些数字了
    //     for (int i=pos; i<nums.size(); i++) {
    //         if (!visited.count(nums[i])) {
    //         // if(i==pos || nums[i]!=nums[i-1]) {
    //             visited.insert(nums[i]);
    //             swap(nums[i], nums[pos]);
    //             DFS(nums, pos+1, res);
    //             swap(nums[i], nums[pos]);
    //         }
    //     }
    // }
};
// @lc code=end
// [1,2,2]
