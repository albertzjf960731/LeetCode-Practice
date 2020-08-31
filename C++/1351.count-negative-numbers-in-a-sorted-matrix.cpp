/*
 * @lc app=leetcode id=1351 lang=cpp
 *
 * [1351] Count Negative Numbers in a Sorted Matrix
 */

// @lc code=start
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i=0, j=grid[0].size()-1; i<grid.size(); i++) {
            while (j>=0 && grid[i][j]<0)
                j--;
            ans += grid[0].size()-1-j;
        }
        return ans;
    }
};
// @lc code=end

