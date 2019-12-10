/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 *
 * https://leetcode.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (35.30%)
 * Likes:    1927
 * Dislikes: 55
 * Total Accepted:    145K
 * Total Submissions: 410.6K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
 * containing only 1's and return its area.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * ⁠ ["1","0","1","0","0"],
 * ⁠ ["1","0","1","1","1"],
 * ⁠ ["1","1","1","1","1"],
 * ⁠ ["1","0","0","1","0"]
 * ]
 * Output: 6
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        if (matrix.empty())
            return ans;

        vector<int> heights(matrix[0].size()+1, 0);;
        
        for (int i=0; i<matrix.size(); i++) {
            vector<int> stack;

            for (int j=0; j<heights.size(); j++) {
                if (j<matrix[0].size()) {
                    if (matrix[i][j]=='1')
                        heights[j]++;
                    else
                        heights[j] = 0;
                }

                while (stack.size()>0 && heights[j] < heights[stack.back()]) {
                    int h = heights[stack.back()];
                    stack.pop_back();

                    int w = stack.size()>0 ? j-stack.back()-1 :j;
                    ans = max(ans, h*w);
                }
                stack.push_back(j);
            }
        }
        return ans;
    }
};
// @lc code=end

