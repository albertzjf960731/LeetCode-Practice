/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 *
 * https://leetcode.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (54.39%)
 * Likes:    832
 * Dislikes: 45
 * Total Accepted:    147.9K
 * Total Submissions: 271.9K
 * Testcase Example:  '3\n7'
 *
 * 
 * Find all possible combinations of k numbers that add up to a number n, given
 * that only numbers from 1 to 9 can be used and each combination should be a
 * unique set of numbers.
 * 
 * Note:
 * 
 * 
 * All numbers will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: k = 3, n = 7
 * Output: [[1,2,4]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: k = 3, n = 9
 * Output: [[1,2,6], [1,3,5], [2,3,4]]
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> path;
        DFS(k, n, 1, path, res);
        return res;
    }
    void DFS(int k, int target, int start, vector<int>& path, vector<vector<int>>& res) {
        if (target<0 || k<0)
            return;
        if (target==0 && k==0) {
            res.push_back(path);
            return;
        }
        for(int i=start; i<=9; i++) {
            path.push_back(i);
            DFS(k-1, target-i, i+1, path, res);
            path.pop_back();
        }
    }
};
// @lc code=end

