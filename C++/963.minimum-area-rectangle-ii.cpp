/*
 * @lc app=leetcode id=963 lang=cpp
 *
 * [963] Minimum Area Rectangle II
 *
 * https://leetcode.com/problems/minimum-area-rectangle-ii/description/
 *
 * algorithms
 * Medium (48.75%)
 * Likes:    109
 * Dislikes: 175
 * Total Accepted:    9K
 * Total Submissions: 18.4K
 * Testcase Example:  '[[1,2],[2,1],[1,0],[0,1]]'
 *
 * Given a set of points in the xy-plane, determine the minimum area of any
 * rectangle formed from these points, with sides not necessarily parallel to
 * the x and y axes.
 * 
 * If there isn't any rectangle, return 0.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: [[1,2],[2,1],[1,0],[0,1]]
 * Output: 2.00000
 * Explanation: The minimum area rectangle occurs at [1,2],[2,1],[1,0],[0,1],
 * with an area of 2.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: [[0,1],[2,1],[1,1],[1,0],[2,0]]
 * Output: 1.00000
 * Explanation: The minimum area rectangle occurs at [1,0],[1,1],[2,1],[2,0],
 * with an area of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * 
 * 
 * Input: [[0,3],[1,2],[3,1],[1,3],[2,1]]
 * Output: 0
 * Explanation: There is no possible rectangle to form from these points.
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * 
 * 
 * Input: [[3,1],[1,1],[0,1],[2,1],[3,3],[3,2],[0,2],[2,3]]
 * Output: 2.00000
 * Explanation: The minimum area rectangle occurs at [2,1],[2,3],[3,3],[3,1],
 * with an area of 2.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= points.length <= 50
 * 0 <= points[i][0] <= 40000
 * 0 <= points[i][1] <= 40000
 * All points are distinct.
 * Answers within 10^-5 of the actual value will be accepted as correct.
 * 
 * 
 */
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<set>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isValid(vector<int> &p1,vector<int> &p2,vector<int>&p3){        
        int x1 = p1[0]-p2[0];
        int x2 = p3[0]-p2[0];
        
        int y1 = p1[1]-p2[1];
        int y2 = p3[1]-p2[1];
        
        return x1*x2 + y1*y2 == 0;

        // if((y1==0 && x2==0) || (y2==0 && x1==0))
        //     return true;
        // else if(y1==0 || x1==0 || y2==0 || x2==0)
        //     return false;
        // else if(x1*x2 == -y1*y2)
        //     return true;
        // return false;
    }
    
    double dist(vector<int> &p1,vector<int> &p2){
        return sqrt((pow(p1[0]-p2[0], 2))+ pow(p1[1]-p2[1], 2));
    }
    
    double Area(vector<int> &p1,vector<int> &p2,vector<int>&p3){
        return dist(p1,p2) * dist(p2,p3);
    }
    
    double minAreaFreeRect(vector<vector<int>>& points) {        
        const int n = points.size();
        if(n<3) return 0;
        
        // set<pair<int, int> > hash_map;
        // for(int i=0; i<n; i++)
        //     hash_map.insert({points[i][0], points[i][1]});
        unordered_map<int, unordered_set<int>> hash_map;
        for (auto p: points) 
            hash_map[p[0]].insert(p[1]);

        double ans = INT_MAX;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                for(int k=j+1; k<n; k++) {
                    if(isValid(points[i], points[j], points[k])){
                        int x = points[i][0] + points[k][0] - points[j][0];
                        int y = points[i][1] + points[k][1] - points[j][1];
                        // if(hash_map.count({x,y})){
                        if (hash_map[x].count(y)) {
                            ans = min(ans, Area(points[i], points[j], points[k]));
                        }
                    }
                   else  if(isValid(points[i],  points[k], points[j])){
                        int x = points[i][0] + points[j][0] - points[k][0];
                        int y = points[i][1] + points[j][1] - points[k][1];
                        // if(hash_map.count({x,y})){
                        if (hash_map[x].count(y)) {
                            ans = min(ans, Area(points[i],points[k],points[j]));
                        }
                    }
                   else if(isValid(points[j], points[i], points[k])){
                        int x = points[j][0] + points[k][0] - points[i][0];
                        int y = points[j][1] + points[k][1] - points[i][1];
                        // if(hash_map.count({x,y})){
                        if (hash_map[x].count(y)) {
                            ans = min(ans, Area(points[j],points[i],points[k]));
                        }
                    }
                    
                }
            }
        }
        return ans==INT_MAX ? 0: ans;
    }
};
// @lc code=end

