/*
 * @lc app=leetcode id=1353 lang=cpp
 *
 * [1353] Maximum Number of Events That Can Be Attended
 *
 * https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/description/
 *
 * algorithms
 * Medium (29.92%)
 * Likes:    671
 * Dislikes: 87
 * Total Accepted:    19.2K
 * Total Submissions: 63.9K
 * Testcase Example:  '[[1,2],[2,3],[3,4]]'
 *
 * Given an array of events where events[i] = [startDayi, endDayi]. Every event
 * i starts at startDayi and ends at endDayi.
 * 
 * You can attend an event i at any day d where startTimei <= d <= endTimei.
 * Notice that you can only attend one event at any time d.
 * 
 * Return the maximum number of events you can attend.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: events = [[1,2],[2,3],[3,4]]
 * Output: 3
 * Explanation: You can attend all the three events.
 * One way to attend them all is as shown.
 * Attend the first event on day 1.
 * Attend the second event on day 2.
 * Attend the third event on day 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: events= [[1,2],[2,3],[3,4],[1,2]]
 * Output: 4
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: events = [[1,4],[4,4],[2,2],[3,4],[1,1]]
 * Output: 4
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: events = [[1,100000]]
 * Output: 1
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: events = [[1,1],[1,2],[1,3],[1,4],[1,5],[1,6],[1,7]]
 * Output: 7
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= events.length <= 10^5
 * events[i].length == 2
 * 1 <= startDayi <= endDayi <= 10^5
 * 
 * 
 */
#include<vector>
#include<unordered_set>
#include<queue>

using namespace std;
// @lc code=start
class Solution {
public:
    int maxEvents(vector<vector<int>>& nums) {
        // sort(nums.begin(), nums.end(), [](auto &a, auto &b) {
        //     return a[1]<b[1] || (a[1]==b[1] && a[0]<b[0]);
        // });
        
        // unordered_set<int> days;
        // for (int i=0; i<nums.size(); i++) {
            
        //     for (int j=nums[i][0]; j<=nums[i][1]; j++) {
        //         if (!days.count(j)) {
        //             days.insert(j);
        //             break;
        //         };
        //     }
        // }
        // return days.size();

        priority_queue <int, vector<int>, greater<int>> pq;
        sort(nums.begin(), nums.end());
        
        int res = 0;
        for (int d=1, i=0; d<=100000; ++d) {
            while (pq.size() && pq.top()<d)
                pq.pop();
            while (i<nums.size() && nums[i][0]==d)
                pq.push(nums[i++][1]);
            if (!pq.empty()) {
                pq.pop();
                ++res;
            }
        }
        return res;
    }
};
// @lc code=end

