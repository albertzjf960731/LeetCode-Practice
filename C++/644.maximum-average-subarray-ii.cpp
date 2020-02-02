/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [644] Maximum Average Subarray II
 *
 * https://leetcode.com/problems/maximum-average-subarray-i/description/
 *
 * Given an array consisting of n integers, find the contiguous subarray find the contiguous subarray whose length is greater than or equal to k that has the maximum average value. 
 * And you need to output the maximum average value.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,12,-5,-6,50,3], k = 4
 * Output: 12.75
 * Explanation:
 * when length is 5, maximum average value is 10.8,
 * when length is 6, maximum average value is 9.16667.
 * Thus return 12.75.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= k <= n <= 10,000.
 * Elements of the given array will be in range [-10,000, 10,000].
 * The answer with the calculation error less than 10-5 will be accepted.
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
    double findMaxAverage(vector<int>& nums, int k) {

        // 每次找到left和right的平均值mid，对于mid，在数组内找是否存在一个长度大于等于k的连续区间，其平均值大于mid，如果存在，那么说明mid还不是最大平均值，所以修改左边界left；否则说明mid已经大于等于左右长度大于等于k的所有连续区间的最大平均值了，所以此时修改右边界right。这样当left和right逐渐收敛到一点的时候，该收敛点就是最大平均值。

        double left = *min_element(nums.begin(), nums.end());
        double right = *max_element(nums.begin(), nums.end());

        while (right - left > 1e-5) {
            double mid = (left + right) / 2;
            if (isLarger(nums, mid, k)) 
                right = mid;
            else
                left = mid;
        }
        return left;
    }

private:
    bool isLarger(vector<int>& nums, double mid, int k) {

        // cur_sum: the sum from nums[0] to nums[i];
        // prev_sum:  the sum from nums[0] to nums[i-k];
        // min_sum: the minimal sum from nums[0] to nums[j] (0 =<  j <= i-k);
        double cur_sum = 0, prev_sum = 0, min_sum = 0;

        for (int i=0; i<nums.size(); ++i) {
            cur_sum += nums[i] - mid;
            if (i>=k) {
                prev_sum += nums[i-k] - mid;
                min_sum = min(prev_sum, min_sum);
            }

            if(i>=k-1 && cur_sum-min_sum>0) // there exists an range in which the average value is larger
                return false;
        }
        return true;
    }
// @lc code=end
};
