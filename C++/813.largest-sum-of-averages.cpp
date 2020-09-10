/*
 * @lc app=leetcode id=813 lang=cpp
 *
 * [813] Largest Sum of Averages
 *
 * https://leetcode.com/problems/largest-sum-of-averages/description/
 *
 * algorithms
 * Medium (50.11%)
 * Likes:    965
 * Dislikes: 46
 * Total Accepted:    25.5K
 * Total Submissions: 50.8K
 * Testcase Example:  '[9,1,2,3,9]\n3'
 *
 * We partition a row of numbers A into at most K adjacent (non-empty) groups,
 * then our score is the sum of the average of each group. What is the largest
 * score we can achieve?
 * 
 * Note that our partition must use every number in A, and that scores are not
 * necessarily integers.
 * 
 * 
 * Example:
 * Input: 
 * A = [9,1,2,3,9]
 * K = 3
 * Output: 20
 * Explanation: 
 * The best choice is to partition A into [9], [1, 2, 3], [9]. The answer is 9
 * + (1 + 2 + 3) / 3 + 9 = 20.
 * We could have also partitioned A into [9, 1], [2], [3, 9], for example.
 * That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.
 * 
 * 
 * 
 * 
 * Note: 
 * 
 * 
 * 1 <= A.length <= 100.
 * 1 <= A[i] <= 10000.
 * 1 <= K <= A.length.
 * Answers within 10^-6 of the correct answer will be accepted as correct.
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int K) {
        int n = nums.size();
        
        vector<double> sums(n+1, 0);
        for (int i=0; i<n; ++i) 
            sums[i+1] = sums[i] + nums[i];
        
        vector<vector<double>> dp(n, vector<double>(K));
        for (int i=0; i<n; ++i) 
            dp[i][0] = (sums[n]-sums[i]) / (n-i);
           
        for (int k=1; k<K; ++k) {
            for (int i=0; i<n-1; ++i) {
                for (int j=i+1; j<n; ++j) {
                    dp[i][k] = max(dp[i][k], 
                                   (sums[j]-sums[i])/(j-i) + dp[j][k-1]);
                }
            }
        }
        return dp[0][K-1];
    }
};
// @lc code=end

