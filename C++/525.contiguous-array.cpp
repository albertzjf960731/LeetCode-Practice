/*
 * @lc app=leetcode id=525 lang=cpp
 *
 * [525] Contiguous Array
 *
 * https://leetcode.com/problems/contiguous-array/description/
 *
 * algorithms
 * Medium (46.74%)
 * Likes:    5878
 * Dislikes: 240
 * Total Accepted:    280.6K
 * Total Submissions: 599.8K
 * Testcase Example:  '[0,1]'
 *
 * Given a binary array nums, return the maximum length of a contiguous
 * subarray with an equal number of 0 and 1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [0,1]
 * Output: 2
 * Explanation: [0, 1] is the longest contiguous subarray with an equal number
 * of 0 and 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0,1,0]
 * Output: 2
 * Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal
 * number of 0 and 1.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * nums[i] is either 0 or 1.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> hmap{{0, -1}};
        int cnt = 0, ans = 0;;
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] == 1) cnt += 1;
            else cnt -= 1;
            
            if (hmap.count(cnt)) ans = max(ans, i - hmap[cnt]);
            else hmap[cnt] = i;
        }
        return ans;
    }
};
// @lc code=end

