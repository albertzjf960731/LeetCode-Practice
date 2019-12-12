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
using namespace std;

// @lc code=start
class Solution {
public:
    // vector<vector<int>> permuteUnique(vector<int>& nums) {
    //     sort(nums.begin(), nums.begin());

    //     vector<vector<int>> res;
    //     DFS(nums, res, 0);
    //     return res;
    // }

    // void DFS(vector<int> nums, vector<vector<int>>& res, int pos) {
    //     if (pos==nums.size()-1) {
    //         res.push_back(nums);
    //         return;
    //     }

    //     for (int i=pos; i<nums.size(); i++) {
    //         if (i!=pos && nums[i] == nums[pos]) 
    //             continue;
    //         swap(nums[i], nums[pos]);
    //         DFS(nums, res, pos+1);
    //         // The reason why not swap back is to maintain the sorted ordered for the rest of the array.

    //         // swap(nums[i], nums[pos]);
    //     }
    // }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        DFS(nums, res, 0);
        return res;
    }

    void DFS(vector<int> nums, vector<vector<int>>& res, int pos) {
        if(pos == nums.size()-1) {
            res.push_back(nums);
            return;
        }

        for(int i=pos; i<nums.size(); i++) {
            int j = i-1;
            //judge whether num[i] and num[pos...i-1] are equal
            while(j>=pos && nums[j]!=nums[i])
                j--;
            if(i==pos || j==pos-1) {
                swap(nums[i], nums[pos]);
                DFS(nums, res, pos+1);
                swap(nums[i], nums[pos]);
            }
        }
        
    }
};
// @lc code=end
// [1,2,2]
