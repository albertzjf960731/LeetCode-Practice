/*
 * @lc app=leetcode id=1053 lang=cpp
 *
 * [1053] Previous Permutation With One Swap
 *
 * https://leetcode.com/problems/previous-permutation-with-one-swap/description/
 *
 * algorithms
 * Medium (50.52%)
 * Likes:    373
 * Dislikes: 31
 * Total Accepted:    35.6K
 * Total Submissions: 70.5K
 * Testcase Example:  '[3,2,1]'
 *
 * Given an array of positive integers arr (not necessarily distinct), return
 * the lexicographically largest permutation that is smaller than arr, that can
 * be made with exactly one swap. If it cannot be done, then return the same
 * array.
 * 
 * Note that a swap exchanges the positions of two numbers arr[i] and arr[j]
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [3,2,1]
 * Output: [3,1,2]
 * Explanation: Swapping 2 and 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [1,1,5]
 * Output: [1,1,5]
 * Explanation: This is already the smallest permutation.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = [1,9,4,6,7]
 * Output: [1,7,4,6,9]
 * Explanation: Swapping 9 and 7.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 10^4
 * 1 <= arr[i] <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& nums) {
        // 0 <= i < j <= n, nums[i] > nums[j], swap(nums[i], nums[j]);
        // 非递减

        int n = nums.size();

        // max(i)
        int i = n - 2;
        while (i>=0 && nums[i]<=nums[i+1]) i--;
        if (i == -1) return nums;

        // max(nums[j]) && nums[j]<nums[i]
        int j = n - 1;
        while (nums[j]>=nums[i] || nums[j]==nums[j-1]) j--;
        swap(nums[i], nums[j]);
        return nums;
    }
};
// @lc code=end

