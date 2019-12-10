/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (32.86%)
 * Likes:    2566
 * Dislikes: 65
 * Total Accepted:    210.2K
 * Total Submissions: 639.7K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the
 * histogram.
 * 
 * 
 * 
 * 
 * Above is a histogram where width of each bar is 1, given height =
 * [2,1,5,6,2,3].
 * 
 * 
 * 
 * 
 * The largest rectangle is shown in the shaded area, which has area = 10
 * unit.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [2,1,5,6,2,3]
 * Output: 10
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> stack;
        heights.push_back(0);

        int ans = 0;
        for (int i=0; i<heights.size(); i++) {
            while (stack.size()>0 && heights[i] < heights[stack.back()]) {
                int h = heights[stack.back()];
                stack.pop_back();

                int w = stack.size()>0 ? i-stack.back()-1 :i;
                ans = max(ans, h*w);
            }
            stack.push_back(i);
        }
        return ans;
    }
};
// @lc code=end

