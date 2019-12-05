/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty() || matrix[0].empty())
            return res;
        int rows=matrix.size(), cols=matrix[0].size();
        int u=0, d=rows-1, l=0, r=cols-1;
        
        while (u<=d && l<=r) {
            for (int j=l; j<=r; j++)
                res.push_back(matrix[u][j]);  
            if(++u>d) 
                break;
            
            for (int i=u; i<=d; i++)
                res.push_back(matrix[i][r]); 
            if(--r<l) 
                break;

            for (int j=r; j>=l; j--)
                res.push_back(matrix[d][j]);
            if(--d<u)
                break;
            
            for (int i=d; i>=u; i--)
                res.push_back(matrix[i][l]);
            if(l++>r)
                break;
        }
        return res;
    }
};
// @lc code=end

