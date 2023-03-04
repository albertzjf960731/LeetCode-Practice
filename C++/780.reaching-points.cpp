/*
 * @lc app=leetcode id=780 lang=cpp
 *
 * [780] Reaching Points
 *
 * https://leetcode.com/problems/reaching-points/description/
 *
 * algorithms
 * Hard (31.98%)
 * Likes:    1061
 * Dislikes: 177
 * Total Accepted:    45.8K
 * Total Submissions: 142.8K
 * Testcase Example:  '1\n1\n3\n5'
 *
 * Given four integers sx, sy, tx, and ty, return true if it is possible to
 * convert the point (sx, sy) to the point (tx, ty) through some operations, or
 * false otherwise.
 * 
 * The allowed operation on some point (x, y) is to convert it to either (x, x
 * + y) or (x + y, y).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: sx = 1, sy = 1, tx = 3, ty = 5
 * Output: true
 * Explanation:
 * One series of moves that transforms the starting point to the target is:
 * (1, 1) -> (1, 2)
 * (1, 2) -> (3, 2)
 * (3, 2) -> (3, 5)
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: sx = 1, sy = 1, tx = 2, ty = 2
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: sx = 1, sy = 1, tx = 1, ty = 1
 * Output: true
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= sx, sy, tx, ty <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if (tx < sx || ty < sy) return false;
        if (tx == sx && (ty-sy) % sx == 0) return true;
        if (ty == sy && (tx-sx) % sy == 0) return true;
        return reachingPoints(sx, sy, tx%ty, ty % tx);
    }
};
// @lc code=end

