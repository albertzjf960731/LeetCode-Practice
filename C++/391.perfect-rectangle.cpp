/*
 * @lc app=leetcode id=391 lang=cpp
 *
 * [391] Perfect Rectangle
 *
 * https://leetcode.com/problems/perfect-rectangle/description/
 *
 * algorithms
 * Hard (30.46%)
 * Likes:    399
 * Dislikes: 79
 * Total Accepted:    26.4K
 * Total Submissions: 86.3K
 * Testcase Example:  '[[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]'
 *
 * Given N axis-aligned rectangles where N > 0, determine if they all together
 * form an exact cover of a rectangular region.
 * 
 * Each rectangle is represented as a bottom-left point and a top-right point.
 * For example, a unit square is represented as [1,1,2,2]. (coordinate of
 * bottom-left point is (1, 1) and top-right point is (2, 2)).
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * rectangles = [
 * ⁠ [1,1,3,3],
 * ⁠ [3,1,4,2],
 * ⁠ [3,2,4,4],
 * ⁠ [1,3,2,4],
 * ⁠ [2,3,3,4]
 * ]
 * 
 * Return true. All 5 rectangles together form an exact cover of a rectangular
 * region.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * rectangles = [
 * ⁠ [1,1,2,3],
 * ⁠ [1,3,2,4],
 * ⁠ [3,1,4,2],
 * ⁠ [3,2,4,4]
 * ]
 * 
 * Return false. Because there is a gap between the two rectangular
 * regions.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * rectangles = [
 * ⁠ [1,1,3,3],
 * ⁠ [3,1,4,2],
 * ⁠ [1,3,2,4],
 * ⁠ [3,2,4,4]
 * ]
 * 
 * Return false. Because there is a gap in the top center.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * rectangles = [
 * ⁠ [1,1,3,3],
 * ⁠ [3,1,4,2],
 * ⁠ [1,3,2,4],
 * ⁠ [2,2,4,4]
 * ]
 * 
 * Return false. Because two of the rectangles overlap with each other.
 * 
 * 
 * 
 */
#include<vector>
#include<map>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int left=INT_MAX, right=INT_MIN;
        int bottom=INT_MAX, top=INT_MIN;
        
        int area = 0;
        map<pair<int,int>,int> points;   //保存每个顶点数量
        for(vector<int>& item:rectangles){
            left = min(left, item[0]);  //找最大矩形
            right = max(right, item[2]);
            bottom = min(bottom, item[1]);
            top = max(top, item[3]);
            
            area += (item[2]-item[0])*(item[3]-item[1]);
            
            points[{item[0],item[1]}]++;   //保存4个顶点
            points[{item[2],item[3]}]++;
            points[{item[0],item[3]}]++;
            points[{item[2],item[1]}]++;
        }
        
        if(area != (right-left) * (top-bottom))
            return false;
        
        points[{left,bottom}]++; //把大矩形有4个角放入后,所有点都应该是偶数了
        points[{left,top}]++;
        points[{right,bottom}]++;
        points[{right,top}]++;
        
        for(auto& it: points)
            if(it.second % 2 == 1) return false;
        return true;
    }
};
// @lc code=end

