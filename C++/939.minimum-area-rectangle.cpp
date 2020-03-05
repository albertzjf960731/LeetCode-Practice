/*
 * @lc app=leetcode id=939 lang=cpp
 *
 * [939] Minimum Area Rectangle
 *
 * https://leetcode.com/problems/minimum-area-rectangle/description/
 *
 * algorithms
 * Medium (52.04%)
 * Likes:    490
 * Dislikes: 94
 * Total Accepted:    37.4K
 * Total Submissions: 71.8K
 * Testcase Example:  '[[1,1],[1,3],[3,1],[3,3],[2,2]]'
 *
 * Given a set of points in the xy-plane, determine the minimum area of a
 * rectangle formed from these points, with sides parallel to the x and y
 * axes.
 * 
 * If there isn't any rectangle, return 0.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,1],[1,3],[3,1],[3,3],[2,2]]
 * Output: 4
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
 * Output: 2
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= points.length <= 500
 * 0 <= points[i][0] <= 40000
 * 0 <= points[i][1] <= 40000
 * All points are distinct.
 * 
 * 
 * 
 */
#include<vector>
#include<set>
#include<unordered_set>
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        // set<pair<int, int>> p_set;
        // for (auto p : points) {
        //     p_set.insert(make_pair(p[0], p[1]));
        // }
        // int ans = INT_MAX;
        // for (int i=0; i<points.size(); ++i) {
        //     for (int j=i+1; j<points.size(); ++j) {
        //         auto p1 = points[i];
        //         auto p2 = points[j];
        //         if (p1[0] == p2[0] || p1[1] == p2[1])
        //             continue;
        //         pair<int, int> p3 = {p1[0], p2[1]};
        //         pair<int, int> p4 = {p2[0], p1[1]};
        //         if (p_set.count(p3) && p_set.count(p4))
        //             ans = min(ans, abs((p2[1] - p1[1]) * (p2[0] - p1[0])));
        //     }
        // }
        // return ans==INT_MAX ? 0 : ans;

        // unordered_set<int> p_set;
        // for (auto p : points) p_set.insert(40001*p[0] + p[1]);

        // int ans = INT_MAX;
        // for (int i=0; i<points.size(); ++i) {
        //     for (int j=i+1; j<points.size(); ++j) {
        //         auto p1 = points[i];
        //         auto p2 = points[j];
        //         if (p1[0] == p2[0] || p1[1] == p2[1])
        //             continue;
                
        //         vector<int> p3 = {p1[0], p2[1]};
        //         vector<int> p4 = {p2[0], p1[1]};
        //         if (p_set.count(40001*p3[0]+p3[1]) && p_set.count(40001*p4[0]+p4[1]))
        //             ans = min(ans, abs((p2[1] - p1[1]) * (p2[0] - p1[0])));
        //     }
        // }
        // return ans==INT_MAX ? 0 : ans;

        unordered_map<int, unordered_set<int>> p_set;
        for(auto point: points) p_set[point[0]].insert(point[1]);

        int ans = INT_MAX;
        for(int i=0; i<points.size(); ++i){
            int x0 = points[i][0];
            int y0 = points[i][1];
            
            for(int j=i+1; j<points.size(); ++j){
                int x1 = points[j][0];
                int y1 = points[j][1];
                
                if(x0==x1 || y0==y1) continue;
                
                int area = abs(x0-x1) * abs(y0-y1);
                if(area > ans) continue;
                
                if(p_set[x1].count(y0) && p_set[x0].count(y1))
                    ans = min(ans, area);
            }
        }
        return ans==INT_MAX ? 0: ans;
    }
};
// @lc code=end

