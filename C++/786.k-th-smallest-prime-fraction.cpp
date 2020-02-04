/*
 * @lc app=leetcode id=786 lang=cpp
 *
 * [786] K-th Smallest Prime Fraction
 *
 * https://leetcode.com/problems/k-th-smallest-prime-fraction/description/
 *
 * algorithms
 * Hard (41.59%)
 * Likes:    297
 * Dislikes: 17
 * Total Accepted:    11K
 * Total Submissions: 26.4K
 * Testcase Example:  '[1,2,3,5]\n3'
 *
 * A sorted list A contains 1, plus some number of primes.  Then, for every p <
 * q in the list, we consider the fraction p/q.
 * 
 * What is the K-th smallest fraction considered?  Return your answer as an
 * array of ints, where answer[0] = p and answer[1] = q.
 * 
 * 
 * Examples:
 * Input: A = [1, 2, 3, 5], K = 3
 * Output: [2, 5]
 * Explanation:
 * The fractions to be considered in sorted order are:
 * 1/5, 1/3, 2/5, 1/2, 3/5, 2/3.
 * The third fraction is 2/5.
 * 
 * Input: A = [1, 7], K = 1
 * Output: [1, 7]
 * 
 * 
 * Note:
 * 
 * 
 * A will have length between 2 and 2000.
 * Each A[i] will be between 1 and 30000.
 * K will be between 1 and A.length * (A.length - 1) / 2.
 * 
 */
#include<vector>
using namespace std; 

// @lc code=start
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& nums, int k) {
        int n=nums.size();
        int p=0, q=1;

        double left=0, right=1;
        while (true) {
            double mid = left + (right-left)/2;
            p=0;

            int count = 0; // <=mid
            for (int i=0, j=0; i<n; i++) {
                while (j<n && mid*nums[j]<nums[i])
                    j++;
                count += n-j;
                
                // nums[i]/nums[j] > p/q
                if (j<n && p*nums[j]<q*nums[i]) {
                    p = nums[i];
                    q = nums[j];
                }
            }

            if (count < k) {
                left = mid;
            } 
            else if (count > k) {
                right = mid;
            } else {
                return vector<int>{p, q};
            }
        }
    }
};
// @lc code=end

