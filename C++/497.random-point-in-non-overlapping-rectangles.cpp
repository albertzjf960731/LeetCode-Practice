/*
 * @lc app=leetcode id=497 lang=cpp
 *
 * [497] Random Point in Non-overlapping Rectangles
 *
 * https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/description/
 *
 * algorithms
 * Medium (39.18%)
 * Likes:    385
 * Dislikes: 601
 * Total Accepted:    34.4K
 * Total Submissions: 87.8K
 * Testcase Example:  '["Solution","pick","pick","pick","pick","pick"]\n' +
  '[[[[-2,-2,1,1],[2,2,4,6]]],[],[],[],[],[]]'
 *
 * You are given an array of non-overlapping axis-aligned rectangles rects
 * where rects[i] = [ai, bi, xi, yi] indicates that (ai, bi) is the bottom-left
 * corner point of the i^th rectangle and (xi, yi) is the top-right corner
 * point of the i^th rectangle. Design an algorithm to pick a random integer
 * point inside the space covered by one of the given rectangles. A point on
 * the perimeter of a rectangle is included in the space covered by the
 * rectangle.
 * 
 * Any integer point inside the space covered by one of the given rectangles
 * should be equally likely to be returned.
 * 
 * Note that an integer point is a point that has integer coordinates.
 * 
 * Implement the Solution class:
 * 
 * 
 * Solution(int[][] rects) Initializes the object with the given rectangles
 * rects.
 * int[] pick() Returns a random integer point [u, v] inside the space covered
 * by one of the given rectangles.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input
 * ["Solution", "pick", "pick", "pick", "pick", "pick"]
 * [[[[-2, -2, 1, 1], [2, 2, 4, 6]]], [], [], [], [], []]
 * Output
 * [null, [1, -2], [1, -1], [-1, -2], [-2, -2], [0, 0]]
 * 
 * Explanation
 * Solution solution = new Solution([[-2, -2, 1, 1], [2, 2, 4, 6]]);
 * solution.pick(); // return [1, -2]
 * solution.pick(); // return [1, -1]
 * solution.pick(); // return [-1, -2]
 * solution.pick(); // return [-2, -2]
 * solution.pick(); // return [0, 0]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= rects.length <= 100
 * rects[i].length == 4
 * -10^9 <= ai < xi <= 10^9
 * -10^9 <= bi < yi <= 10^9
 * xi - ai <= 2000
 * yi - bi <= 2000
 * All the rectangles do not overlap.
 * At most 10^4 calls will be made to pick.
 * 
 * 
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> _rects;
    vector<int> _sumArea;
    
public:
    Solution(vector<vector<int>>& rects) {
        _rects = rects;
        int sum = 0;
        for (auto rect: rects) {
            sum += (rect[2]-rect[0]+1) * (rect[3]-rect[1]+1);
            _sumArea.push_back(sum);
        }
    }
    
    vector<int> pick() {
        int rnd = rand() % _sumArea.back();
        int idx = upper_bound(_sumArea.begin(), _sumArea.end(), rnd) - _sumArea.begin();
        
        vector<int> rect = _rects[idx];
        int x = rand() % (rect[2] - rect[0] + 1) + rect[0];
        int y = rand() % (rect[3] - rect[1] + 1) + rect[1];
        return {x, y};
    }
};

// @lc code=end

