/*
 * @lc app=leetcode id=2560 lang=cpp
 *
 * [2560] House Robber IV
 *
 * https://leetcode.com/problems/house-robber-iv/description/
 *
 * algorithms
 * Medium (37.75%)
 * Likes:    458
 * Dislikes: 13
 * Total Accepted:    8.3K
 * Total Submissions: 21.9K
 * Testcase Example:  '[2,3,5,9]\n2'
 *
 * There are several consecutive houses along a street, each of which has some
 * money inside. There is also a robber, who wants to steal money from the
 * homes, but he refuses to steal from adjacent homes.
 * 
 * The capability of the robber is the maximum amount of money he steals from
 * one house of all the houses he robbed.
 * 
 * You are given an integer array nums representing how much money is stashed
 * in each house. More formally, the i^th house from the left has nums[i]
 * dollars.
 * 
 * You are also given an integer k, representing the minimum number of houses
 * the robber will steal from. It is always possible to steal at least k
 * houses.
 * 
 * Return the minimum capability of the robber out of all the possible ways to
 * steal at least k houses.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,3,5,9], k = 2
 * Output: 5
 * Explanation: 
 * There are three ways to rob at least 2 houses:
 * - Rob the houses at indices 0 and 2. Capability is max(nums[0], nums[2]) =
 * 5.
 * - Rob the houses at indices 0 and 3. Capability is max(nums[0], nums[3]) =
 * 9.
 * - Rob the houses at indices 1 and 3. Capability is max(nums[1], nums[3]) =
 * 9.
 * Therefore, we return min(5, 9, 9) = 5.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [2,7,9,3,1], k = 2
 * Output: 2
 * Explanation: There are 7 ways to rob the houses. The way which leads to
 * minimum capability is to rob the house at index 0 and 4. Return max(nums[0],
 * nums[4]) = 2.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
 * 1 <= k <= (nums.length + 1)/2
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(k, vector<int>(n, INT_MAX));
        for (int i=0; i<n; ++i) 
            dp[0][i] = nums[i];
                
        for (int i=1; i<k; ++i) {
            
            int cur_min = INT_MAX;
            for (int j=2; j<n; ++j) {
                
                cur_min = min(cur_min, dp[i-1][j-2]);
                dp[i][j] = max(nums[j], cur_min);
            }
        }
        
        int ans = INT_MAX;
        for (int i=0; i<n; ++i) 
            ans = min(ans, dp[k-1][i]);
        return ans;


        // If I have nums[i]<=limitnums[i]<=limitnums[i]<=limit and nums[i+1]<=limitnums[i+1]<=limitnums[i+1]<=limit, if I choose ith element I will have n−i−1n-i-1n−i−1 more choices from i+2<=x<ni+2<=x<ni+2<=x<n. Here, x represents the candidates i can choose. If I choose i+1thi+1 thi+1th element I will have n−i−2n-i-2n−i−2 element to choose from i+3<=x<ni+3<=x<ni+3<=x<n so first one is better which boils down to choosing the first element every time i get an element within allowable limit.

        // mimi-max problem
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());

        while (left < right) {
            int mid = left + (right - left) / 2;

            int cnt = 0;
            for (int i=0; i<nums.size(); ++i) {
                if (nums[i] <= mid) {
                    cnt += 1;
                    i++;
                }
            }

            if (cnt < k) left = mid + 1;
            else right = mid;
        }
        return left;

    }
};
// @lc code=end

