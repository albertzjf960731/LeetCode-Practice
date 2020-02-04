/*
 * @lc app=leetcode id=849 lang=cpp
 *
 * [849] Maximize Distance to Closest Person
 *
 * https://leetcode.com/problems/maximize-distance-to-closest-person/description/
 *
 * algorithms
 * Easy (42.08%)
 * Likes:    597
 * Dislikes: 89
 * Total Accepted:    49.9K
 * Total Submissions: 118.5K
 * Testcase Example:  '[1,0,0,0,1,0,1]'
 *
 * In a row of seats, 1 represents a person sitting in that seat, and 0
 * represents that the seat is empty. 
 * 
 * There is at least one empty seat, and at least one person sitting.
 * 
 * Alex wants to sit in the seat such that the distance between him and the
 * closest person to him is maximized. 
 * 
 * Return that maximum distance to closest person.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,0,0,0,1,0,1]
 * Output: 2
 * Explanation: 
 * If Alex sits in the second open seat (seats[2]), then the closest person has
 * distance 2.
 * If Alex sits in any other open seat, the closest person has distance 1.
 * Thus, the maximum distance to the closest person is 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,0,0,0]
 * Output: 3
 * Explanation: 
 * If Alex sits in the last seat, the closest person is 3 seats away.
 * This is the maximum distance possible, so the answer is 3.
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= seats.length <= 20000
 * seats contains only 0s or 1s, at least one 0, and at least one 1.
 * 
 * 
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {

        // int ans = 0;

        // int n = seats.size();
        // int left=-1, right=0;
        // while (right<n) {
        //     while(right<n && seats[right]==0) 
        //         right++;
            
        //     if (left==-1)
        //         ans = max(ans, right);
        //     else if (right==n)
        //         ans = max(ans, n-1-left);
        //     else 
        //         ans = max(ans, (right-left)/2);
            
        //     left = right;
        //     right++;
        // }
        // return ans;

        int ans = 0;
        int last = -1;
        for (int i=0; i<seats.size(); ++i) {
            if (seats[i]==1) {
                ans = last==-1 ? i : max(ans, (i-last)/2);
                last = i;
            }
        }
        ans = max(ans, (int)seats.size()-1-last);
        return ans;
    }
};
// @lc code=end

