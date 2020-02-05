/*
 * @lc app=leetcode id=878 lang=cpp
 *
 * [878] Nth Magical Number
 *
 * https://leetcode.com/problems/nth-magical-number/description/
 *
 * algorithms
 * Hard (27.52%)
 * Likes:    153
 * Dislikes: 48
 * Total Accepted:    7.5K
 * Total Submissions: 27.4K
 * Testcase Example:  '1\n2\n3'
 *
 * A positive integer is magical if it is divisible by either A or B.
 * 
 * Return the N-th magical number.  Since the answer may be very large, return
 * it modulo 10^9 + 7.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: N = 1, A = 2, B = 3
 * Output: 2
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: N = 4, A = 2, B = 3
 * Output: 6
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: N = 5, A = 2, B = 4
 * Output: 10
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: N = 3, A = 6, B = 4
 * Output: 8
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= N <= 10^9
 * 2 <= A <= 40000
 * 2 <= B <= 40000
 * 
 * 
 * 
 * 
 * 
 * 
 */
#include<numeric>
#include<iostream>
using namespace std; 

// @lc code=start
class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {
        long lcm = A * B / gcd(A, B);
        long mod = 1e9 + 7;

        long left = 2, right = 1e14;
        while (left < right) {
            long mid = left + (right-left)/2;
            if (mid/A + mid/B - mid/lcm < N) 
                left = mid + 1;
            else 
                right = mid;
        }
        return left % mod;
    }
};
// @lc code=end

int main() {
    Solution sol;
    int N=4, A=2, B=3;
    cout<< sol.nthMagicalNumber(N, A, B) << endl;;
    return 0;
}