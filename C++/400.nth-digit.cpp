/*
 * @lc app=leetcode id=400 lang=cpp
 *
 * [400] Nth Digit
 *
 * https://leetcode.com/problems/nth-digit/description/
 *
 * algorithms
 * Medium (30.99%)
 * Likes:    306
 * Dislikes: 947
 * Total Accepted:    53.6K
 * Total Submissions: 173.1K
 * Testcase Example:  '3'
 *
 * Find the n^th digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8,
 * 9, 10, 11, ... 
 * 
 * Note:
 * n is positive and will fit within the range of a 32-bit signed integer (n <
 * 2^31).
 * 
 * 
 * Example 1:
 * 
 * Input:
 * 3
 * 
 * Output:
 * 3
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * 11
 * 
 * Output:
 * 0
 * 
 * Explanation:
 * The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a
 * 0, which is part of the number 10.
 * 
 * 
 */
#include<math.h>
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    int find(int n, int p) {
        // n = 9 + 2 × 90 + 3 × 900 + ... + 9(k - 1) × 10^(k - 2) + M, M < 9k × 10^(k-1)

        if(n > 9*p*pow(10, p-1))
            return find(n-9*p*pow(10, p-1), p+1);
        else{
            int x = (n-1)/p + pow(10, p-1);
            int k = (n-1) % p;
            return (x / (int) pow(10, p-k-1)) % 10;
        }
    }
    
    int findNthDigit(int n) {
        return find (n, 1);

        long long len = 1, cnt = 9, start = 1;
        while (n > len * cnt) {
            n -= len * cnt;
            ++len;
            cnt *= 10;
            start *= 10;
        }
        start += (n - 1) / len;
        string t = to_string(start);
        return t[(n - 1) % len] - '0';
    }
};
// @lc code=end

