/*
 * @lc app=leetcode id=1695 lang=cpp
 *
 * [1695] Maximum Erasure Value
 *
 * https://leetcode.com/problems/maximum-erasure-value/description/
 *
 * algorithms
 * Medium (52.42%)
 * Likes:    937
 * Dislikes: 19
 * Total Accepted:    45.8K
 * Total Submissions: 86.1K
 * Testcase Example:  '[4,2,4,5,6]'
 *
 * You are given an array of positive integers nums and want to erase a
 * subarray containing unique elements. The score you get by erasing the
 * subarray is equal to the sum of its elements.
 * 
 * Return the maximum score you can get by erasing exactly one subarray.
 * 
 * An array b is called to be a subarray of a if it forms a contiguous
 * subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some
 * (l,r).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,2,4,5,6]
 * Output: 17
 * Explanation: The optimal subarray here is [2,4,5,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,2,1,2,5,2,1,2,5]
 * Output: 8
 * Explanation: The optimal subarray here is [5,2,1] or [1,2,5].
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0, sum = 0;
        int left = 0, right = 0;
        unordered_set<int> hset;
        
        while (right < nums.size()) {
            while (hset.count(nums[right])) {
                hset.erase(nums[left]);
                sum -= nums[left];
                left ++;
            }
            
            sum += nums[right];
            ans = max(ans, sum);
            
            hset.insert(nums[right]);
            right++;
        }
        return ans;
    }
};
// @lc code=end

