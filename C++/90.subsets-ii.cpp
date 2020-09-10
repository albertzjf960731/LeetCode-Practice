/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (44.51%)
 * Likes:    1235
 * Dislikes: 56
 * Total Accepted:    239.7K
 * Total Submissions: 536.7K
 * Testcase Example:  '[1,2,2]'
 *
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,2]
 * Output:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> path;
        DFS(nums, 0, path, res);
        return res;
    }

    void DFS(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& res) {
        // if (find(res.begin(), res.end(), path) == res.end())
        res.push_back(path);
        for (int i=start; i<nums.size(); i++) {
                if(i==start || nums[i]!=nums[i-1]){
                path.push_back(nums[i]);
                DFS(nums, i+1, path, res);
                path.pop_back();
            }
        }
    }
};
// @lc code=end

