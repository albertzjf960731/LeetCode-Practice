/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (52.75%)
 * Likes:    1713
 * Dislikes: 118
 * Total Accepted:    405.3K
 * Total Submissions: 765.3K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 * 
 */

#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows, vector<int>());
        for (int i=0; i<numRows; ++i) {
            
            res[i].resize(i+1, 1);
            for (int j=1; j<i; ++j) {
                res[i][j] = res[i-1][j-1] + res[i-1][j];
            }
        }
        return res;
    }
};
// @lc code=end

