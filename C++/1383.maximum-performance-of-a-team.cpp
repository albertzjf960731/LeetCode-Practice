/*
 * @lc app=leetcode id=1383 lang=cpp
 *
 * [1383] Maximum Performance of a Team
 *
 * https://leetcode.com/problems/maximum-performance-of-a-team/description/
 *
 * algorithms
 * Hard (41.63%)
 * Likes:    1279
 * Dislikes: 42
 * Total Accepted:    41.4K
 * Total Submissions: 98.9K
 * Testcase Example:  '6\n[2,10,3,1,5,8]\n[5,4,3,9,7,2]\n2'
 *
 * You are given two integers n and k and two integer arrays speed and
 * efficiency both of length n. There are n engineers numbered from 1 to n.
 * speed[i] and efficiency[i] represent the speed and efficiency of the i^th
 * engineer respectively.
 * 
 * Choose at most k different engineers out of the n engineers to form a team
 * with the maximum performance.
 * 
 * The performance of a team is the sum of their engineers' speeds multiplied
 * by the minimum efficiency among their engineers.
 * 
 * Return the maximum performance of this team. Since the answer can be a huge
 * number, return it modulo 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
 * Output: 60
 * Explanation: 
 * We have the maximum performance of the team by selecting engineer 2 (with
 * speed=10 and efficiency=4) and engineer 5 (with speed=5 and efficiency=7).
 * That is, performance = (10 + 5) * min(4, 7) = 60.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 3
 * Output: 68
 * Explanation:
 * This is the same example as the first but k = 3. We can select engineer 1,
 * engineer 2 and engineer 5 to get the maximum performance of the team. That
 * is, performance = (2 + 10 + 5) * min(5, 4, 7) = 68.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 4
 * Output: 72
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= k <= n <= 10^5
 * speed.length == n
 * efficiency.length == n
 * 1 <= speed[i] <= 10^5
 * 1 <= efficiency[i] <= 10^8
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<vector<int>> nums;
        for (int i=0; i<n; ++i) nums.push_back({speed[i], efficiency[i]});
        sort(nums.begin(), nums.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] > b[1];
        });
        
        long mod = 1e9+7, ans = 0, sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (int i=0; i<n; ++i) {
            if (i >= k) sum -= pq.top(), pq.pop();
            
            sum += nums[i][0], pq.push(nums[i][0]);
            ans = max(ans, (sum%mod)*nums[i][1]);
        }
        return ans % mod;
    }
};
// @lc code=end

