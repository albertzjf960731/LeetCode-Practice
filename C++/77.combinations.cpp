/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (50.98%)
 * Likes:    1065
 * Dislikes: 58
 * Total Accepted:    244.2K
 * Total Submissions: 477.8K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 * 
 */
#include<vector>
using namespace std; 

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;
        DFS(n, k, 1, path, res);
        return res;
    }
    
    void DFS(int n, int k, int start, vector<int>& path, vector<vector<int>>& res) {
        if (path.size() == k){
            res.push_back(path);
            return;
        }
        for (int i=start; i<=n; i++) {
            path.push_back(i);
            DFS(n, k, i+1, path, res);
            path.pop_back();
        }
    }
};
// @lc code=end

