/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 *
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (43.31%)
 * Likes:    3014
 * Dislikes: 85
 * Total Accepted:    178.9K
 * Total Submissions: 412.9K
 * Testcase Example:  '[1,1,1]\n2'
 *
 * Given an array of integers and an integer k, you need to find the total
 * number of continuous subarrays whose sum equals to k.
 * 
 * Example 1:
 * 
 * Input:nums = [1,1,1], k = 2
 * Output: 2
 * 
 * 
 * 
 * Note:
 * 
 * The length of the array is in range [1, 20,000].
 * The range of numbers in the array is [-1000, 1000] and the range of the
 * integer k is [-1e7, 1e7].
 * 
 * 
 * 
 */
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> hash_map = {{0, 1}};
        int ans=0, sum=0;
        for (int num: nums) {
            sum += num;
            ans += hash_map[sum-k];
            hash_map[sum]++;
        }
        return ans;
    }
};
// @lc code=end

int main() {
    vector<int> nums = {1, 1, 1};
    int k = 2;
    Solution sol;
    int ans = sol.subarraySum(nums, k);
}