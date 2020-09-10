/*
 * @lc app=leetcode id=386 lang=cpp
 *
 * [386] Lexicographical Numbers
 *
 * https://leetcode.com/problems/lexicographical-numbers/description/
 *
 * algorithms
 * Medium (51.82%)
 * Likes:    603
 * Dislikes: 74
 * Total Accepted:    56K
 * Total Submissions: 107.8K
 * Testcase Example:  '13'
 *
 * Given an integer n, return 1 - n in lexicographical order.
 * 
 * For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].
 * 
 * Please optimize your algorithm to use less time and space. The input size
 * may be as large as 5,000,000.
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res(n);
        int cur = 1;
        
        for (int i=0; i<n; ++i) {
            res[i] = cur;
            if (cur*10 <= n) {
                cur *= 10;
            } 
            else {
                if (cur >= n) cur /= 10;
                cur += 1;
                
                while (cur%10 == 0) cur /= 10;
            }
        }
        return res;
    }
};
// @lc code=end

