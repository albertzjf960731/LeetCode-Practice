/*
 * @lc app=leetcode id=857 lang=cpp
 *
 * [857] Minimum Cost to Hire K Workers
 *
 * https://leetcode.com/problems/minimum-cost-to-hire-k-workers/description/
 *
 * algorithms
 * Hard (51.81%)
 * Likes:    1759
 * Dislikes: 219
 * Total Accepted:    54.3K
 * Total Submissions: 104.7K
 * Testcase Example:  '[10,20,5]\n[70,50,30]\n2'
 *
 * There are n workers. You are given two integer arrays quality and wage where
 * quality[i] is the quality of the i^th worker and wage[i] is the minimum wage
 * expectation for the i^th worker.
 * 
 * We want to hire exactly k workers to form a paid group. To hire a group of k
 * workers, we must pay them according to the following rules:
 * 
 * 
 * Every worker in the paid group should be paid in the ratio of their quality
 * compared to other workers in the paid group.
 * Every worker in the paid group must be paid at least their minimum wage
 * expectation.
 * 
 * 
 * Given the integer k, return the least amount of money needed to form a paid
 * group satisfying the above conditions. Answers within 10^-5 of the actual
 * answer will be accepted.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: quality = [10,20,5], wage = [70,50,30], k = 2
 * Output: 105.00000
 * Explanation: We pay 70 to 0^th worker and 35 to 2^nd worker.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], k = 3
 * Output: 30.66667
 * Explanation: We pay 4 to 0^th worker, 13.33333 to 2^nd and 3^rd workers
 * separately.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == quality.length == wage.length
 * 1 <= k <= n <= 10^4
 * 1 <= quality[i], wage[i] <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        // select k member, with its biggest ratio (num[0]);
        // minimus res -> minimus the biggest ratio;
        // at the traversal, update quality (num[1])
        int n = quality.size();
        vector<vector<double>> nums;
        for (int i=0; i<n; ++i) 
            nums.push_back({(double)(wage[i])/quality[i], (double)quality[i]});
        sort(nums.begin(), nums.end());

        double ans = INT_MAX, qsum = 0;
        priority_queue<int> pq;
        for (int i=0; i<n; ++i) {
            if (i >= k) qsum -= pq.top(), pq.pop();

            qsum += nums[i][1], pq.push(nums[i][1]);
            if (pq.size() == k) ans = min(ans, qsum * nums[i][0]);
        }
        return ans;
    }
};
// @lc code=end

