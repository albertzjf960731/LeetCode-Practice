/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int num = 0;
        int u=0, d=n-1, l=0, r=n-1;
        
        while (u<=d && l<=r) {
            for (int j=l; j<=r; j++)
                matrix[u][j] = ++num;            
            if(++u>d) 
                break;
            
            for (int i=u; i<=d; i++)
                matrix[i][r] = ++num;
            if(--r<l) 
                break;

            for (int j=r; j>=l; j--)
                matrix[d][j] = ++num;
            if(--d<u)
                break;
            
            for (int i=d; i>=u; i--)
                matrix[i][l] = ++num;
            if(l++>r)
                break;
        }
        return matrix;
    }
};
// @lc code=end

