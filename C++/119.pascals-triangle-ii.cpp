/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (50.72%)
 * Likes:    1039
 * Dislikes: 202
 * Total Accepted:    324.6K
 * Total Submissions: 637.9K
 * Testcase Example:  '3'
 *
 * Given an integer rowIndex, return the rowIndex^th row of the Pascal's
 * triangle.
 * 
 * Notice that the row index starts from 0.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Follow up:
 * 
 * Could you optimize your algorithm to use only O(k) extra space?
 * 
 * 
 * Example 1:
 * Input: rowIndex = 3
 * Output: [1,3,3,1]
 * Example 2:
 * Input: rowIndex = 0
 * Output: [1]
 * Example 3:
 * Input: rowIndex = 1
 * Output: [1,1]
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= rowIndex <= 40
 * 
 * 
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1);
        res[0] = 1;
        for (int i=1; i<=rowIndex; ++i) {
            for (int j=i; j>=1; --j) {
                res[j] += res[j-1];
            }
        }
        return res;
    }
};
// @lc code=end

