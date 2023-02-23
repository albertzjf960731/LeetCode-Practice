/*
 * @lc app=leetcode id=1712 lang=cpp
 *
 * [1712] Ways to Split Array Into Three Subarrays
 *
 * https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/description/
 *
 * algorithms
 * Medium (32.59%)
 * Likes:    1140
 * Dislikes: 92
 * Total Accepted:    26.2K
 * Total Submissions: 80.3K
 * Testcase Example:  '[1,1,1]'
 *
 * A split of an integer array is good if:
 * 
 * 
 * The array is split into three non-empty contiguous subarrays - named left,
 * mid, right respectively from left to right.
 * The sum of the elements in left is less than or equal to the sum of the
 * elements in mid, and the sum of the elements in mid is less than or equal to
 * the sum of the elements in right.
 * 
 * 
 * Given nums, an array of non-negative integers, return the number of good
 * ways to split nums. As the number may be too large, return it modulo 10^9 +
 * 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,1]
 * Output: 1
 * Explanation: The only good way to split nums is [1] [1] [1].
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,2,2,5,0]
 * Output: 3
 * Explanation: There are three good ways of splitting nums:
 * [1] [2] [2,2,5,0]
 * [1] [2,2] [2,5,0]
 * [1,2] [2,2] [5,0]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [3,2,1]
 * Output: 0
 * Explanation: There is no good way to split nums.
 * 
 * 
 * Constraints:
 * 
 * 
 * 3 <= nums.length <= 10^5
 * 0 <= nums[i] <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size(), mod = 1e9+7;
        for (int i=1; i<n; ++i) nums[i] += nums[i-1];

        long ans = 0;
        for (int i=0, left=0, right=0; i<n-2; ++i) {
            left = max(left, i + 1);
            while (left<n-1 && nums[i]>nums[left]-nums[i]) 
                left += 1;

            right = max(right, left);
            while (right<n-1 && nums[right]-nums[i]<=nums.back()-nums[right]) 
                right += 1;

            ans = (ans + right - left) % mod;
        }
        return ans;

        int n = nums.size(), mod = 1e9+7;
        for (int i=1; i<n; ++i) nums[i] += nums[i-1];

        long ans = 0;
        for (int i=0; i<n-2; ++i) {
            // nums[i] <= nums[j] - nums[i];
            int left = lower_bound(nums.begin()+i+1, nums.end(), 2 * nums[i]) - nums.begin();
            
            // nums[j] - nums[i] <= nums.back() - nums[j];
            int right = upper_bound(nums.begin()+i+1, nums.end()-1, nums[i]+(nums.back()-nums[i])/2) - nums.begin();
           
            if (right <= left) continue;
            ans = (ans + right - left) % mod;
        }
        return ans;

    }
};
// @lc code=end

