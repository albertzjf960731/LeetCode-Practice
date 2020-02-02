/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 *
 * https://leetcode.com/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (58.28%)
 * Likes:    3470
 * Dislikes: 297
 * Total Accepted:    375.3K
 * Total Submissions: 643.8K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given an array nums of n integers where n > 1,  return an array output such
 * that output[i] is equal to the product of all the elements of nums except
 * nums[i].
 * 
 * Example:
 * 
 * 
 * Input:  [1,2,3,4]
 * Output: [24,12,8,6]
 * 
 * 
 * Note: Please solve it without division and in O(n).
 * 
 * Follow up:
 * Could you solve it with constant space complexity? (The output array does
 * not count as extra space for the purpose of space complexity analysis.)
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;

        int prod = 1;
        for (int i=0; i<nums.size(); ++i) {
            res.push_back(prod);
            prod *= nums[i];
        }

        prod = 1;
        for (int i=nums.size()-1; i>=0; --i) {
            res[i] *= prod;
            prod *= nums[i];
        }

        return res;
    }
};
// @lc code=end

