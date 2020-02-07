/*
 * @lc app=leetcode id=491 lang=cpp
 *
 * [491] Increasing Subsequences
 *
 * https://leetcode.com/problems/increasing-subsequences/description/
 *
 * algorithms
 * Medium (43.73%)
 * Likes:    549
 * Dislikes: 95
 * Total Accepted:    39.5K
 * Total Submissions: 90.2K
 * Testcase Example:  '[4,6,7,7]'
 *
 * Given an integer array, your task is to find all the different possible
 * increasing subsequences of the given array, and the length of an increasing
 * subsequence should be at least 2.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [4, 6, 7, 7]
 * Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7],
 * [4,7,7]]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The length of the given array will not exceed 15.
 * The range of integer in the given array is [-100,100].
 * The given array may contain duplicates, and two equal integers should also
 * be considered as a special case of increasing sequence.
 * 
 * 
 */
#include<vector>
#include<unordered_set>
#include<set>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> path;
        DFS(nums, 0, path, res);
        return vector<vector<int>> (res.begin(), res.end());
    }

    void DFS(vector<int>& nums, int start, vector<int>& path, set<vector<int>>& res) {
        if (path.size()>1) 
            res.insert(path);

        for (int i=start; i<nums.size(); i++) {
            if (path.empty() || nums[i] >= path.back()) {
                path.push_back(nums[i]);
                DFS(nums, i+1, path, res);
                path.pop_back();
            }
        }
    }
};
// @lc code=end

