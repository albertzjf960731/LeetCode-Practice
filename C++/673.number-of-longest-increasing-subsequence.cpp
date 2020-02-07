/*
 * @lc app=leetcode id=673 lang=cpp
 *
 * [673] Number of Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (34.79%)
 * Likes:    1056
 * Dislikes: 71
 * Total Accepted:    40.7K
 * Total Submissions: 117K
 * Testcase Example:  '[1,3,5,4,7]'
 *
 * 
 * Given an unsorted array of integers, find the number of longest increasing
 * subsequence.
 * 
 * 
 * Example 1:
 * 
 * Input: [1,3,5,4,7]
 * Output: 2
 * Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1,
 * 3, 5, 7].
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [2,2,2,2,2]
 * Output: 5
 * Explanation: The length of longest continuous increasing subsequence is 1,
 * and there are 5 subsequences' length is 1, so output 5.
 * 
 * 
 * 
 * Note:
 * Length of the given array will be not exceed 2000 and the answer is
 * guaranteed to be fit in 32-bit signed int.
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        
        vector<int> lens(n, 1); // length of the longest increasing subsequence that ends at i
        vector<int> counts(n,1); // the number of the longest increasing subsequence that ends at i

        int max_len = 1;
        for (int i=1; i<n; i++) {
            for (int j=0; j<i; j++) {

                if (nums[i] > nums[j]) {
                    // if combining with i makes a longer increasing subsequence
                    if (lens[i]<lens[j]+1) {
                        lens[i] = lens[j]+1;
                        counts[i] = counts[j];
                        max_len = max(max_len, lens[i]);
                    // if combining with i makes another longest increasing subsequence
                    } else if (lens[i]==lens[j]+1) {
                        counts[i] += counts[j];
                    }
                }
            }
        }
        //return count(dp.begin(), dp.end(),maxLen);
        
        int ans = 0;
        for (int i = 0; i <nums.size(); i++) {
            if (lens[i] == max_len) {
                ans += counts[i];
            }
        }
        return ans;
    }
};
// @lc code=end

