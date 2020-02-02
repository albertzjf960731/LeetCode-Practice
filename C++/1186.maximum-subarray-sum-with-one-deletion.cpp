/*
 * @lc app=leetcode id=1186 lang=cpp
 *
 * [1186] Maximum Subarray Sum with One Deletion
 *
 * https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/description/
 *
 * algorithms
 * Medium (34.70%)
 * Likes:    269
 * Dislikes: 10
 * Total Accepted:    8.7K
 * Total Submissions: 25K
 * Testcase Example:  '[1,-2,0,3]'
 *
 * Given an array of integers, return the maximum sum for a non-empty subarray
 * (contiguous elements) with at most one element deletion. In other words, you
 * want to choose a subarray and optionally delete one element from it so that
 * there is still at least one element left and the sum of the remaining
 * elements is maximum possible.
 * 
 * Note that the subarray needs to be non-empty after deleting one element.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [1,-2,0,3]
 * Output: 4
 * Explanation: Because we can choose [1, -2, 0, 3] and drop -2, thus the
 * subarray [1, 0, 3] becomes the maximum value.
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [1,-2,-2,3]
 * Output: 3
 * Explanation: We just choose [3] and it's the maximum sum.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = [-1,-1,-1,-1]
 * Output: -1
 * Explanation: The final subarray needs to be non-empty. You can't choose [-1]
 * and delete -1 from it, then get an empty subarray to make the sum equals to
 * 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 10^5
 * -10^4 <= arr[i] <= 10^4
 * 
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> dp_end(n, 0), dp_start(n, 0);

        // dp_end[0] = nums[0];
        // for (int i=1; i<n; i++) 
        //     dp_end[i] = max(dp_end[i-1]+nums[i], nums[i]);

        // dp_start[n-1] = nums[n-1];
        // for (int i=n-2; i>-1; i--) 
        //     dp_start[i] = max(dp_start[i+1]+nums[i], nums[i]);
        
        // int ans = *max_element(dp_end.begin(), dp_end.end()); // 不删除元素的最大值,  at most one element deletion
        // for (int i=1; i<n-1; i++) 
        //     ans = max(ans, dp_end[i-1]+dp_start[i+1]);
        
        // return ans;

        if (nums.size()==1) return nums[0];

        int drop = max(nums[0], nums[1]);
        int keep = max(nums[0]+nums[1], nums[1]);
        int ans = max(drop, keep);
            
        for (int i=2; i<nums.size(); i++ ) {
            drop = max(keep, drop+nums[i]);
            keep = max(keep+nums[i], nums[i]);
            ans = max(ans, max(drop, keep));
        }
        return ans;
    }
};
// @lc code=end

