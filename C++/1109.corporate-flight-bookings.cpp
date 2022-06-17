/*
 * @lc app=leetcode id=1109 lang=cpp
 *
 * [1109] Corporate Flight Bookings
 *
 * https://leetcode.com/problems/corporate-flight-bookings/description/
 *
 * algorithms
 * Medium (53.55%)
 * Likes:    540
 * Dislikes: 102
 * Total Accepted:    20.2K
 * Total Submissions: 37.8K
 * Testcase Example:  '[[1,2,10],[2,3,20],[2,5,25]]\n5'
 *
 * There are n flights, and they are labeled from 1 to n.
 * 
 * We have a list of flight bookings.  The i-th booking bookings[i] = [i, j, k]
 * means that we booked k seats from flights labeled i to j inclusive.
 * 
 * Return an array answer of length n, representing the number of seats booked
 * on each flight in order of their label.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
 * Output: [10,55,45,25,25]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= bookings.length <= 20000
 * 1 <= bookings[i][0] <= bookings[i][1] <= n <= 20000
 * 1 <= bookings[i][2] <= 10000
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> cnts(n);
        for (auto &b : bookings) {
            cnts[b[0]-1] += b[2];
            if (b[1] < n)
                cnts[b[1]] -= b[2];
        }
        for (int i=1; i<n; ++i)
            cnts[i] += cnts[i-1];
        return cnts;
    }
};
// @lc code=end

