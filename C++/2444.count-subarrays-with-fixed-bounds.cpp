/*
 * @lc app=leetcode id=2444 lang=cpp
 *
 * [2444] Count Subarrays With Fixed Bounds
 *
 * https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/
 *
 * algorithms
 * Hard (44.85%)
 * Likes:    1212
 * Dislikes: 22
 * Total Accepted:    24.9K
 * Total Submissions: 45.7K
 * Testcase Example:  '[1,3,5,2,7,5]\n1\n5'
 *
 * You are given an integer array nums and two integers minK and maxK.
 * 
 * A fixed-bound subarray of nums is a subarray that satisfies the following
 * conditions:
 * 
 * 
 * The minimum value in the subarray is equal to minK.
 * The maximum value in the subarray is equal to maxK.
 * 
 * 
 * Return the number of fixed-bound subarrays.
 * 
 * A subarray is a contiguous part of an array.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
 * Output: 2
 * Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,1,1,1], minK = 1, maxK = 1
 * Output: 10
 * Explanation: Every subarray of nums is a fixed-bound subarray. There are 10
 * possible subarrays.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= nums.length <= 10^5
 * 1 <= nums[i], minK, maxK <= 10^6
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
         long long ans = 0;
        int start = 0, minIdx = 0, maxIdx = 0;
        bool minFound = false, maxFound = false;

        for (int i=0; i<nums.size(); ++i) {
            if (nums[i]<minK || nums[i]>maxK) {
                minFound = false;
                maxFound = false;
                start = i + 1;
            }

            if (nums[i]==minK) {
                minIdx = i;
                minFound = true;
            }
            if (nums[i]==maxK) {
                maxIdx = i;
                maxFound = true;
            }
            if (minFound && maxFound) {
                ans += (min(minIdx, maxIdx) - start + 1);
            }
        }
        return ans;


        long long a = helper(nums, minK, maxK);
        long long b = helper(nums, minK+1, maxK-1);
        long long c = helper(nums, minK+1, maxK);
        long long d = helper(nums, minK, maxK-1);
        return a + b - c - d;
    }
    
    long long helper(vector<int>& nums, int minK, int maxK) {
        // min >= minK && max <= maxK
        
        int i = 0, n = nums.size();
        long long ans = 0;
        while (i < n) {
            if (nums[i] > maxK || nums[i] < minK) {
                i += 1;
                continue;
            }
            
            long long cnt = 0;
            while (i<n && nums[i]>=minK && nums[i]<=maxK) {
                i += 1;
                cnt += 1;
            }
            ans += (cnt * (cnt + 1) / 2);
        }
        return ans;
    }
    
};
// @lc code=end

