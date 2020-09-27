/*
 * @lc app=leetcode id=850 lang=cpp
 *
 * [850] Rectangle Area II
 *
 * https://leetcode.com/problems/rectangle-area-ii/description/
 *
 * algorithms
 * Hard (46.29%)
 * Likes:    256
 * Dislikes: 27
 * Total Accepted:    9.5K
 * Total Submissions: 20.6K
 * Testcase Example:  '[[0,0,2,2],[1,0,2,3],[1,0,3,1]]'
 *
 * We are given a list of (axis-aligned) rectangles.  Each rectangle[i] = [x1,
 * y1, x2, y2] , where (x1, y1) are the coordinates of the bottom-left corner,
 * and (x2, y2) are the coordinates of the top-right corner of the ith
 * rectangle.
 * 
 * Find the total area covered by all rectangles in the plane.  Since the
 * answer may be too large, return it modulo 10^9 + 7.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[0,0,2,2],[1,0,2,3],[1,0,3,1]]
 * Output: 6
 * Explanation: As illustrated in the picture.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[0,0,1000000000,1000000000]]
 * Output: 49
 * Explanation: The answer is 10^18 modulo (10^9 + 7), which is (10^9)^2 =
 * (-7)^2 = 49.
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= rectangles.length <= 200
 * rectanges[i].length = 4
 * 0 <= rectangles[i][j] <= 10^9
 * The total area covered by all rectangles will never exceed 2^63 - 1 and thus
 * will fit in a 64-bit signed integer.
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        vector<vector<int>> nums;
        for (auto &item : rectangles) {
            helper(nums, item, 0);
        }
        
        long ans = 0, mode = 1e9 + 7;
        for (auto &item : nums) {
            ans = (ans + (long)(item[2]-item[0]) *(long) (item[3]-item[1])) % mode;
        }
        return ans;
    }
    
    void helper(vector<vector<int>>& nums, vector<int> cur, int idx) {
        if (idx >= nums.size()) {
            nums.push_back(cur); 
            return;
        }
        
        auto rec = nums[idx];
        if (cur[2]<=rec[0] || cur[3]<=rec[1] || cur[0]>=rec[2] || cur[1]>=rec[3]) {
            helper(nums, cur, idx+1); 
            return;
        }
        if (cur[0] < rec[0]) {
            helper(nums, {cur[0], cur[1], 
                          rec[0], cur[3]}, idx+1);
        }
        if (cur[2] > rec[2]) {
            helper(nums, {rec[2], cur[1], 
                          cur[2], cur[3]}, idx+1);
        }
        if (cur[1] < rec[1]) {
            helper(nums, {max(rec[0],cur[0]), cur[1], 
                          min(rec[2],cur[2]), rec[1]}, idx+1);
        }
        if (cur[3] > rec[3]) {
            helper(nums, {max(rec[0], cur[0]), rec[3],
                          min(rec[2], cur[2]), cur[3]}, idx+1);
        }
    }
};
// @lc code=end

