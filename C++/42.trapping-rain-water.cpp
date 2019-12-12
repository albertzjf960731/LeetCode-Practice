/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (45.90%)
 * Likes:    5090
 * Dislikes: 91
 * Total Accepted:    393.5K
 * Total Submissions: 856.7K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 * 
 * 
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        if(height.empty())
            return ans;

        // for (int i=0; i<height.size()-1; i++) {
        //     int max_left = *max_element(height.begin(), height.begin()+i);
        //     int max_right = *max_element(height.begin()+i+1, height.end());

        //     ans += max(
        //         min(max_left, max_right)-height[i], 0);
        // }
        // return ans;

        // int n = height.size();
        // vector<int> max_left(n, 0), max_right(n, 0);
        // for (int i=1; i<n-1; i++)
        //     max_left[i] = max(max_left[i-1], height[i-1]);
        // for (int i=n-2; i>-1; i--)
        //     max_right[i] = max(max_right[i+1], height[i+1]);
        // for (int i=1; i<n-1; i++) {
        //     ans += max(
        //         min(max_left[i], max_right[i])-height[i], 0);
        // }
        // return ans;

        int l=1, r=height.size()-2;
        int max_left=0, max_right=0;
        while (l<=r){
            if (height[l-1]<height[r+1]) {
                max_left = max(max_left, height[l-1]);
                ans += max(max_left-height[l], 0);
                l++;
            }
            else {
                max_right = max(max_right, height[r+1]);
                ans += max(max_right-height[r], 0);
                r--;
            }
        }
        return ans;
    }
};
// @lc code=end

