/*
 * @lc app=leetcode id=873 lang=cpp
 *
 * [873] Length of Longest Fibonacci Subsequence
 *
 * https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/description/
 *
 * algorithms
 * Medium (47.48%)
 * Likes:    545
 * Dislikes: 25
 * Total Accepted:    23.2K
 * Total Submissions: 48.8K
 * Testcase Example:  '[1,2,3,4,5,6,7,8]'
 *
 * A sequence X_1, X_2, ..., X_n is fibonacci-like if:
 * 
 * 
 * n >= 3
 * X_i + X_{i+1} = X_{i+2} for all i + 2 <= n
 * 
 * 
 * Given a strictly increasing array A of positive integers forming a sequence,
 * find the length of the longest fibonacci-like subsequence of A.  If one does
 * not exist, return 0.
 * 
 * (Recall that a subsequence is derived from another sequence A by deleting
 * any number of elements (including none) from A, without changing the order
 * of the remaining elements.  For example, [3, 5, 8] is a subsequence of [3,
 * 4, 5, 6, 7, 8].)
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,4,5,6,7,8]
 * Output: 5
 * Explanation:
 * The longest subsequence that is fibonacci-like: [1,2,3,5,8].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,3,7,11,12,14,18]
 * Output: 3
 * Explanation:
 * The longest subsequence that is fibonacci-like:
 * [1,11,12], [3,11,14] or [7,11,18].
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 3 <= A.length <= 1000
 * 1 <= A[0] < A[1] < ... < A[A.length - 1] <= 10^9
 * (The time limit has been reduced by 50% for submissions in Java, C, and
 * C++.)
 * 
 * 
 */
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std; 

// @lc code=start
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& nums) {
        // unordered_set<int> hash_set(nums.begin(), nums.end());

        // int ans = 0;
        // for (int i=0; i<nums.size()-1; i++) {
        //     for (int j=i+1; j<nums.size(); j++) {
        //         int a=nums[i], b=nums[j];
                
        //         int count = 2;
        //         while (hash_set.count(a+b)) {
        //             b = a + b;
        //             a = b - a;
        //             count ++;
        //         }
        //         ans = max(ans, count);    
        //     }
        // }
        // return ans>2 ? ans: 0;

        int ans=0, n=nums.size();
        unordered_map<int, int> index;
        for (int i=0; i<n; i++) 
            index[nums[i]] = i;
        
        vector<vector<int>> dp(n, vector<int>(n, 2));
        for (int i=0; i<n-1; i++) {
            for (int j=i+1; j<n; j++) {

                int num = nums[j] - nums[i];
                if (num >= nums[i])
                    break;
                if (index.count(num)) {
                    int k = index[num];
                    dp[i][j] = dp[k][i] + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans>2 ? ans: 0;
    }
};
// @lc code=end

