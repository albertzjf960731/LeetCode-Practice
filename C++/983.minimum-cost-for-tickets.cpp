/*
 * @lc app=leetcode id=983 lang=cpp
 *
 * [983] Minimum Cost For Tickets
 *
 * https://leetcode.com/problems/minimum-cost-for-tickets/description/
 *
 * algorithms
 * Medium (58.19%)
 * Likes:    925
 * Dislikes: 22
 * Total Accepted:    31.3K
 * Total Submissions: 53.9K
 * Testcase Example:  '[1,4,6,7,8,20]\n[2,7,15]'
 *
 * In a country popular for train travel, you have planned some train
 * travelling one year in advance.  The days of the year that you will travel
 * is given as an array days.  Each day is an integer from 1 to 365.
 * 
 * Train tickets are sold in 3 different ways:
 * 
 * 
 * a 1-day pass is sold for costs[0] dollars;
 * a 7-day pass is sold for costs[1] dollars;
 * a 30-day pass is sold for costs[2] dollars.
 * 
 * 
 * The passes allow that many days of consecutive travel.  For example, if we
 * get a 7-day pass on day 2, then we can travel for 7 days: day 2, 3, 4, 5, 6,
 * 7, and 8.
 * 
 * Return the minimum number of dollars you need to travel every day in the
 * given list of days.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: days = [1,4,6,7,8,20], costs = [2,7,15]
 * Output: 11
 * Explanation: 
 * For example, here is one way to buy passes that lets you travel your travel
 * plan:
 * On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
 * On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3,
 * 4, ..., 9.
 * On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
 * In total you spent $11 and covered all the days of your travel.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
 * Output: 17
 * Explanation: 
 * For example, here is one way to buy passes that lets you travel your travel
 * plan:
 * On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1,
 * 2, ..., 30.
 * On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
 * In total you spent $17 and covered all the days of your travel.
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= days.length <= 365
 * 1 <= days[i] <= 365
 * days is in strictly increasing order.
 * costs.length == 3
 * 1 <= costs[i] <= 1000
 * 
 * 
 */
#include<vector>
using namespace std; 

// @lc code=start
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int max_d = days.back();
        
        vector<int> travel_day(max_d+1, 0);
        for (int d: days) travel_day[d] = 1;
        
        vector<int> dp(max_d+1, INT_MAX);
        dp[0] = 0;
        
        // 顺序有关
        for(int i = 1; i<=max_d; i++){
            if (travel_day[i]) {
                dp[i] = dp[i-1] + costs[0];
                dp[i] = min(dp[i], dp[max(0,i-7)]+costs[1]);
                dp[i] = min(dp[i], dp[max(0, i-30)]+costs[2]);
            }
            else
                dp[i] = dp[i-1];
        }        


        // int max_d = days.back();
        
        // vector<int> travel_day(max_d+1, 0);
        // for (int d: days) travel_day[d] = 1;
        
        // vector<int> dp(max_d+1, INT_MAX);
        // dp[0] = 0;
        
        // vector<int> tds{1, 7, 30};
        // for(int i=0; i<3; i++) {
        //     for (int j=tds[i]; j<=max_d; j++) {
        //         if(travel_day[j])
        //             dp[j] = min(dp[j], dp[j-tds[i]]+costs[i]);
        //         else 
        //             dp[j] = dp[j-1];
        //         cout <<setw(2) << dp[j] << " ";
        //     }
        //     cout << endl;
        // }
        // return dp[max_d];
    }
};
// @lc code=end

