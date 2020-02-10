/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 *
 * https://leetcode.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (61.88%)
 * Likes:    2034
 * Dislikes: 65
 * Total Accepted:    119.1K
 * Total Submissions: 192.4K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * 
 * Given a list of daily temperatures T, return a list such that, for each day
 * in the input, tells you how many days you would have to wait until a warmer
 * temperature.  If there is no future day for which this is possible, put 0
 * instead.
 * 
 * For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76,
 * 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].
 * 
 * 
 * Note:
 * The length of temperatures will be in the range [1, 30000].
 * Each temperature will be an integer in the range [30, 100].
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        vector<int> res(nums.size()), stack;
        
        for (int i=0; i<nums.size(); i++) {
            while (!stack.empty() && nums[i]>nums[stack.back()]) {
                res[stack.back()] = i - stack.back();
                stack.pop_back();
            }
            stack.push_back(i);
        }
        return res;
    }
};
// @lc code=end

