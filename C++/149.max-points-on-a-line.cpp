/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 *
 * https://leetcode.com/problems/max-points-on-a-line/description/
 *
 * algorithms
 * Hard (16.98%)
 * Likes:    959
 * Dislikes: 2112
 * Total Accepted:    161.3K
 * Total Submissions: 947K
 * Testcase Example:  '[[1,1],[2,2],[3,3]]'
 *
 * Given n points on a 2D plane, find the maximum number of points that lie on
 * the same straight line.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,1],[2,2],[3,3]]
 * Output: 3
 * Explanation:
 * ^
 * |
 * |        o
 * |     o
 * |  o  
 * +------------->
 * 0  1  2  3  4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
 * Output: 4
 * Explanation:
 * ^
 * |
 * |  o
 * |     o        o
 * |        o
 * |  o        o
 * +------------------->
 * 0  1  2  3  4  5  6
 * 
 * 
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 * 
 */
#include<vector>
#include<map>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        // 由于通过斜率来判断共线需要用到除法，而用 double 表示的双精度小数在有的系统里不一定准确，为了更加精确无误的计算共线，应当避免除法，从而避免无线不循环小数的出现，那么怎么办呢，这里把除数和被除数都保存下来，不做除法，但是要让这两数分别除以它们的最大公约数
        
        int ans = 0;
        for (int i=0; i<points.size(); ++i) {
            map<pair<int, int>, int> hash_map;
            
            int dup = 1;
            for (int j=i+1; j<points.size(); ++j) {
                if (points[i][0]==points[j][0] && points[i][1]==points[j][1]) {
                    ++dup; 
                    continue;
                } 
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int d = gcd(dx, dy);
                ++hash_map[{dx/d, dy/d}];
            }
            
            ans = max(ans, dup);
            for (auto& it : hash_map) {
                ans = max(ans, it.second + dup);
            }
        }
        return ans;
    }
    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }
};
// @lc code=end

