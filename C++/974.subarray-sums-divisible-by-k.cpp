/*
 * @lc app=leetcode id=974 lang=cpp
 *
 * [974] Subarray Sums Divisible by K
 *
 * https://leetcode.com/problems/subarray-sums-divisible-by-k/description/
 *
 * algorithms
 * Medium (47.53%)
 * Likes:    568
 * Dislikes: 53
 * Total Accepted:    23.5K
 * Total Submissions: 49.4K
 * Testcase Example:  '[4,5,0,-2,-3,1]\n5'
 *
 * Given an array A of integers, return the number of (contiguous, non-empty)
 * subarrays that have a sum divisible by K.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: A = [4,5,0,-2,-3,1], K = 5
 * Output: 7
 * Explanation: There are 7 subarrays with a sum divisible by K = 5:
 * [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2,
 * -3]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 30000
 * -10000 <= A[i] <= 10000
 * 2 <= K <= 10000
 * 
 * 
 */
#include<vector>
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> count{{0, 1}};
        // vector<int> count(k, 0);
        // count[0] = 1;

        int ans=0, sum=0, mod;
        for(int num: nums) {
            sum += num;
            mod = ((sum%k)+k)%k;
                        
            ans += count[mod];
            count[mod]++;
        }
        
        return ans;
    }
};
// @lc code=end

