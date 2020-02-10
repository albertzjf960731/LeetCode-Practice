/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 *
 * https://leetcode.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (48.34%)
 * Likes:    1394
 * Dislikes: 321
 * Total Accepted:    321.1K
 * Total Submissions: 663.9K
 * Testcase Example:  '19'
 *
 * Write an algorithm to determine if a number is "happy".
 * 
 * A happy number is a number defined by the following process: Starting with
 * any positive integer, replace the number by the sum of the squares of its
 * digits, and repeat the process until the number equals 1 (where it will
 * stay), or it loops endlessly in a cycle which does not include 1. Those
 * numbers for which this process ends in 1 are happy numbers.
 * 
 * Example: 
 * 
 * 
 * Input: 19
 * Output: true
 * Explanation: 
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 * 
 */
#include<math.h>
#include<unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> hash_set;
        
        while(n!=1) {
            int sum = 0;
            while(n != 0) {
                sum += pow(n%10,2);
                n = n/10;
            }
            n = sum;
            if (hash_set.count(n))
                return false;
            else 
                hash_set.insert(n);
        }
        return true;


        int slow = next(n);
        int fast = next(next(n));
        
        while(slow!=fast) {
            slow = next(slow);
            fast = next(next(fast));
        }
        
        return fast==1;
    }
   int next(int n) {
        int sum = 0;
        while(n != 0) {
            sum += pow(n % 10,2);
            n = n / 10;
        }
        return sum;
    }
};
// @lc code=end

