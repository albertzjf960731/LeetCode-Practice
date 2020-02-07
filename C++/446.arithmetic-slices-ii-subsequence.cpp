/*
 * @lc app=leetcode id=446 lang=cpp
 *
 * [446] Arithmetic Slices II - Subsequence
 *
 * https://leetcode.com/problems/arithmetic-slices-ii-subsequence/description/
 *
 * algorithms
 * Hard (31.75%)
 * Likes:    372
 * Dislikes: 48
 * Total Accepted:    18.1K
 * Total Submissions: 57.1K
 * Testcase Example:  '[2,4,6,8,10]'
 *
 * A sequence of numbers is called arithmetic if it consists of at least three
 * elements and if the difference between any two consecutive elements is the
 * same.
 * 
 * For example, these are arithmetic sequences:
 * 
 * 
 * 1, 3, 5, 7, 9
 * 7, 7, 7, 7
 * 3, -1, -5, -9
 * 
 * The following sequence is not arithmetic.
 * 
 * 
 * 1, 1, 2, 5, 7
 * 
 * 
 * A zero-indexed array A consisting of N numbers is given. A subsequence slice
 * of that array is any sequence of integers (P0, P1, ..., Pk) such that 0 ≤ P0
 * < P1 < ... < Pk < N.
 * 
 * A subsequence slice (P0, P1, ..., Pk) of array A is called arithmetic if the
 * sequence A[P0], A[P1], ..., A[Pk-1], A[Pk] is arithmetic. In particular,
 * this means that k ≥ 2.
 * 
 * The function should return the number of arithmetic subsequence slices in
 * the array A.
 * 
 * The input contains N integers. Every integer is in the range of -2^31 and
 * 2^31-1 and 0 ≤ N ≤ 1000. The output is guaranteed to be less than 2^31-1.
 * 
 * 
 * Example:
 * 
 * 
 * Input: [2, 4, 6, 8, 10]
 * 
 * Output: 7
 * 
 * Explanation:
 * All arithmetic subsequence slices are:
 * [2,4,6]
 * [4,6,8]
 * [6,8,10]
 * [2,4,6,8]
 * [4,6,8,10]
 * [2,4,6,8,10]
 * [2,6,10]
 * 
 * 
 */
#include<vector>
#include<map>
#include<unordered_map>
using namespace std; 

// @lc code=start
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        // 【0,1,2,2,2]
        // int ans=0, n=nums.size();

        // unordered_map<int, int> index;
        // for (int i=0; i<n; i++) 
        //     index[nums[i]] = i;
        
        // vector<vector<int>> dp(n, vector<int>(n));
        // for (int i=0; i<n-1; i++) {
        //     for (int j=i+1; j<n; j++) {
        //         int num = nums[i] - (nums[j]-nums[i]);
        //         if (index.count(num)) {
        //             int k = index[num]; // 这一步是查不到的
        //             dp[i][j] = dp[k][i] + 1;
        //             ans += dp[i][j];
        //         }
        //     }
        // }
        // return ans;

        // dp[i][d] = the number of arithmetic subsequences ending with A[i], difference is d. (NOTE here the length of valid subsequences can be 2)
        int ans = 0;
        vector<unordered_map<long, int>> dp(nums.size());
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {

                long delta = (long)nums[i] - (long)nums[j];
                int sum = 0;
                if (dp[j].count(delta))
                    sum = dp[j][delta];
                dp[i][delta] += sum+1;
                ans += sum;
            }
        }
        return ans;
    }
};
// @lc code=end

