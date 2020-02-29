/*
 * @lc app=leetcode id=861 lang=cpp
 *
 * [861] Score After Flipping Matrix
 *
 * https://leetcode.com/problems/score-after-flipping-matrix/description/
 *
 * algorithms
 * Medium (71.41%)
 * Likes:    371
 * Dislikes: 97
 * Total Accepted:    17.8K
 * Total Submissions: 24.9K
 * Testcase Example:  '[[0,0,1,1],[1,0,1,0],[1,1,0,0]]'
 *
 * We have a two dimensional matrix A where each value is 0 or 1.
 * 
 * A move consists of choosing any row or column, and toggling each value in
 * that row or column: changing all 0s to 1s, and all 1s to 0s.
 * 
 * After making any number of moves, every row of this matrix is interpreted as
 * a binary number, and the score of the matrix is the sum of these numbers.
 * 
 * Return the highest possible score.
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
 * Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
 * Output: 39
 * Explanation:
 * Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
 * 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 20
 * 1 <= A[0].length <= 20
 * A[i][j] is 0 or 1.
 * 
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int rows = A.size(), cols = A[0].size();
        
        int ans = (1 << (cols-1)) * rows;
        for (int j=1; j<cols; j++) {
            int cnt = 0;
            for (int i=0; i<rows; i++) 
                cnt += A[i][j]==A[i][0];
            
            ans += max(cnt, rows-cnt) * (1 << (cols-1-j));
        }
        return ans;
    }
};
// @lc code=end

