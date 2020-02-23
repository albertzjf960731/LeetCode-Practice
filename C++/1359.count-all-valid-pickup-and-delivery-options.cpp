/*
 * @lc app=leetcode id=1359 lang=cpp
 *
 * [1359] Count All Valid Pickup and Delivery Options
 *
 * https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/description/
 *
 * algorithms
 * Hard (55.81%)
 * Likes:    29
 * Dislikes: 1
 * Total Accepted:    1.5K
 * Total Submissions: 2.6K
 * Testcase Example:  '1'
 *
 * Given n orders, each order consist in pickup and delivery services. 
 * 
 * Count all valid pickup/delivery possible sequences such that delivery(i) is
 * always after of pickup(i). 
 * 
 * Since the answer may be too large, return it modulo 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 1
 * Output: 1
 * Explanation: Unique order (P1, D1), Delivery 1 always is after of Pickup
 * 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 2
 * Output: 6
 * Explanation: All possible orders: 
 * (P1,P2,D1,D2), (P1,P2,D2,D1), (P1,D1,P2,D2), (P2,P1,D1,D2), (P2,P1,D2,D1)
 * and (P2,D2,P1,D1).
 * This is an invalid order (P1,D2,P2,D1) because Pickup 2 is after of Delivery
 * 2.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 3
 * Output: 90
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 500
 * 
 */

// @lc code=start
class Solution {
public:
    int countOrders(int n) {
        int mode = 1e9+7;

        long ans = 1;
        while (n>0) {
            ans = ans * n * (2*n-1) % mode;
            n--;
        }
        return ans;
    }
};
// @lc code=end

