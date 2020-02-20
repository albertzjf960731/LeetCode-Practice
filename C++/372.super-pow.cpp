/*
 * @lc app=leetcode id=372 lang=cpp
 *
 * [372] Super Pow
 *
 * https://leetcode.com/problems/super-pow/description/
 *
 * algorithms
 * Medium (36.15%)
 * Likes:    176
 * Dislikes: 673
 * Total Accepted:    32.2K
 * Total Submissions: 89.1K
 * Testcase Example:  '2\n[3]'
 *
 * Your task is to calculate a^b mod 1337 where a is a positive integer and b
 * is an extremely large positive integer given in the form of an array.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: a = 2, b = [3]
 * Output: 8
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: a = 2, b = [1,0]
 * Output: 1024
 * 
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    const int mode_ = 1337;
    int pow_mod(int a, int k) {
        a %= mode_;
        int ans = 1;
        for (int i=0; i<k; ++i)
            ans = (ans * a) % mode_;
        return ans;
    }
    int superPow(int a, vector<int>& b) {
        if (b.empty()) 
            return 1;
        int last_digit = b.back();
        b.pop_back();
        return pow_mod(superPow(a, b), 10) * pow_mod(a, last_digit) % mode_;
    }
};
// @lc code=end

