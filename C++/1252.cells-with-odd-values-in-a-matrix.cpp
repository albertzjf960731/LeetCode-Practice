/*
 * @lc app=leetcode id=1252 lang=cpp
 *
 * [1252] Cells with Odd Values in a Matrix
 *
 * https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/description/
 *
 * algorithms
 * Easy (78.49%)
 * Likes:    792
 * Dislikes: 1161
 * Total Accepted:    82.3K
 * Total Submissions: 104.8K
 * Testcase Example:  '2\n3\n[[0,1],[1,1]]'
 *
 * There is an m x n matrix that is initialized to all 0's. There is also a 2D
 * array indices where each indices[i] = [ri, ci] represents a 0-indexed
 * location to perform some increment operations on the matrix.
 * 
 * For each location indices[i], do both of the following:
 * 
 * 
 * Increment all the cells on row ri.
 * Increment all the cells on column ci.
 * 
 * 
 * Given m, n, and indices, return the number of odd-valued cells in the matrix
 * after applying the increment to all locations in indices.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: m = 2, n = 3, indices = [[0,1],[1,1]]
 * Output: 6
 * Explanation: Initial matrix = [[0,0,0],[0,0,0]].
 * After applying first increment it becomes [[1,2,1],[0,1,0]].
 * The final matrix is [[1,3,1],[1,3,1]], which contains 6 odd numbers.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: m = 2, n = 2, indices = [[1,1],[0,0]]
 * Output: 0
 * Explanation: Final matrix = [[2,2],[2,2]]. There are no odd numbers in the
 * final matrix.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= m, n <= 50
 * 1 <= indices.length <= 100
 * 0 <= ri < m
 * 0 <= ci < n
 * 
 * 
 * 
 * Follow up: Could you solve this in O(n + m + indices.length) time with only
 * O(n + m) extra space?
 * 
 */

// @lc code=start
class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        
        vector<bool> rows(m, false), cols(n, false);
        
        for (int i=0; i<indices.size(); ++i) {
            rows[indices[i][0]] = rows[indices[i][0]] ^ true;
            cols[indices[i][1]] = cols[indices[i][1]] ^ true;
        }
        
        int ans = 0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                ans  += rows[i] ^ cols[j] ? 1: 0;
            }
        }
        return ans;

        int cntRow = 0, cntCol = 0;
        for (int num: rows) cntRow += num ? 1 : 0;
        for (int num: cols) cntCol += num ? 1 : 0;
        
        int ans = (m-cntRow) * cntCol + (n-cntCol) * cntRow;
        return ans;
    }
};
// @lc code=end

