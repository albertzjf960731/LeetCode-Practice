/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (30.47%)
 * Likes:    1555
 * Dislikes: 511
 * Total Accepted:    304.4K
 * Total Submissions: 998.3K
 * Testcase Example:  '10'
 *
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * Example:
 * 
 * 
 * Input: 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 * 
 * 
 */
#include<vector>
#include<numeric>
#include<math.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
         if (n<2) return 0;
        
        vector<int> primes(n, 1);
        primes[0] = primes[1] = 0;

        for (int i=2; i<sqrt(n); i++) {
            if (primes[i]) {
                for(int j=2; i*j<n; j++) 
                    primes[i*j] = 0;
            }
        }
        return accumulate(primes.begin(), primes.end(), 0);
        return count(primes.begin(), primes.end(), 1);    
 
    }
};
// @lc code=end

