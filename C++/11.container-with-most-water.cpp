/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

#include<iostream>
#include<string>
#include<vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int l=0, r=height.size()-1;

        while (l<r) {
            ans = max(ans, min(height[l], height[r]) * (r-l));

            // no nested while loop
            if (height[l] < height[r])
                l += 1;
            else 
                r -= 1;
        }
        return ans;
    }
};
// @lc code=end

