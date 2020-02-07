/*
 * @lc app=leetcode id=646 lang=cpp
 *
 * [646] Maximum Length of Pair Chain
 *
 * https://leetcode.com/problems/maximum-length-of-pair-chain/description/
 *
 * algorithms
 * Medium (50.38%)
 * Likes:    704
 * Dislikes: 64
 * Total Accepted:    47K
 * Total Submissions: 93.3K
 * Testcase Example:  '[[1,2], [2,3], [3,4]]'
 *
 * 
 * You are given n pairs of numbers. In every pair, the first number is always
 * smaller than the second number.
 * 
 * 
 * 
 * Now, we define a pair (c, d) can follow another pair (a, b) if and only if b
 * < c. Chain of pairs can be formed in this fashion. 
 * 
 * 
 * 
 * Given a set of pairs, find the length longest chain which can be formed. You
 * needn't use up all the given pairs. You can select pairs in any order.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: [[1,2], [2,3], [3,4]]
 * Output: 2
 * Explanation: The longest chain is [1,2] -> [3,4]
 * 
 * 
 * 
 * Note:
 * 
 * The number of given pairs will be in the range [1, 1000].
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // if (pairs.empty()) return 0;

        // sort(pairs.begin(), pairs.end());
        // vector<int> dp(pairs.size(), 1);
        
        // for (int i=1; i<pairs.size(); i++) {
        //     for (int j=0; j<i; j++) {
        //         if (pairs[j][1] < pairs[i][0])
        //             dp[i] = max(dp[i], dp[j]+1);
        //     }
        // }
        // return *max_element(dp.begin(), dp.end())

        // You can select pairs in any order.
        if (pairs.empty()) return 0;

        sort(pairs.begin(), pairs.end(), cmp);
        
        int ans = 1;
        vector<int> pre_pair = pairs[0];
        for (int i=1; i<pairs.size(); i++) {
            if (pairs[i][0] > pre_pair[1]) {
                pre_pair = pairs[i];
                ans ++;
            }
        }
        return ans;
    }

private:
    // the first number is always smaller than the second number.
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1]<b[1] || (a[1]==b[1] && a[0]<b[0]);
    }
};
// @lc code=end

