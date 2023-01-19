/*
 * @lc app=leetcode id=1793 lang=cpp
 *
 * [1793] Maximum Score of a Good Subarray
 *
 * https://leetcode.com/problems/maximum-score-of-a-good-subarray/description/
 *
 * algorithms
 * Hard (53.56%)
 * Likes:    853
 * Dislikes: 27
 * Total Accepted:    18.8K
 * Total Submissions: 35.1K
 * Testcase Example:  '[1,4,3,7,4,5]\n3'
 *
 * You are given an array of integers nums (0-indexed) and an integer k.
 * 
 * The score of a subarray (i, j) is defined as min(nums[i], nums[i+1], ...,
 * nums[j]) * (j - i + 1). A good subarray is a subarray where i <= k <= j.
 * 
 * Return the maximum possible score of a good subarray.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,4,3,7,4,5], k = 3
 * Output: 15
 * Explanation: The optimal subarray is (1, 5) with a score of min(4,3,7,4,5) *
 * (5-1+1) = 3 * 5 = 15. 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,5,4,5,4,1,1,1], k = 0
 * Output: 20
 * Explanation: The optimal subarray is (0, 4) with a score of min(5,5,4,5,4) *
 * (4-0+1) = 4 * 5 = 20.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 2 * 10^4
 * 0 <= k < nums.length
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        vector<int> monostack;
        nums.push_back(0);
        monostack.push_back(-1);
        
        int ans = 0;
        for (int i=0; i<nums.size(); ++i) {
            while (monostack.back()!=-1 && nums[monostack.back()]>nums[i]) {
                int h = nums[monostack.back()];
                monostack.pop_back();

                int w = i-monostack.back()-1;
                if (i>k && monostack.back()<k) 
                    ans = max(ans, h * w);
            }
            monostack.push_back(i);
        }
        return ans;


        int ans = nums[k], mini = nums[k];
        int i = k, j = k, n = nums.size();
        while (i>0 || j<n-1) {
            if ((i>0? nums[i-1] : 0) < (j<n-1 ? nums[j+1] : 0))
                mini = min(mini, nums[++j]);
            else
                mini = min(mini, nums[--i]);
            ans = max(ans, mini * (j-i+1));
        }
        return ans;

    }
};
// @lc code=end

