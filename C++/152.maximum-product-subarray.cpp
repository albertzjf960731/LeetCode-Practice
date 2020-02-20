/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (30.69%)
 * Likes:    3072
 * Dislikes: 131
 * Total Accepted:    279.1K
 * Total Submissions: 909.4K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Given an integer array nums, find the contiguous subarray within an array
 * (containing at least one number) which has the largest product.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre_max=nums[0], pre_min=nums[0];
        int ans = nums[0];

        for (int i=1; i<nums.size(); ++i) {
            if (nums[i]<0) { 
                int tmp = pre_max;
                pre_max = max(pre_min*nums[i], nums[i]);
                pre_min = min(tmp*nums[i], nums[i]);
            }
            else {
                pre_max = max(pre_max*nums[i], nums[i]);
                pre_min = min(pre_min*nums[i], nums[i]);
            }
            ans = max(ans, pre_max);
        }
        return ans;
    }
};
// @lc code=end

