/*
 * @lc app=leetcode id=986 lang=cpp
 *
 * [986] Interval List Intersections
 *
 * https://leetcode.com/problems/interval-list-intersections/description/
 *
 * algorithms
 * Medium (67.44%)
 * Likes:    1639
 * Dislikes: 52
 * Total Accepted:    135.8K
 * Total Submissions: 201K
 * Testcase Example:  '[[0,2],[5,10],[13,23],[24,25]]\n[[1,5],[8,12],[15,24],[25,26]]'
 *
 * Given two lists of closed intervals, each list of intervals is pairwise
 * disjoint and in sorted order.
 * 
 * Return the intersection of these two interval lists.
 * 
 * (Formally, a closed interval [a, b] (with a <= b) denotes the set of real
 * numbers x with a <= x <= b.  The intersection of two closed intervals is a
 * set of real numbers that is either empty, or can be represented as a closed
 * interval.  For example, the intersection of [1, 3] and [2, 4] is [2,
 * 3].)
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: A = [[0,2],[5,10],[13,23],[24,25]], B =
 * [[1,5],[8,12],[15,24],[25,26]]
 * Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 0 <= A.length < 1000
 * 0 <= B.length < 1000
 * 0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9
 * 
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> res;
        int i = 0, j = 0;
        while (i<nums1.size() && j<nums2.size()) {
            int a1 = nums1[i][0], a2 = nums1[i][1];
            int b1 = nums2[j][0], b2 = nums2[j][1];
            if (b2>=a1 && a2>=b1)  {
                res.push_back({max(a1, b1), min(a2, b2)});
            }
            if (a2 > b2) j ++;
            else i++;
        }
        return res;
    }
};
// @lc code=end

