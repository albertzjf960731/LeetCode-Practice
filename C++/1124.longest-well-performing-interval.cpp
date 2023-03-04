/*
 * @lc app=leetcode id=1124 lang=cpp
 *
 * [1124] Longest Well-Performing Interval
 *
 * https://leetcode.com/problems/longest-well-performing-interval/description/
 *
 * algorithms
 * Medium (31.97%)
 * Likes:    247
 * Dislikes: 46
 * Total Accepted:    7.5K
 * Total Submissions: 23.4K
 * Testcase Example:  '[9,9,6,0,6,6,9]'
 *
 * We are given hours, a list of the number of hours worked per day for a given
 * employee.
 * 
 * A day is considered to be a tiring day if and only if the number of hours
 * worked is (strictly) greater than 8.
 * 
 * A well-performing interval is an interval of days for which the number of
 * tiring days is strictly larger than the number of non-tiring days.
 * 
 * Return the length of the longest well-performing interval.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: hours = [9,9,6,0,6,6,9]
 * Output: 3
 * Explanation: The longest well-performing interval is [9,9,6].
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= hours.length <= 10000
 * 0 <= hours[i] <= 16
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        // 1, 0, -1, -2, -3
        int n = hours.size(), score = 0, ans = 0;
        unordered_map<int, int> hmap;

        for (int i=0; i<n; ++i) {
            score += (hours[i]>8 ? 1: -1);
            if (score > 0) ans = i + 1;
            else {
                if (hmap.count(score-1)) 
                    ans = max(ans, i-hmap[score-1]);
            }
            if (!hmap.count(score)) hmap[score] = i;
        }
        return ans;


        int n = hours.size();
        vector<int> nums(n+1, 0);
        for (int i=1; i<=n; ++i) 
            nums[i] = nums[i-1] + (hours[i-1]>8 ?1 : -1);

        vector<int> stack;
        for (int i=0; i<=n; ++i) {
            if (stack.empty() || nums[stack.back()] > nums[i])
                stack.push_back(i);
        }

        int ans = 0;
        for (int i=n; i>=0; i--) {
            while (!stack.empty() && nums[stack.back()] < nums[i]) {
                ans = max(ans, i - stack.back());
                stack.pop_back();
            }
        }
        return ans;
    }
};
// @lc code=end

