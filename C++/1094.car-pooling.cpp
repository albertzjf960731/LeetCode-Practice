/*
 * @lc app=leetcode id=1094 lang=cpp
 *
 * [1094] Car Pooling
 *
 * https://leetcode.com/problems/car-pooling/description/
 *
 * algorithms
 * Medium (56.90%)
 * Likes:    286
 * Dislikes: 13
 * Total Accepted:    17.1K
 * Total Submissions: 30.1K
 * Testcase Example:  '[[2,1,5],[3,3,7]]\n4'
 *
 * You are driving a vehicle that has capacity empty seats initially available
 * for passengers.  The vehicle only drives east (ie. it cannot turn around and
 * drive west.)
 * 
 * Given a list of trips, trip[i] = [num_passengers, start_location,
 * end_location] contains information about the i-th trip: the number of
 * passengers that must be picked up, and the locations to pick them up and
 * drop them off.  The locations are given as the number of kilometers due east
 * from your vehicle's initial location.
 * 
 * Return true if and only if it is possible to pick up and drop off all
 * passengers for all the given trips. 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: trips = [[2,1,5],[3,3,7]], capacity = 4
 * Output: false
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: trips = [[2,1,5],[3,3,7]], capacity = 5
 * Output: true
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: trips = [[2,1,5],[3,5,7]], capacity = 3
 * Output: true
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: trips = [[3,2,7],[3,7,9],[8,3,9]], capacity = 11
 * Output: true
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * trips.length <= 1000
 * trips[i].length == 3
 * 1 <= trips[i][0] <= 100
 * 0 <= trips[i][1] < trips[i][2] <= 1000
 * 1 <= capacity <= 100000
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        vector<int> people(1001, 0);
        for (auto trip: trips) {
            for (int i=trip[1]; i<trip[2]; i++) {
                people[i] += trip[0];
                if (people[i]>capacity)
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end

