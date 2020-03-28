/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 *
 * https://leetcode.com/problems/missing-number/description/
 *
 * algorithms
 * Easy (50.12%)
 * Likes:    1337
 * Dislikes: 1738
 * Total Accepted:    374.5K
 * Total Submissions: 747K
 * Testcase Example:  '[3,0,1]'
 *
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
 * find the one that is missing from the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,0,1]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [9,6,4,2,3,5,7,0,1]
 * Output: 8
 * 
 * 
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant extra space complexity?
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for (int num: nums) sum += num;

        int n = nums.size();
        return (n+1)*n/2-sum;


        int ans = nums.size();
        for (int i=0; i<nums.size(); i++) 
            ans = ans ^ i ^ nums[i];
        return ans;

        for (int i=0; i<nums.size(); i++) {
            while (nums[i]>=0 && nums[i]<nums.size() && nums[nums[i]] != nums[i]) 
                swap(nums[nums[i]], nums[i]);
        }
        
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] != i)
                return i;
        }
        return nums.size();
    }
};
// @lc code=end

