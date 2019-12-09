/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 *
 * https://leetcode.com/problems/triangle/description/
 *
 * algorithms
 * Medium (41.53%)
 * Likes:    1445
 * Dislikes: 168
 * Total Accepted:    211K
 * Total Submissions: 508.1K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * Given a triangle, find the minimum path sum from top to bottom. Each step
 * you may move to adjacent numbers on the row below.
 * 
 * For example, given the following triangle
 * 
 * 
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 * 
 * 
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 * 
 * Note:
 * 
 * Bonus point if you are able to do this using only O(n) extra space, where n
 * is the total number of rows in the triangle.
 * 
 */

#include<vector>
#include<algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // updown
        // if (triangle.empty())
        //     return 0;

        // vector<int> dp(triangle.size(), 0);
        // dp[0] = triangle[0][0];

        // for (int i=1; i<triangle.size(); i++) {
        //     for (int j=i; j>-1; j--) {
        //         if (j==0) 
        //             dp[j] = triangle[i][j] + dp[j];
        //         else if (j==i)  
        //             dp[j] = triangle[i][j] + dp[j-1];
        //         else 
        //             dp[j] = triangle[i][j] + min(dp[j-1], dp[j]);
        //     }
        // }
        // return *min_element(dp.begin(), dp.end());
        
        vector<int> dp = triangle[triangle.size()-1];
        for (int i=triangle.size()-2; i>-1; i--) {
            for (int j=0; j<i+1; j++){
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
        }
        return dp[0];
    }
};
// @lc code=end

