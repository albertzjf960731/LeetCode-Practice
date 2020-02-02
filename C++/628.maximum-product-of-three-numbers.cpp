/*
 * @lc app=leetcode id=628 lang=cpp
 *
 * [628] Maximum Product of Three Numbers
 *
 * https://leetcode.com/problems/maximum-product-of-three-numbers/description/
 *
 * algorithms
 * Easy (46.81%)
 * Likes:    880
 * Dislikes: 312
 * Total Accepted:    94.7K
 * Total Submissions: 202.2K
 * Testcase Example:  '[1,2,3]'
 *
 * Given an integer array, find three numbers whose product is maximum and
 * output the maximum product.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3]
 * Output: 6
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3,4]
 * Output: 24
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The length of the given array will be in range [3,10^4] and all elements are
 * in the range [-1000, 1000].
 * Multiplication of any three numbers in the input won't exceed the range of
 * 32-bit signed integer.
 * 
 * 
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // int size=nums.size();
        // int ans = max(nums[size-1]*nums[0]*nums[1], nums[size-1]*nums[size-2]*nums[size-3]);
        // return ans;

        int max1=INT_MIN, max2=INT_MIN, max3=INT_MIN;
        int min1=INT_MAX, min2=INT_MAX;
        for(int num: nums){
            if (num>max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            }
            else if (num>max2){
                max3 = max2;
                max2 = num;
            }
            else if (num>max3) {
                max3 = num;
            }

            if (num<min1) {
                min2 = min1;
                min1 = num;
            }
            else if (num<min2){
                min2 = num;
            }
        }
        return max(max1*max2*max3, max1*min1*min2);
    }
};
// @lc code=end

