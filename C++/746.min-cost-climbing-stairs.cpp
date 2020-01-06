/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 *
 * https://leetcode.com/problems/min-cost-climbing-stairs/description/
 *
 * algorithms
 * Easy (48.50%)
 * Likes:    1433
 * Dislikes: 333
 * Total Accepted:    114.6K
 * Total Submissions: 235.3K
 * Testcase Example:  '[0,0,0,0]'
 *
 * 
 * On a staircase, the i-th step has some non-negative cost cost[i] assigned (0
 * indexed).
 * 
 * Once you pay the cost, you can either climb one or two steps. You need to
 * find minimum cost to reach the top of the floor, and you can either start
 * from the step with index 0, or the step with index 1.
 * 
 * 
 * Example 1:
 * 
 * Input: cost = [10, 15, 20]
 * Output: 15
 * Explanation: Cheapest is start on cost[1], pay that cost and go to the
 * top.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
 * Output: 6
 * Explanation: Cheapest is start on cost[0], and only step on 1s, skipping
 * cost[3].
 * 
 * 
 * 
 * Note:
 * 
 * cost will have a length in the range [2, 1000].
 * Every cost[i] will be an integer in the range [0, 999].
 * 
 * 
 */
#include<vector>
using namespace std; 

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int cost_size = cost.size();
        if (cost_size == 0 || cost_size ==1) 
            return 0;
        for (int i=2; i<cost_size; i++) 
            cost[i] += min(cost[i-1], cost[i-2]);
        return min(cost[cost_size-1], cost[cost_size-2]);
    }
};
// @lc code=end

