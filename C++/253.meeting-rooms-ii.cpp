/*
 * @lc app=leetcode id=253 lang=cpp
 *
 * [253] Meeting Rooms II
 *
 * Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required
 * 
 * Example 1:
 * Input: [[0, 30],[5, 10],[15, 20]]
 * Output: 2
 * 
 * Example 2:
 * Input: [[7,10],[2,4]]
 * Output: 1
 * NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
 * 
 */
#include<vector>
#include<map>
using namespace std;

// @lc code=start
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> m;
        for (auto& item : intervals) {
            ++m[item[0]];
            --m[item[1]];
        }
        int cnt = 0, ans = 0;
        for (auto &it : m) {
            ans = max(ans, cnt += it.second);
        }
        return ans;
    }
};
// @lc code=end

