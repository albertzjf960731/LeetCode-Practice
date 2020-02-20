/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 *
 * https://leetcode.com/problems/gray-code/description/
 *
 * algorithms
 * Medium (47.33%)
 * Likes:    502
 * Dislikes: 1372
 * Total Accepted:    149.2K
 * Total Submissions: 314.3K
 * Testcase Example:  '2'
 *
 * The gray code is a binary numeral system where two successive values differ
 * in only one bit.
 * 
 * Given a non-negative integer n representing the total number of bits in the
 * code, print the sequence of gray code. A gray code sequence must begin with
 * 0.
 * 
 * Example 1:
 * 
 * 
 * Input: 2
 * Output: [0,1,3,2]
 * Explanation:
 * 00 - 0
 * 01 - 1
 * 11 - 3
 * 10 - 2
 * 
 * For a given n, a gray code sequence may not be uniquely defined.
 * For example, [0,2,3,1] is also a valid gray code sequence.
 * 
 * 00 - 0
 * 10 - 2
 * 11 - 3
 * 01 - 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 0
 * Output: [0]
 * Explanation: We define the gray code sequence to begin with 0.
 * A gray code sequence of n has size = 2^n, which for n = 0 the size is 2^0 =
 * 1.
 * Therefore, for n = 0 the gray code sequence is [0].
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> grayCode(int n) {
        // vector<int> res(1<<n);
        // for (int i=0; i<(1<<n); i++) 
        //     res[i] = i^(i>>1);
        // return res;
        
        // bitset<32> bits;
        // vector<int> res;
        // DFS(bits, res, 0, n);
        // return res;
        
        vector<int> res{0};
        for (int i=0; i<n; i++) {
            int add = 1<<i;
            for (int j=res.size()-1; j>=0; j--)
                res.push_back(res[j]+add);
        }
        return res;
    }
    
    // void DFS(bitset<32>& bits, vector<int>& res, int i, int n) {
    //     if (i==n) {
    //         res.push_back(bits.to_ulong());
    //         return;
    //     }
    //     DFS(bits, res, k-1);
    //     bits.flip(k-1);
    //     DFS(bits, res, k-1);
    // }
};
// @lc code=end

