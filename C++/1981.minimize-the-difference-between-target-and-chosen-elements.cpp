/*
 * @lc app=leetcode id=1981 lang=cpp
 *
 * [1981] Minimize the Difference Between Target and Chosen Elements
 *
 * https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/description/
 *
 * algorithms
 * Medium (32.67%)
 * Likes:    594
 * Dislikes: 108
 * Total Accepted:    17K
 * Total Submissions: 52.6K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]\n13'
 *
 * You are given an m x n integer matrix mat and an integer target.
 * 
 * Choose one integer from each row in the matrix such that the absolute
 * difference between target and the sum of the chosen elements is minimized.
 * 
 * Return the minimum absolute difference.
 * 
 * The absolute difference between two numbers a and b is the absolute value of
 * a - b.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: mat = [[1,2,3],[4,5,6],[7,8,9]], target = 13
 * Output: 0
 * Explanation: One possible choice is to:
 * - Choose 1 from the first row.
 * - Choose 5 from the second row.
 * - Choose 7 from the third row.
 * The sum of the chosen elements is 13, which equals the target, so the
 * absolute difference is 0.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: mat = [[1],[2],[3]], target = 100
 * Output: 94
 * Explanation: The best possible choice is to:
 * - Choose 1 from the first row.
 * - Choose 2 from the second row.
 * - Choose 3 from the third row.
 * The sum of the chosen elements is 6, and the absolute difference is 94.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: mat = [[1,2,9,8,7]], target = 6
 * Output: 1
 * Explanation: The best choice is to choose 7 from the first row.
 * The absolute difference is 1.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 70
 * 1 <= mat[i][j] <= 70
 * 1 <= target <= 800
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        vector<set<int>> hset;
        for (vector<int>& row : nums) {
            hset.push_back(set<int>(row.begin(), row.end()));
        }
        
        int ans = INT_MAX;
        vector<unordered_set<int>> visited(nums.size());
        DFS(hset, target, 0, 0, ans, visited);
        return ans;
    }
    
    void DFS(vector<set<int>>& hset, int target, int row, int sum, int& ans,  vector<unordered_set<int>>& visited) {
        if (row == hset.size()) {
            ans = min(ans, abs(target-sum)); 
            return ;
        }
        
        if (visited[row].count(sum)) return;
        for (auto it=hset[row].begin(); it!=hset[row].end(); ++it) {
            DFS(hset, target, row+1, sum + *it, ans, visited);
            if (ans == 0 || sum + *it >target) break;
        }
        visited[row].insert(sum);
        return;
    }
};
// @lc code=end

