/*
 * @lc app=leetcode id=1658 lang=cpp
 *
 * [1658] Minimum Operations to Reduce X to Zero
 *
 * https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/description/
 *
 * algorithms
 * Medium (33.56%)
 * Likes:    1691
 * Dislikes: 31
 * Total Accepted:    48.9K
 * Total Submissions: 144.6K
 * Testcase Example:  '[1,1,4,2,3]\n5'
 *
 * You are given an integer array nums and an integer x. In one operation, you
 * can either remove the leftmost or the rightmost element from the array nums
 * and subtract its value from x. Note that this modifies the array for future
 * operations.
 * 
 * Return the minimum number of operations to reduce x to exactly 0 if it is
 * possible, otherwise, return -1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,4,2,3], x = 5
 * Output: 2
 * Explanation: The optimal solution is to remove the last two elements to
 * reduce x to zero.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,6,7,8,9], x = 4
 * Output: -1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [3,2,20,1,1,3], x = 10
 * Output: 5
 * Explanation: The optimal solution is to remove the last three elements and
 * the first two elements (5 operations in total) to reduce x to zero.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^4
 * 1 <= x <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = -x;
        for (int num: nums) target += num;
        if (target == 0) return nums.size();
        if (target < 0) return -1;
        
        int left = 0, right = 0;
        int sum = 0, len = INT_MIN;
        while (right < nums.size()) {
            sum += nums[right];
            
            while (sum > target) {
                sum -= nums[left];
                left ++;
            }
            if (sum == target) {
                len = max(len, right - left + 1);
            }
            
            right ++;
        }
        return len==INT_MIN ? -1 : nums.size()-len;

        
//         // cout << target << endl;
//         unordered_map<int, int> hash_map;
//         hash_map[0] = -1;
        
//         int ans = INT_MIN;
//         for (int i=0, sum=0; i<nums.size(); ++i) {
//             sum += nums[i];
//             if (hash_map.count(sum-target)) {
//                 ans = max(ans, i - hash_map[sum-target]);
//             }
//             hash_map[sum]= i;
//         }
        // return ans==INT_MIN ? -1 : nums.size()-ans;
    }
};
// @lc code=end

