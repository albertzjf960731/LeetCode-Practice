/*
 * @lc app=leetcode id=325 lang=cpp
 *
 * [325] Maximum Size Subarray Sum Equals k
 *
 * 
 * Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.
 * 
 * Example 1:
 * Given nums = [1, -1, 5, -2, 3], k = 3,
 * return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)
 * 
 * Example 2:
 * Given nums = [-2, -1, 2, 1], k = 1,
 * return 2. (because the subarray [-1, 2] sums to 1 and is the longest)
 * 
 * Follow Up:
 * Can you do it in O(n) time?
 * 
 * 
 * 
 */
#include<vector>
#include<deque>
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int sum = 0, ans = 0;
        unordered_map<int, int> hash_map{{0, -1}};

        for (int i=0; i<nums.size(); ++i) {
            sum += nums[i];
            if (hash_map.count(sum-k)) 
                ans = max(ans, i-hash_map[sum-k]);
            else
                hash_map[sum] = i;
        }
        return ans;
    }
};
// @lc code=end

